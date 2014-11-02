////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#ifndef SOLO_QUEUE_H
#define SOLO_QUEUE_H

// TalentTab.dbc -> TalentTabID
const uint32 HEALER_TALENTS[] = 
{
	201, // PriestDiscipline
	202, // PriestHoly
	382, // PaladinHoly
	262, // ShamanRestoration
	282, // DruidRestoration
	0 // End
};

const uint32 MELEE_TALENTS[] = 
{
	161, // WarriorArms
	182, // RogueAssassination
	398, // DKBlood
	164, // WarriorFury
	181, // RogueCombat
	263, // ShamanEnhancement
	281, // DruidFeral
	383, // PaladinProtection
	163, // WarriorProtection
    183, // RogueSubtlety
	381, // Paladin Retribution
	400, // DKUnholy
	399, // DKFrost
	0 // End
};

const uint32 RANGED_TALENTS[] = 
{
	361, // HunterBeastMastery
	363, // HunterMarksmanship
	362, // HunterSurvival
	81,  // MageArcane
	261, // ShamanElemental
	283, // DruidBallance
	302, // WarlockAffliction
	41,  // MageFire
	303, // WarlockDemonology
	61,  // MageFrost
	203, // PriestShadow
	301, // WarlockDestruction
	0 // End
};


// Return false, if player have invested more than 35 talentpoints in a forbidden talenttree.
static bool playerIsHealer(Player* player)
{
	if (!player)
		return false;

	uint32 count = 0;
	for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
	{
		TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

		if (!talentInfo)
			continue;

		for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
		{
			if (talentInfo->RankID[rank] == 0)
				continue;
						
			if (player->HasTalent(talentInfo->RankID[rank], player->GetActiveSpec()))
			{
				for(int8 i = 0; HEALER_TALENTS[i] != 0; i++)
					if(HEALER_TALENTS[i] == talentInfo->TalentTab)
						count += rank + 1;
			}
		}
	}

	if (count <= 36)
	{
		// HEALER
		return false;
	}
	return true;
}

static bool playerIsMelee(Player* player)
{
	if (!player)
		return false;

	uint32 count = 0;
	for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
	{
		TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

		if (!talentInfo)
			continue;

		for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
		{
			if (talentInfo->RankID[rank] == 0)
				continue;
						
			if (player->HasTalent(talentInfo->RankID[rank], player->GetActiveSpec()))
			{
				for(int8 i = 0; MELEE_TALENTS[i] != 0; i++)
					if(MELEE_TALENTS[i] == talentInfo->TalentTab)
						count += rank + 1;
			}
		}
	}

	if (count <= 36)
	{
		// MELEE
		return false;
	}
	return true;
}

static bool playerIsCaster(Player* player)
{
	if (!player)
		return false;

	uint32 count = 0;
	for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
	{
		TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

		if (!talentInfo)
			continue;

		for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
		{
			if (talentInfo->RankID[rank] == 0)
				continue;
						
			if (player->HasTalent(talentInfo->RankID[rank], player->GetActiveSpec()))
			{
				for(int8 i = 0; RANGED_TALENTS[i] != 0; i++)
					if(RANGED_TALENTS[i] == talentInfo->TalentTab)
						count += rank + 1;
			}
		}
	}

	if (count <= 36)
	{
		// RANGED
		return false;
	}
	return true;
}

#endif