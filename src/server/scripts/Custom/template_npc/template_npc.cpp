////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"
#include "template_npc_discipline_priest.h"

class createItemSet_commandscript : public CommandScript
{
public:
    createItemSet_commandscript() : CommandScript("createItemSet_commandscript") { }

	static void SaveDisciplinePriestToDB(Player* dPriest)
	{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = dPriest->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (dPriest->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`) VALUES ('Priest', 'Discipline', '%u', %u, %u, %u, %u, %u, %u);"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT));
		        }
				else if (dPriest->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`) VALUES ('Priest', 'Discipline', '%u', %u, %u, %u, %u, %u, %u);"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT));
				}
			}
		}
	}

    ChatCommand* GetCommands() const
    {
		static ChatCommand createPriestItemSetTable[] =
        {
			{ "discipline",     SEC_OWNER,         false,          &HandleCreatePriestDisciplineItemSetCommand,   "", NULL },
			{ "shadow",         SEC_OWNER,         false,          &HandleCreatePriestDisciplineItemSetCommand,       "", NULL },
			{ "holy",           SEC_OWNER,         false,          &HandleCreatePriestDisciplineItemSetCommand,   "", NULL },
			{ NULL,             0,                         false,          NULL,                                          "", NULL }
		};
        static ChatCommand createItemSetCommandTable[] =
        {
			{ "priest",            SEC_OWNER,          true,            NULL,         "", createPriestItemSetTable },
            { NULL,                0,                          false,           NULL,         "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "create",         SEC_OWNER,         true, NULL,                 "", createItemSetCommandTable },
            { NULL,             0,                         false, NULL,                "", NULL }
        };
        return commandTable;
    }

	    // DISCIPLINE PRIEST
		static bool HandleCreatePriestDisciplineItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PRIEST)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a priest!");
			return false;
		}

		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Discipline Priest template set (human)!");
		    SaveDisciplinePriestToDB(player);
			return false;
		}
		CharacterDatabase.PExecute("DELETE FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline';");
		player->GetSession()->SendAreaTriggerMessage("Successfuly created Discipline Priest template set!");
		SaveDisciplinePriestToDB(player);
		return true;
    }
};

class template_npc : public CreatureScript
{
public:
	template_npc() : CreatureScript("template_npc") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		switch (player->getClass())
		{
		case CLASS_PRIEST:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Discipline Spec", GOSSIP_SENDER_MAIN, 0);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Holy Spec", GOSSIP_SENDER_MAIN, 1);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Shadow Spec", GOSSIP_SENDER_MAIN, 2);
			}
			break;
		case CLASS_PALADIN:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Holy Spec", GOSSIP_SENDER_MAIN, 3);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Protection Spec", GOSSIP_SENDER_MAIN, 4);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Retribution Spec", GOSSIP_SENDER_MAIN, 5);
			}
			break;
		case CLASS_WARRIOR:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Fury Spec", GOSSIP_SENDER_MAIN, 6);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Arms Spec", GOSSIP_SENDER_MAIN, 7);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Protection Spec", GOSSIP_SENDER_MAIN, 8);
			}
			break;
		case CLASS_MAGE:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Arcane Spec", GOSSIP_SENDER_MAIN, 9);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Fire Spec", GOSSIP_SENDER_MAIN, 10);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Frost Spec", GOSSIP_SENDER_MAIN, 11);
			}
			break;
		case CLASS_WARLOCK:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Affliction Spec", GOSSIP_SENDER_MAIN, 12);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Demonology Spec", GOSSIP_SENDER_MAIN, 13);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Destruction Spec", GOSSIP_SENDER_MAIN, 14);
			}
			break;
		case CLASS_SHAMAN:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Elemental Spec", GOSSIP_SENDER_MAIN, 15);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Enhancement Spec", GOSSIP_SENDER_MAIN, 16);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Restoration Spec", GOSSIP_SENDER_MAIN, 17);
			}
			break;
		case CLASS_DRUID:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Ballance Spec", GOSSIP_SENDER_MAIN, 18);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Feral Spec", GOSSIP_SENDER_MAIN, 19);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Restoration Spec", GOSSIP_SENDER_MAIN, 20);
			}
			break;
		case CLASS_HUNTER:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Markmanship Spec", GOSSIP_SENDER_MAIN, 21);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Beastmastery Spec", GOSSIP_SENDER_MAIN, 22);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Survival Spec", GOSSIP_SENDER_MAIN, 23);
			}
			break;
		case CLASS_ROGUE:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Assasination Spec", GOSSIP_SENDER_MAIN, 24);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Combat Spec", GOSSIP_SENDER_MAIN, 25);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Subtlety Spec", GOSSIP_SENDER_MAIN, 26);
			}
			break;
		case CLASS_DEATH_KNIGHT:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Blood Spec", GOSSIP_SENDER_MAIN, 27);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Frost Spec", GOSSIP_SENDER_MAIN, 28);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Use Unholy Spec", GOSSIP_SENDER_MAIN, 29);
			}
			break;
		}
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
	{
		if (!player || !creature)
			return true;

		player->PlayerTalkClass->ClearMenus();

		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			if (Item* haveItemEquipped = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
			{
				if (haveItemEquipped)
				{
					player->GetSession()->SendAreaTriggerMessage("You need to remove all your equipped items in order to use this feature!");
		            player->CLOSE_GOSSIP_MENU();
		            return true;
				}
		    }
		}

		switch (uiAction)
        {
		case 0: // Use Discipline Spec
			{
				EquipDisciplinePriestSet(player);
				player->CLOSE_GOSSIP_MENU();
			    return true;
			}
			break;

		case 1: // Use Shadow Spec
			{
				player->GetSession()->SendAreaTriggerMessage("Coming Soon!");
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		case 2: // Use Holy Spec
			{
				player->GetSession()->SendAreaTriggerMessage("Coming Soon!");
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;
		}
		OnGossipHello(player, creature);
		return true;
	}
};

void AddSC_template_npc()
{
	new template_npc();
	new createItemSet_commandscript();
}