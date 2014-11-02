////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#ifndef TALENT_FUNCTIONS_H
#define TALENT_FUNCTIONS_H

static void ApplyBonus(Player* player, Item* item, EnchantmentSlot slot, uint32 bonusEntry)
{
	if (!item)
    {
        player->GetSession()->SendNotification("You must first equip the item you are trying to enchant in order to enchant it!");
        return;
    }
	
    if (!bonusEntry || bonusEntry == 0)
        return;
  
	player->ApplyEnchantment(item, slot, false);
    item->SetEnchantment(slot, bonusEntry, 0, 0);
    player->ApplyEnchantment(item, slot, true);
}

static void SetDisciplinePriestTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Priest' AND playerSpec = 'Discipline' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetHolyPriestTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Priest' AND playerSpec = 'Holy' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetShadowPriestTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Priest' AND playerSpec = 'Shadow' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetHolyPaladinTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Paladin' AND playerSpec = 'Holy' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetProtectionPaladinTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Paladin' AND playerSpec = 'Protection' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetRetributionPaladinTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetFuryWarriorTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Warrior' AND playerSpec = 'Fury' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetArmsWarriorTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Warrior' AND playerSpec = 'Arms' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetProtectionWarriorTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Warrior' AND playerSpec = 'Protection' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetArcaneMageTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Mage' AND playerSpec = 'Arcane' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetFireMageTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Mage' AND playerSpec = 'Fire' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetFrostMageTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Mage' AND playerSpec = 'Frost' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetAfflictionWarlockTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetDemonologyWarlockTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetDestructionWarlockTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetElementalShamanTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetEnhancementShamanTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetRestorationShamanTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetBallanceDruidTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Druid' AND playerSpec = 'Ballance' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetFeralDruidTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Druid' AND playerSpec = 'Feral' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetRestorationDruidTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Druid' AND playerSpec = 'Restoration' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetMarksmanshipHunterTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetBeastmasteryHunterTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetSurvivalHunterTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Hunter' AND playerSpec = 'Survival' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetAssassinationRogueTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetCombatRogueTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Rogue' AND playerSpec = 'Combat' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetSubtletyRogueTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetBloodDeathKnightTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetFrostDeathKnightTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

static void SetUnholyDeathKnightTalents(Player* player)
{
	if (!player)
		return;

	QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy' ORDER BY talentId ASC;");

	if (!select)
	{ 
		player->GetSession()->SendAreaTriggerMessage("No records for talents yet!");
		return;
	}
    else
	{
		do
		{
			Field* fields = select->Fetch(); 
	        uint32 talentId = fields[0].GetUInt32(); 

		    player->learnSpell(talentId, false);
			player->AddTalent(talentId, player->GetActiveSpec(), true);
			player->SetFreeTalentPoints(0);
		    player->SendTalentsInfoData(false);
		}
		while (select->NextRow());
	}
}

#endif