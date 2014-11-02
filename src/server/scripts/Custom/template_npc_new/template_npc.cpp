/////////////////////////////////////////////////////////////////////////////
//        ____        __  __  __     ___                                   //
//       / __ )____ _/ /_/ /_/ /__  /   |  ________  ____  ____ ______     //
//      / __  / __ `/ __/ __/ / _ \/ /| | / ___/ _ \/ __ \/ __ `/ ___/     //
//     / /_/ / /_/ / /_/ /_/ /  __/ ___ |/ /  /  __/ / / / /_/ (__  )      //
//    /_____/\__,_/\__/\__/_/\___/_/  |_/_/   \___/_/ /_/\__,_/____/       //
//         Developed by Natureknight for BattleArenas.no-ip.org            //
/////////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"
#include "template_npc.h"
#include "template_npc_commands.h"

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
		player->SEND_GOSSIP_MENU(60025, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
	{
		if (!player || !creature)
			return true;

		player->PlayerTalkClass->ClearMenus();

		// THIS PART IS USED ONLY ON TOURNAMENT REALM
		if (sWorld->getBoolConfig(REALM_IS_TOURNAMENT_ENABLED))	// Professions Reminder
			creature->MonsterWhisper("Most of the templates incudes also professions, so don't forget to learn BS and JC from the Professions trainer, otherwise"
			"JC gems and bracer/gloves additional sockets won't work.", player->GetGUID());

		// Dont let players to use Template NPC with any items equipped
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

		// Dont let players to use Template NPC after spending some talent points
		if (player->GetFreeTalentPoints() < 71)
		{
			player->GetSession()->SendAreaTriggerMessage("You have already spent some talent points. You need to reset your talents first!");
		    player->CLOSE_GOSSIP_MENU();
		    return true;
	    }

		switch (uiAction)
        {
		case 0: // Use Discipline Priest Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
							continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
							continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
					    player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
							continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
					    player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetDisciplinePriestTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 1: // Use Holy Priest Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Holy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Priest' AND playerSpec = 'Holy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Priest' AND playerSpec = 'Holy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetHolyPriestTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 2: // Use Shadow Priest Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Shadow' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Priest' AND playerSpec = 'Shadow' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Priest' AND playerSpec = 'Shadow' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetShadowPriestTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 3: // Use Holy Paladin Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Paladin' AND playerSpec = 'Holy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Paladin' AND playerSpec = 'Holy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Paladin' AND playerSpec = 'Holy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetHolyPaladinTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 4: // Use Protection Paladin Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Paladin' AND playerSpec = 'Protection' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Paladin' AND playerSpec = 'Protection' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Paladin' AND playerSpec = 'Protection' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetProtectionPaladinTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 5: // Use Retribution Paladin Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetRetributionPaladinTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 6: // Use Fury Warrior Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Warrior' AND playerSpec = 'Fury' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Warrior' AND playerSpec = 'Fury' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Warrior' AND playerSpec = 'Fury' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetFuryWarriorTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 7: // Use Arms Warrior Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Warrior' AND playerSpec = 'Arms' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Warrior' AND playerSpec = 'Arms' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Warrior' AND playerSpec = 'Arms' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetArmsWarriorTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 8: // Use Protection Warrior Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Warrior' AND playerSpec = 'Protection' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Warrior' AND playerSpec = 'Protection' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Warrior' AND playerSpec = 'Protection' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetProtectionWarriorTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 9: // Use Arcane Mage Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Mage' AND playerSpec = 'Arcane' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Mage' AND playerSpec = 'Arcane' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Mage' AND playerSpec = 'Arcane' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetArcaneMageTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 10: // Use Fire Mage Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Mage' AND playerSpec = 'Fire' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Mage' AND playerSpec = 'Fire' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Mage' AND playerSpec = 'Fire' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetFireMageTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 11: // Use Frost Mage Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Mage' AND playerSpec = 'Frost' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Mage' AND playerSpec = 'Frost' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Mage' AND playerSpec = 'Frost' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetFrostMageTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 12: // Use Affliction Warlock Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetAfflictionWarlockTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 13: // Use Demonology Warlock Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetDemonologyWarlockTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 14: // Use Destruction Warlock Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetDestructionWarlockTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 15: // Use Elemental Shaman Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetElementalShamanTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 16: // Use Enhancement Shaman Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetEnhancementShamanTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 17: // Use Restoration Shaman Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetRestorationShamanTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 18: // Use Ballance Druid Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Druid' AND playerSpec = 'Ballance' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Druid' AND playerSpec = 'Ballance' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Druid' AND playerSpec = 'Ballance' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetBallanceDruidTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 19: // Use Feral Druid Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Druid' AND playerSpec = 'Feral' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Druid' AND playerSpec = 'Feral' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Druid' AND playerSpec = 'Feral' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetFeralDruidTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 20: // Use Restoration Druid Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Druid' AND playerSpec = 'Restoration' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Druid' AND playerSpec = 'Restoration' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Druid' AND playerSpec = 'Restoration' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetRestorationDruidTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 21: // Use Marksmanship Hunter Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetMarksmanshipHunterTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 22: // Use Beastmastery Hunter Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetBeastmasteryHunterTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

			case 23: // Use Survival Hunter Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Hunter' AND playerSpec = 'Survival' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Hunter' AND playerSpec = 'Survival' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Hunter' AND playerSpec = 'Survival' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetSurvivalHunterTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 24: // Use Assassination Rogue Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetAssassinationRogueTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 25: // Use Combat Rogue Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Rogue' AND playerSpec = 'Combat' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Rogue' AND playerSpec = 'Combat' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Rogue' AND playerSpec = 'Combat' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetCombatRogueTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 26: // Use Subtlety Rogue Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetSubtletyRogueTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 27: // Use Blood DK Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetBloodDeathKnightTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 28: // Use Frost DK Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetFrostDeathKnightTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;

		case 29: // Use Unholy DK Spec
			{
				if (player->getRace() == RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_human WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_alliance WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				else if (player->GetTeam() == HORDE)
				{
					for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
					{
					    QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
						    "FROM template_npc_horde WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy' AND pos = '%u'", equipmentSlot);
						if (!result)
				        {
					        player->GetSession()->SendAreaTriggerMessage("No records yet!");
					        continue;
				        }

						Field* fields = result->Fetch(); uint32 itemEntry = fields[0].GetUInt32(); 
						uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); uint32 socket2 = fields[3].GetUInt32(); 
						uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32(); uint32 prismaticEnchant = fields[6].GetUInt32();

						// Equip Gear
						player->EquipNewItem(equipmentSlot, itemEntry, true);
						// Apply Enchants and Gems
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
		                ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
			            ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
						ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
					}
				}
				SetUnholyDeathKnightTalents(player);
				player->GetSession()->SendAreaTriggerMessage("Successfuly equipped your gear!");
				player->CLOSE_GOSSIP_MENU();
			}
			break;
		}

		// Learn Plate/Mail or Mail
		switch (player->getClass())
		{
		case CLASS_WARRIOR:
		case CLASS_PALADIN:
		case CLASS_DEATH_KNIGHT:
			player->learnSpell(750, true); // Plate/Mail
			break;
		case CLASS_SHAMAN:
		case CLASS_HUNTER:
			player->learnSpell(8737, true); // Mail (Only)
			break;
		}
		return true;
	}
};

void AddSC_template_npc()
{
	new template_npc();
}