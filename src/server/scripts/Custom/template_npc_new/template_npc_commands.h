/////////////////////////////////////////////////////////////////////////////
//        ____        __  __  __     ___                                   //
//       / __ )____ _/ /_/ /_/ /__  /   |  ________  ____  ____ ______     //
//      / __  / __ `/ __/ __/ / _ \/ /| | / ___/ _ \/ __ \/ __ `/ ___/     //
//     / /_/ / /_/ / /_/ /_/ /  __/ ___ |/ /  /  __/ / / / /_/ (__  )      //
//    /_____/\__,_/\__/\__/_/\___/_/  |_/_/   \___/_/ /_/\__,_/____/       //
//         Developed by Natureknight for BattleArenas.no-ip.org            //
/////////////////////////////////////////////////////////////////////////////

#ifndef SAVE_FUNCTIONS_H
#define SAVE_FUNCTIONS_H

static void SaveDisciplinePriestToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Discipline', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Discipline', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Discipline', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));

				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '%u' ORDER BY spell ASC;", player->GetGUID(), player->GetActiveSpec());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Priest', 'Discipline', '%u');", spell);
			}
			while (result->NextRow());
		}
}
	
static void SaveShadowPriestToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Shadow', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Shadow', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Shadow', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Priest', 'Shadow', '%u');", spell);
			}
			while (result->NextRow());
		}
}
	
static void SaveHolyPriestToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Holy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Holy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Priest', 'Holy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Priest', 'Holy', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveHolyPaladinToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Holy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Holy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Holy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Paladin', 'Holy', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveProtectionPaladinToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Protection', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Protection', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Protection', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Paladin', 'Protection', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveRetributionPaladinToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Retribution', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Retribution', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Paladin', 'Retribution', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Paladin', 'Retribution', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveArmsWarriorToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Arms', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Arms', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Arms', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Warrior', 'Arms', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveFuryWarriorToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Fury', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Fury', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Fury', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Warrior', 'Fury', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveProtectionWarriorToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Protection', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Protection', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warrior', 'Protection', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Warrior', 'Protection', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveArcaneMageToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Arcane', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Arcane', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Arcane', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Mage', 'Arcane', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveFireMageToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Fire', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Fire', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Fire', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Mage', 'Fire', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveFrostMageToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Frost', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Frost', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Mage', 'Frost', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Mage', 'Frost', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveAfflictionWarlockToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Affliction', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Affliction', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Affliction', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Warlock', 'Affliction', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveDemonologyWarlockToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Demonology', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Demonology', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Demonology', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Warlock', 'Demonology', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveDestructionWarlockToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Destruction', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Destruction', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Warlock', 'Destruction', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Warlock', 'Destruction', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveElementalShamanToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Elemental', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Elemental', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Elemental', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Shaman', 'Elemental', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveEnhancementShamanToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Enhancement', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Enhancement', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Enhancement', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Shaman', 'Enhancement', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveRestorationShamanToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Restoration', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Restoration', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Shaman', 'Restoration', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Shaman', 'Restoration', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveBallanceDruidToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Ballance', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Ballance', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Ballance', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Druid', 'Ballance', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveFeralDruidToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Feral', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Feral', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Feral', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Druid', 'Feral', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveRestorationDruidToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Restoration', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Restoration', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Druid', 'Restoration', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Druid', 'Restoration', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveMarksmanshipHunterToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Marksmanship', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Marksmanship', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Marksmanship', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Hunter', 'Marksmanship', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveBeastmasteryHunterToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Beastmastery', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Beastmastery', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Beastmastery', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Hunter', 'Beastmastery', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveSurvivalHunterToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Survival', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Survival', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Hunter', 'Survival', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Hunter', 'Survival', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveAssassinationRogueToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Assassination', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Assassination', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Assassination', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Rogue', 'Assassination', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveCombatRogueToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Combat', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Combat', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Combat', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Rogue', 'Combat', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveSubtletyRogueToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Subtlety', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Subtlety', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('Rogue', 'Subtlety', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('Rogue', 'Subtlety', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveBloodDeathKnightToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Blood', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Blood', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Blood', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('DeathKnight', 'Blood', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveFrostDeathKnightToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Frost', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Frost', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Frost', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('DeathKnight', 'Frost', '%u');", spell);
			}
			while (result->NextRow());
		}
}

static void SaveUnholyDeathKnightToDB(Player* player)
{
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
		{
			Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
			if (equippedItem)
			{
		        if (player->getRace() == RACE_HUMAN)
		        {
	                CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Unholy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
			            equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
		        }
				else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
				{
	                CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Unholy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
				else if (player->GetTeam() == HORDE)
				{
					CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('DeathKnight', 'Unholy', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
			            , equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
		                equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
				}
			}
		}
		QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' AND spec = '0' ORDER BY spell ASC;", player->GetGUID());

	    if (!result)
	    { 
		    player->GetSession()->SendAreaTriggerMessage("Something went wrong!");
		    return;
	    }
		else
		{
			do
			{
				Field* fields = result->Fetch(); 
	            uint32 spell = fields[0].GetUInt32();

				CharacterDatabase.PQuery("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) VALUES ('DeathKnight', 'Unholy', '%u');", spell);
			}
			while (result->NextRow());
		}
}

#endif