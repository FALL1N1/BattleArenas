////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

// http://pastebin.com/pif71YNV - MOJE DA E POLEZNO

#include "ScriptMgr.h"
#include "ArenaTeamMgr.h"
#include "Common.h"
#include "DisableMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "ArenaTeam.h"
#include "Language.h"
#include "solo_queue_npc.h"

class solo_queue_npc : public CreatureScript
{
public:
	solo_queue_npc() : CreatureScript("solo_queue_npc") { }

	bool JoinQueueArena(Player* player, Creature* me, bool isRated)
	{
		if (!player || !me)
			return false;

		uint64 guid = player->GetGUID();
		uint8 arenatype = ARENA_TYPE_SOLO_QUEUE;
		uint32 arenaRating = 0;
		uint32 matchmakerRating = 0;

		// ignore if we already in BG or BG queue
		if (player->InBattleground())
			return false;

		// check existance
		Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
		if (!bg)
		{
			sLog->outError("Battleground: template bg (all arenas) not found");
			return false;
		}

		if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, NULL))
		{
			ChatHandler(player->GetSession()).PSendSysMessage(LANG_ARENA_DISABLED);
			return false;
		}

		BattlegroundTypeId bgTypeId = bg->GetTypeID();
		BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, arenatype);
		PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
		if (!bracketEntry)
			return false;

		GroupJoinBattlegroundResult err = ERR_GROUP_JOIN_BATTLEGROUND_FAIL;

		// check if already in queue
        if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            //player is already in this queue
            return false;
        // check if has free queue slots
        if (!player->HasFreeBattlegroundQueueId())
            return false;

		uint32 ateamId = 0;

		BattlegroundQueue &bgQueue = sBattlegroundMgr->m_BattlegroundQueues[bgQueueTypeId];
		bg->SetRated(isRated);

		GroupQueueInfo* ginfo = bgQueue.AddGroup(player, NULL, bgTypeId, bracketEntry, arenatype, isRated, false, arenaRating, matchmakerRating, ateamId);
        uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPacket data;
        // send status packet (in queue)
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype, 0);
		player->GetSession()->SendPacket(&data);

		sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, arenatype, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());

		return true;
	}

	bool OnGossipHello(Player* player, Creature* me)
	{
		if (!player || !me)
			return true;

		if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_SOLO_QUEUE))
			player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Leave 3v3 Solo Queue Arena", GOSSIP_SENDER_MAIN, 1, "Are you sure?", 0, false);
		else
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Sign up for 3v3 Solo Queue", GOSSIP_SENDER_MAIN, 0);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Show my specialization", GOSSIP_SENDER_MAIN, 2);
		player->SEND_GOSSIP_MENU(60015, me->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* me, uint32 /*uiSender*/, uint32 uiAction)
	{
		if(!player || !me)
			return true;

		// Trinity Strings
		int32 SQ_ANNOUNCER_MELEE = 10000;
		int32 SQ_ANNOUNCER_CASTER = 9999;
		int32 SQ_ANNOUNCER_HEALER = 9998;

		player->PlayerTalkClass->ClearMenus();

		switch (uiAction)
        {
		case 0: // Join Queue Arena (unrated)
			{
				if (JoinQueueArena(player, me, false) == false)
				{
					ChatHandler(player->GetSession()).SendSysMessage("Something went wrong while join queue.");
					return false;
				}
				
				if (playerIsMelee(player))
					sWorld->SendWorldText(SQ_ANNOUNCER_MELEE, player->GetName());

				if (playerIsCaster(player))
					sWorld->SendWorldText(SQ_ANNOUNCER_CASTER, player->GetName());

				if (playerIsHealer(player))
					sWorld->SendWorldText(SQ_ANNOUNCER_HEALER, player->GetName());

				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		case 1: // Leave Queue
			{
				WorldPacket Data;
				Data << (uint8)0x1 << (uint8)0x0 << (uint32)BATTLEGROUND_AA << (uint16)0x0 << (uint8)0x0;
				player->GetSession()->HandleBattleFieldPortOpcode(Data);
				// POSSIBLE SOLUTION ????????????????:
				player->GetSession()->SendPacket(&Data);
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		case 2: // Show player type
			{
				if (playerIsMelee(player))
				    player->GetSession()->SendAreaTriggerMessage("Your character is: Melee.");
				else if (playerIsCaster(player))
				    player->GetSession()->SendAreaTriggerMessage("Your character is: Caster/Ranged.");
				else if (playerIsHealer(player))
				    player->GetSession()->SendAreaTriggerMessage("Your character is: Healer.");
				else 
					player->GetSession()->SendAreaTriggerMessage("You need to spend your talent points to describe your specialization.");
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;
		}
		OnGossipHello(player, me);
		return true;
	}
};

void AddSC_solo_queue_npc()
{
    new solo_queue_npc();
}