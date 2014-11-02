////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#ifndef DISCIPLINE_PRIEST_H
#define DISCIPLINE_PRIEST_H

void ApplyBonus(Player* player, Item* item, EnchantmentSlot slot, uint32 bonusEntry)
{
	if (!item)
    {
        player->GetSession()->SendNotification("You must first equip the item you are trying to enchant in order to enchant it!");
        return;
    }
	
    if (!bonusEntry)
    {
        player->GetSession()->SendNotification("Something went wrong in the code. It has been logged for developers and will be looked into, sorry for the inconvenience.");
        return;
    }
  
	player->ApplyEnchantment(item, slot, false);
    item->SetEnchantment(slot, bonusEntry, 0, 0);
    player->ApplyEnchantment(item, slot, true);
}

void EquipDisciplinePriestSet(Player* player)
{
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '0';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(0, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '0';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(0, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 0), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '1';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(1, itemEntry, true); 
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '1';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(1, itemEntry, true); 
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 1), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '2';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(2, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '2';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(2, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 2), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '3';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(3, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '3';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(3, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 3), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '4';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(4, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '4';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(4, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 4), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '5';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(5, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '5';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(5, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 5), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '6';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(6, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '6';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(6, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '7';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(7, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '7';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(7, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 7), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '8';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(8, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '8';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(8, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 8), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '9';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(9, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '9';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(9, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 9), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '10';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(10, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '10';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(10, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 10), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '11';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(11, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '11';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(11, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 11), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '12';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(12, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '12';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(12, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 12), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '13';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(13, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '13';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(13, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 13), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '14';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(14, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '14';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(14, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 14), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '15';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(15, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '15';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(15, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 15), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '16';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(16, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '16';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(16, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '17';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(17, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '17';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(17, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		if (player->getRace() == RACE_HUMAN)
		{
			QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '18';");
			if (!select) return;
		    Field* fields = select->Fetch();
			uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
			uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

			player->EquipNewItem(18, itemEntry, true); // head
			if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), SOCK_ENCHANTMENT_SLOT, socket1);
			if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), SOCK_ENCHANTMENT_SLOT_2, socket2);
			if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), SOCK_ENCHANTMENT_SLOT_3, socket3);
			if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		} 
		else if (player->getRace() != RACE_HUMAN)
		{
		    QueryResult select = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant FROM template_npc WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' AND pos = '18';");
			if (!select) return;
		    Field* fields = select->Fetch();
	        uint32 itemEntry = fields[0].GetUInt32(); uint32 enchant = fields[1].GetUInt32(); uint32 socket1 = fields[2].GetUInt32(); 
		    uint32 socket2 = fields[3].GetUInt32(); uint32 socket3 = fields[4].GetUInt32(); uint32 bonusEnchant = fields[5].GetUInt32();

		    player->EquipNewItem(18, itemEntry, true); // head
		    if (enchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), PERM_ENCHANTMENT_SLOT, enchant);
		    if (socket1 > 0)
		        ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), SOCK_ENCHANTMENT_SLOT, socket1);
	        if (socket2 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), SOCK_ENCHANTMENT_SLOT_2, socket2);
	        if (socket3 > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), SOCK_ENCHANTMENT_SLOT_3, socket3);
	        if (bonusEnchant > 0)
			    ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, 18), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
		}
		player->GetSession()->SendAreaTriggerMessage("You've successfuly equipped your template set (human)!");
}

#endif