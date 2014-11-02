/////////////////////////////////////////////////////////////////////////////
//        ____        __  __  __     ___                                   //
//       / __ )____ _/ /_/ /_/ /__  /   |  ________  ____  ____ ______     //
//      / __  / __ `/ __/ __/ / _ \/ /| | / ___/ _ \/ __ \/ __ `/ ___/     //
//     / /_/ / /_/ / /_/ /_/ /  __/ ___ |/ /  /  __/ / / / /_/ (__  )      //
//    /_____/\__,_/\__/\__/_/\___/_/  |_/_/   \___/_/ /_/\__,_/____/       //
//         Developed by Natureknight for BattleArenas.no-ip.org            //
/////////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"

const uint32 ONE_CHARACTER_VIP = 4992700;

enum ForbiddenAreas
{
	AREA_VIP_MALL            = 1196,  // Utgarde Pinnacle
    AREA_VIP_ISLAND          = 2317,  // South Seas
	AREA_GM_ISLAND           = 876,   // GM Island
};

class map_security : public PlayerScript
{
	public:
		map_security() : PlayerScript("map_security") {}

		void OnUpdateZone(Player* pPlayer, uint32 newZone, uint32 newArea)
		{
			switch (pPlayer->GetAreaId())
			{
			    case AREA_VIP_MALL:
			    case AREA_VIP_ISLAND:
			    case AREA_GM_ISLAND:
				{
				    if (pPlayer->GetSession()->GetSecurity() >= 1 || pPlayer->HasItemCount(ONE_CHARACTER_VIP, 1))
				        return;

				    pPlayer->TeleportTo(560,  2168.909912f,  32.518398f,  41.658501f,  5.186590f); // Prison
				    pPlayer->GetSession()->SendAreaTriggerMessage("You don't have VIP access to reach this destination.");
				}
			break;
			}
		}
};

class gamemasters_security : public PlayerScript
{
	public:
		gamemasters_security() : PlayerScript("gamemasters_security") {}

		void OnLogin(Player* player)
		{
			// Cache deletion reminder to new players
			if (player->GetTotalPlayedTime() < 1)
				player->GetSession()->SendAreaTriggerMessage("Please delete your Cache folder from your WoW directory to see anything properly.");

			// Prevent GMs rank 2 and rank 3 to play as normal players
			if (player->GetSession()->GetSecurity() == 2 || player->GetSession()->GetSecurity() == 3)
			{
			    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; slot++)
					 player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

				player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 2586, true);
			    player->EquipNewItem(EQUIPMENT_SLOT_FEET, 11508, true);
			    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 12064, true);
			}
		}
};

void AddSC_Security_Scripts()
{
	new map_security();
	new gamemasters_security();
}