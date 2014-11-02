/////////////////////////////////////////////////////////////////////////////
//        ____        __  __  __     ___                                   //
//       / __ )____ _/ /_/ /_/ /__  /   |  ________  ____  ____ ______     //
//      / __  / __ `/ __/ __/ / _ \/ /| | / ___/ _ \/ __ \/ __ `/ ___/     //
//     / /_/ / /_/ / /_/ /_/ /  __/ ___ |/ /  /  __/ / / / /_/ (__  )      //
//    /_____/\__,_/\__/\__/_/\___/_/  |_/_/   \___/_/ /_/\__,_/____/       //
//         Developed by Natureknight for BattleArenas.no-ip.org            //
/////////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"
#include "template_npc_commands.h"

class createItemSet_commandscript : public CommandScript
{
public:
    createItemSet_commandscript() : CommandScript("createItemSet_commandscript") { }

    ChatCommand* GetCommands() const
    {
		static ChatCommand createDeathKnightItemSetTable[] =
        {
		    { "Blood",               SEC_OWNER,         false,          &HandleCreateDeathKnightBloodItemSetCommand,            "", NULL },
			{ "frost",         SEC_OWNER,         false,          &HandleCreateDeathKnightFrostItemSetCommand,      "", NULL },
			{ "unholy",        SEC_OWNER,         false,          &HandleCreateDeathKnightUnholyItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		static ChatCommand createRogueItemSetTable[] =
        {
		    { "assassination",               SEC_OWNER,         false,          &HandleCreateRogueAssassinationItemSetCommand,            "", NULL },
			{ "combat",         SEC_OWNER,         false,          &HandleCreateRogueCombatItemSetCommand,      "", NULL },
			{ "subtlety",        SEC_OWNER,         false,          &HandleCreateRogueSubtletyItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		static ChatCommand createHunterItemSetTable[] =
        {
		    { "marksmanship",               SEC_OWNER,         false,          &HandleCreateHunterMarksmanshipItemSetCommand,            "", NULL },
			{ "beastmastery",         SEC_OWNER,         false,          &HandleCreateHunterBeastmasteryItemSetCommand,      "", NULL },
			{ "survival",        SEC_OWNER,         false,          &HandleCreateHunterSurvivalItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		static ChatCommand createDruidItemSetTable[] =
        {
		    { "ballance",               SEC_OWNER,         false,          &HandleCreateDruidBallanceItemSetCommand,            "", NULL },
			{ "feral",         SEC_OWNER,         false,          &HandleCreateDruidFeralItemSetCommand,      "", NULL },
			{ "restoration",        SEC_OWNER,         false,          &HandleCreateDruidRestorationItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		static ChatCommand createShamanItemSetTable[] =
        {
		    { "elemetal",               SEC_OWNER,         false,          &HandleCreateShamanElementalItemSetCommand,            "", NULL },
			{ "enhancement",         SEC_OWNER,         false,          &HandleCreateShamanEnhancementItemSetCommand,      "", NULL },
			{ "restoration",        SEC_OWNER,         false,          &HandleCreateShamanRestorationItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		static ChatCommand createWarlockItemSetTable[] =
        {
		    { "affliction",               SEC_OWNER,         false,          &HandleCreateWarlockAfflictionItemSetCommand,            "", NULL },
			{ "Demonology",         SEC_OWNER,         false,          &HandleCreateWarlockDemonologyItemSetCommand,      "", NULL },
			{ "destruction",        SEC_OWNER,         false,          &HandleCreateWarlockDestructionItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		static ChatCommand createMageItemSetTable[] =
        {
		    { "Frost",               SEC_OWNER,         false,          &HandleCreateMageFrostItemSetCommand,            "", NULL },
			{ "fire",         SEC_OWNER,         false,          &HandleCreateMageFireItemSetCommand,      "", NULL },
			{ "arcane",        SEC_OWNER,         false,          &HandleCreateMageArcaneItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		static ChatCommand createWarriorItemSetTable[] =
        {
		    { "arms",               SEC_OWNER,         false,          &HandleCreateWarriorArmsItemSetCommand,            "", NULL },
			{ "fury",         SEC_OWNER,         false,          &HandleCreateWarriorFuryItemSetCommand,      "", NULL },
			{ "protection",        SEC_OWNER,         false,          &HandleCreateWarriorProtectionItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
	    static ChatCommand createPaladinItemSetTable[] =
        {
		    { "Holy",               SEC_OWNER,         false,          &HandleCreatePaladinHolyItemSetCommand,            "", NULL },
			{ "Protection",         SEC_OWNER,         false,          &HandleCreatePaladinProtectionItemSetCommand,      "", NULL },
			{ "Retribution",        SEC_OWNER,         false,          &HandleCreatePaladinRetributionItemSetCommand,     "", NULL },
			{ NULL,                 0,                 false,          NULL,                                              "", NULL }
		};
		
		static ChatCommand createPriestItemSetTable[] =
        {
			{ "discipline",     SEC_OWNER,         false,          &HandleCreatePriestDisciplineItemSetCommand,   "", NULL },
			{ "shadow",         SEC_OWNER,         false,          &HandleCreatePriestShadowItemSetCommand,       "", NULL },
			{ "holy",           SEC_OWNER,         false,          &HandleCreatePriestHolyItemSetCommand,         "", NULL },
			{ NULL,             0,                         false,          NULL,                                          "", NULL }
		};
        static ChatCommand createItemSetCommandTable[] =
        {
			{ "priest",            SEC_OWNER,          true,            NULL,         "", createPriestItemSetTable },
			{ "paladin",           SEC_OWNER,          true,            NULL,         "", createPaladinItemSetTable },
			{ "warrior",            SEC_OWNER,          true,            NULL,         "", createWarriorItemSetTable },
			{ "mage",            SEC_OWNER,          true,            NULL,         "", createMageItemSetTable },
			{ "warlock",            SEC_OWNER,          true,            NULL,         "", createWarlockItemSetTable },
			{ "shaman",            SEC_OWNER,          true,            NULL,         "", createShamanItemSetTable },
			{ "druid",            SEC_OWNER,          true,            NULL,         "", createDruidItemSetTable },
			{ "hunter",            SEC_OWNER,          true,            NULL,         "", createHunterItemSetTable },
			{ "rogue",            SEC_OWNER,          true,            NULL,         "", createRogueItemSetTable },
			{ "deathknight",            SEC_OWNER,          true,            NULL,         "", createDeathKnightItemSetTable },
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

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Priest' AND playerSpec = 'Discipline';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Discipline';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Discipline Priest template set (human)!");
		    SaveDisciplinePriestToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Priest' AND playerSpec = 'Discipline';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Discipline Priest template set!");
		    SaveDisciplinePriestToDB(player);
			return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Priest' AND playerSpec = 'Discipline';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Discipline Priest template set!");
		    SaveDisciplinePriestToDB(player);
			return false;
		}
		return true;
    }
	
	// SHADOW PRIEST
		static bool HandleCreatePriestShadowItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PRIEST)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a priest!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Priest' AND playerSpec = 'Shadow';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Shadow';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Discipline Priest template set (human)!");
		    SaveShadowPriestToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Priest' AND playerSpec = 'Shadow';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Shadow Priest template set!");
		    SaveShadowPriestToDB(player);
			return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Priest' AND playerSpec = 'Shadow';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Shadow Priest template set!");
		    SaveShadowPriestToDB(player);
			return false;
		}
		return true;
    }
	
	// HOLY PRIEST
		static bool HandleCreatePriestHolyItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PRIEST)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a priest!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Priest' AND playerSpec = 'Holy';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Priest' AND playerSpec = 'Holy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Holy Priest template set (human)!");
		    SaveHolyPriestToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Priest' AND playerSpec = 'Holy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Holy Priest template set!");
		    SaveHolyPriestToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Priest' AND playerSpec = 'Holy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Holy Priest template set!");
		    SaveHolyPriestToDB(player);
		    return false;
		}
		return true;
    }
	
	// HOLY PALADIN
		static bool HandleCreatePaladinHolyItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PALADIN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Paladin' AND playerSpec = 'Holy';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Paladin' AND playerSpec = 'Holy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Holy Paladin template set (human)!");
		    SaveHolyPaladinToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Paladin' AND playerSpec = 'Holy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Holy Paladin template set!");
		    SaveHolyPaladinToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Paladin' AND playerSpec = 'Holy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Holy Paladin template set!");
		    SaveHolyPaladinToDB(player);
		    return false;
		}
		return true;
    }
	
	// PROTECTION PALADIN
		static bool HandleCreatePaladinProtectionItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PALADIN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Paladin' AND playerSpec = 'Protection';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Paladin' AND playerSpec = 'Protection';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Protection Paladin template set (human)!");
		    SaveProtectionPaladinToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Paladin' AND playerSpec = 'Protection';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Protection Paladin template set!");
		    SaveProtectionPaladinToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Paladin' AND playerSpec = 'Protection';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Protection Paladin template set!");
		    SaveProtectionPaladinToDB(player);
		    return false;
		}
		return true;
    }
	
	    // RETRIBUTION PALADIN
		static bool HandleCreatePaladinRetributionItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PALADIN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Retribution Paladin template set (human)!");
		    SaveRetributionPaladinToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Retribution Paladin template set!");
		    SaveRetributionPaladinToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Paladin' AND playerSpec = 'Retribution';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Retribution Paladin template set!");
		    SaveRetributionPaladinToDB(player);
		    return false;
		}
		return true;
    }

		// FURY WARRIOR
		static bool HandleCreateWarriorFuryItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARRIOR)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Warrior' AND playerSpec = 'Fury';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Warrior' AND playerSpec = 'Fury';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Fury Warrior template set (human)!");
		    SaveFuryWarriorToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Warrior' AND playerSpec = 'Fury';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Fury Warrior template set!");
		    SaveFuryWarriorToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Warrior' AND playerSpec = 'Fury';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Fury Warrior template set!");
		    SaveFuryWarriorToDB(player);
		    return false;
		}
		return true;
    }

		// ARMS WARRIOR
		static bool HandleCreateWarriorArmsItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARRIOR)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Warrior' AND playerSpec = 'Arms';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Warrior' AND playerSpec = 'Arms';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Arms Warrior template set (human)!");
		    SaveArmsWarriorToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Warrior' AND playerSpec = 'Arms';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Arms Warrior template set!");
		    SaveArmsWarriorToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Warrior' AND playerSpec = 'Arms';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Arms Warrior template set!");
		    SaveArmsWarriorToDB(player);
		    return false;
		}
		return true;
    }

		// PROTECTION WARRIOR
		static bool HandleCreateWarriorProtectionItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARRIOR)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Warrior' AND playerSpec = 'Protection';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Warrior' AND playerSpec = 'Protection';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Protection Warrior template set (human)!");
		    SaveProtectionWarriorToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Warrior' AND playerSpec = 'Protection';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Protection Warrior template set!");
		    SaveProtectionWarriorToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Warrior' AND playerSpec = 'Protection';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Protection Warrior template set!");
		    SaveProtectionWarriorToDB(player);
		    return false;
		}
		return true;
    }

		// ARCANE MAGE
		static bool HandleCreateMageArcaneItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_MAGE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Mage' AND playerSpec = 'Arcane';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Mage' AND playerSpec = 'Arcane';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Arcane Mage template set (human)!");
		    SaveArcaneMageToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Mage' AND playerSpec = 'Arcane';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Arcane Mage template set!");
		    SaveArcaneMageToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Mage' AND playerSpec = 'Arcane';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Arcane Mage template set!");
		    SaveArcaneMageToDB(player);
		    return false;
		}
		return true;
    }

		// FIRE MAGE
		static bool HandleCreateMageFireItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_MAGE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Mage' AND playerSpec = 'Fire';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Mage' AND playerSpec = 'Fire';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Fire Mage template set (human)!");
		    SaveFireMageToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Mage' AND playerSpec = 'Fire';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Fire Mage template set!");
		    SaveFireMageToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Mage' AND playerSpec = 'Fire';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Fire Mage template set!");
		    SaveFireMageToDB(player);
		    return false;
		}
		return true;
    }

		// FROST MAGE
		static bool HandleCreateMageFrostItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_MAGE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Mage' AND playerSpec = 'Frost';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Mage' AND playerSpec = 'Frost';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Frost Mage template set (human)!");
		    SaveFrostMageToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Mage' AND playerSpec = 'Frost';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Frost Mage template set!");
		    SaveFrostMageToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Mage' AND playerSpec = 'Frost';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Frost Mage template set!");
		    SaveFrostMageToDB(player);
		    return false;
		}
		return true;
    }

		// AFFLICTION WARLOCK
		static bool HandleCreateWarlockAfflictionItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARLOCK)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Affliction Warlock template set (human)!");
		    SaveAfflictionWarlockToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Affliction Warlock template set!");
		    SaveAfflictionWarlockToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Warlock' AND playerSpec = 'Affliction';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Affliction Warlock template set!");
		    SaveAfflictionWarlockToDB(player);
		    return false;
		}
		return true;
    }

		// DEMONOLOGY WARLOCK
		static bool HandleCreateWarlockDemonologyItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARLOCK)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Demonology Warlock template set (human)!");
		    SaveDemonologyWarlockToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Demonology Warlock template set!");
		    SaveDemonologyWarlockToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Warlock' AND playerSpec = 'Demonology';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Demonology Warlock template set!");
		    SaveDemonologyWarlockToDB(player);
		    return false;
		}
		return true;
    }

		// DESTRUCTION WARLOCK
		static bool HandleCreateWarlockDestructionItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARLOCK)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Destruction Warlock template set (human)!");
		    SaveDestructionWarlockToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Destruction Warlock template set!");
		    SaveDestructionWarlockToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Warlock' AND playerSpec = 'Destruction';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Destruction Warlock template set!");
		    SaveDestructionWarlockToDB(player);
		    return false;
		}
		return true;
    }

		// ELEMENTAL SHAMAN
		static bool HandleCreateShamanElementalItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_SHAMAN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Elemental Shaman template set (human)!");
		    SaveElementalShamanToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Elemental Shaman template set!");
		    SaveElementalShamanToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Shaman' AND playerSpec = 'Elemental';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Elemental Shaman template set!");
		    SaveElementalShamanToDB(player);
		    return false;
		}
		return true;
    }

		// ENHANCEMENT SHAMAN
		static bool HandleCreateShamanEnhancementItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_SHAMAN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Enhancement Shaman template set (human)!");
		    SaveEnhancementShamanToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Enhancement Shaman template set!");
		    SaveEnhancementShamanToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Shaman' AND playerSpec = 'Enhancement';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Enhancement Shaman template set!");
		    SaveEnhancementShamanToDB(player);
		    return false;
		}
		return true;
    }

		// RESTORATION SHAMAN
		static bool HandleCreateShamanRestorationItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_SHAMAN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Restoration Shaman template set (human)!");
		    SaveRestorationShamanToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Restoration Shaman template set!");
		    SaveRestorationShamanToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Shaman' AND playerSpec = 'Restoration';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Restoration Shaman template set!");
		    SaveRestorationShamanToDB(player);
		    return false;
		}
		return true;
    }

		// BALLANCE DRUID
		static bool HandleCreateDruidBallanceItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DRUID)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Druid' AND playerSpec = 'Ballance';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Druid' AND playerSpec = 'Ballance';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Ballance Druid template set (human)!");
		    SaveBallanceDruidToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Druid' AND playerSpec = 'Ballance';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Ballance Druid template set!");
		    SaveBallanceDruidToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Druid' AND playerSpec = 'Ballance';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Ballance Druid template set!");
		    SaveBallanceDruidToDB(player);
		    return false;
		}
		return true;
    }

		// FERAL DRUID
		static bool HandleCreateDruidFeralItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DRUID)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Druid' AND playerSpec = 'Feral';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Druid' AND playerSpec = 'Feral';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Feral Druid template set (human)!");
		    SaveFeralDruidToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Druid' AND playerSpec = 'Feral';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Feral Druid template set!");
		    SaveFeralDruidToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Druid' AND playerSpec = 'Feral';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Feral Druid template set!");
		    SaveFeralDruidToDB(player);
		    return false;
		}
		return true;
    }

		// RESTORATION DRUID
		static bool HandleCreateDruidRestorationItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DRUID)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Druid' AND playerSpec = 'Restoration';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Druid' AND playerSpec = 'Restoration';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Restoration Druid template set (human)!");
		    SaveRestorationDruidToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Druid' AND playerSpec = 'Restoration';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Restoration Druid template set!");
		    SaveRestorationDruidToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Druid' AND playerSpec = 'Restoration';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Restoration Druid template set!");
		    SaveRestorationDruidToDB(player);
		    return false;
		}
		return true;
    }

		// MARKSMANSHIP HUNTER
		static bool HandleCreateHunterMarksmanshipItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_HUNTER)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Marksmanship Hunter template set (human)!");
		    SaveMarksmanshipHunterToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Marksmanship Hunter template set!");
		    SaveMarksmanshipHunterToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Hunter' AND playerSpec = 'Marksmanship';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Marksmanship Hunter template set!");
		    SaveMarksmanshipHunterToDB(player);
		    return false;
		}
		return true;
    }

		// BEASTMASTERY HUNTER
		static bool HandleCreateHunterBeastmasteryItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_HUNTER)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Beastmastery Hunter template set (human)!");
		    SaveBeastmasteryHunterToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Beastmastery Hunter template set!");
		    SaveBeastmasteryHunterToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Hunter' AND playerSpec = 'Beastmastery';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Beastmastery Hunter template set!");
		    SaveBeastmasteryHunterToDB(player);
		    return false;
		}
		return true;
    }

		// SURVIVAL HUNTER
		static bool HandleCreateHunterSurvivalItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_HUNTER)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Hunter' AND playerSpec = 'Survival';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Hunter' AND playerSpec = 'Survival';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Survival Hunter template set (human)!");
		    SaveSurvivalHunterToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Hunter' AND playerSpec = 'Survival';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Survival Hunter template set!");
		    SaveSurvivalHunterToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Hunter' AND playerSpec = 'Survival';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Survival Hunter template set!");
		    SaveSurvivalHunterToDB(player);
		    return false;
		}
		return true;
    }

		// ASSASSINATION ROGUE
		static bool HandleCreateRogueAssassinationItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_ROGUE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Assassination Rogue template set (human)!");
		    SaveAssassinationRogueToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Assassination Rogue template set!");
		    SaveAssassinationRogueToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Rogue' AND playerSpec = 'Assassination';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Assassination Rogue template set!");
		    SaveAssassinationRogueToDB(player);
		    return false;
		}
		return true;
    }

		// COMBAT ROGUE
		static bool HandleCreateRogueCombatItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_ROGUE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a rogue!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Rogue' AND playerSpec = 'Combat';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Rogue' AND playerSpec = 'Combat';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Combat Rogue template set (human)!");
		    SaveCombatRogueToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Rogue' AND playerSpec = 'Combat';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Combat Rogue template set!");
		    SaveCombatRogueToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Rogue' AND playerSpec = 'Combat';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Combat Rogue template set!");
		    SaveCombatRogueToDB(player);
		    return false;
		}
		return true;
    }

		// SUBTLETY ROGUE
		static bool HandleCreateRogueSubtletyItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_ROGUE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a rogue!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Subtlety Rogue template set (human)!");
		    SaveSubtletyRogueToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Subtlety Rogue template set!");
		    SaveSubtletyRogueToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'Rogue' AND playerSpec = 'Subtlety';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Subtlety Rogue template set!");
		    SaveSubtletyRogueToDB(player);
		    return false;
		}
		return true;
    }

		// BLOOD DEATHKNIGHT
		static bool HandleCreateDeathKnightBloodItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DEATH_KNIGHT)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a dk!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Blood DK template set (human)!");
		    SaveBloodDeathKnightToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Blood DK template set!");
		    SaveBloodDeathKnightToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'DeathKnight' AND playerSpec = 'Blood';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Blood DK template set!");
		    SaveBloodDeathKnightToDB(player);
		    return false;
		}
		return true;
    }

		// FROST DEATHKNIGHT
		static bool HandleCreateDeathKnightFrostItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DEATH_KNIGHT)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a dk!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Frost DK template set (human)!");
		    SaveFrostDeathKnightToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Frost DK template set!");
		    SaveFrostDeathKnightToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'DeathKnight' AND playerSpec = 'Frost';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Frost DK template set!");
		    SaveFrostDeathKnightToDB(player);
		    return false;
		}
		return true;
    }

		// UNHOLY DEATHKNIGHT
		static bool HandleCreateDeathKnightUnholyItemSetCommand(ChatHandler* handler, const char* args)
    {
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DEATH_KNIGHT)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a dk!");
			return false;
		}

		CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy';");
		if (player->getRace() == RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Unholy DK template set (human)!");
		    SaveUnholyDeathKnightToDB(player);
			return false;
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Unholy DK template set!");
		    SaveUnholyDeathKnightToDB(player);
		    return false;
		}
		else if (player->GetTeam() == HORDE)
		{
		    CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = 'DeathKnight' AND playerSpec = 'Unholy';");
		    player->GetSession()->SendAreaTriggerMessage("Successfuly created Unholy DK template set!");
		    SaveUnholyDeathKnightToDB(player);
		    return false;
		}
		return true;
    }
};

void AddSC_createItemSet_commandscript()
{
	new createItemSet_commandscript();
}