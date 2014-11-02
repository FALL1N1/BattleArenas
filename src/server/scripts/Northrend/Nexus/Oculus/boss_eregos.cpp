/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "oculus.h"

//Types of drake mounts: Ruby(Tank),  Amber(DPS),  Emerald(Healer)
//Two Repeating phases

enum Events
{
    EVENT_ARCANE_BARRAGE = 1,
    EVENT_ARCANE_VOLLEY,
    EVENT_ENRAGED_ASSAULT,
    EVENT_SUMMON_LEY_WHELP
};

enum Says
{
    SAY_AGGRO                                     = 1,
    SAY_KILL                                      = 2,
    SAY_ENRAGE                                    = 3,
    SAY_DEATH                                     = 4 
};

enum Spells
{
    SPELL_ARCANE_BARRAGE                          = 50804,
    SPELL_ARCANE_VOLLEY                           = 51153,
    SPELL_ENRAGED_ASSAULT                         = 51170,
    SPELL_PLANAR_ANOMALIES                        = 57959,
    SPELL_PLANAR_SHIFT                            = 51162,
    SPELL_SUMMON_LEY_WHELP                        = 51175,
    SPELL_SUMMON_PLANAR_ANOMALIES                 = 57963,
    SPELL_PLANAR_BLAST                            = 57976
};

enum Npcs
{
    NPC_PLANAR_ANOMALY = 30879
};

enum Phases
{
    PHASE_NORMAL = 1,
    PHASE_FIRST_PLANAR = 2,
    PHASE_SECOND_PLANAR = 3
};

enum Actions
{
    ACTION_SET_NORMAL_EVENTS = 1
};

class boss_eregos : public CreatureScript
{
public:
    boss_eregos() : CreatureScript("boss_eregos") { }

    struct boss_eregosAI : public BossAI
    {
        boss_eregosAI(Creature* creature) : BossAI(creature, DATA_EREGOS_EVENT) { }

        void Reset()
        {
            _Reset();

            phase = PHASE_NORMAL;
            EmeraldVoid = true;
            RubyVoid = true;
            AmberVoid = true;

            me->SetSpeed(MOVE_FLIGHT, 2.8f);
            DoAction(ACTION_SET_NORMAL_EVENTS);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if(Creature* EmeraldDrake = me->FindNearestCreature(27692, 300, true))
                EmeraldVoid = false;
            if(Creature*RubyDrake = me->FindNearestCreature(27756, 300, true))
                RubyVoid = false;
            if(Creature* AmberDrake = me->FindNearestCreature(27755, 300, true))
                AmberVoid = false;

            _EnterCombat();

            Talk(SAY_AGGRO);
        }

        void DoAction(const int32 action)
        {
            if (action != ACTION_SET_NORMAL_EVENTS)
                return;

            events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(3, 10) * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_ARCANE_VOLLEY, urand(10, 25) * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_ENRAGED_ASSAULT, urand(35, 50) * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_SUMMON_LEY_WHELP, urand(15, 30) * IN_MILLISECONDS, 0, PHASE_NORMAL);
        }

        void JustSummoned(Creature* summon)
        {
            BossAI::JustSummoned(summon);

            if (summon->GetEntry() != NPC_PLANAR_ANOMALY)
                return;

            summon->CombatStop(true);
            summon->SetReactState(REACT_PASSIVE);
            summon->GetMotionMaster()->MoveRandom(100.0f);
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            if (summon->GetEntry() != NPC_PLANAR_ANOMALY)
                return;

            // TO-DO: See why the spell is not casted
            summon->CastSpell(summon, SPELL_PLANAR_BLAST, true);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
        {
            if (!me->GetMap()->IsHeroic())
                return;

            if ((me->HealthBelowPct(60) && me->HealthAbovePct(20) && phase < PHASE_FIRST_PLANAR) ||
                (me->HealthBelowPct(20) && phase < PHASE_SECOND_PLANAR))
            {
                events.Reset();
                phase = (me->HealthBelowPct(60) && me->HealthAbovePct(20)) ? PHASE_FIRST_PLANAR : PHASE_SECOND_PLANAR;

                DoCast(SPELL_PLANAR_SHIFT);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ARCANE_BARRAGE:
                        DoCast(me->getVictim(), SPELL_ARCANE_BARRAGE);
                        events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(3, 10) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                    case EVENT_ARCANE_VOLLEY:
                        DoCastAOE(SPELL_ARCANE_VOLLEY);
                        events.ScheduleEvent(EVENT_ARCANE_VOLLEY, urand(10, 25) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                    case EVENT_ENRAGED_ASSAULT:
                        Talk(SAY_ENRAGE);
                        DoCast(SPELL_ENRAGED_ASSAULT);
                        events.ScheduleEvent(EVENT_ENRAGED_ASSAULT, urand(35, 50) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                    case EVENT_SUMMON_LEY_WHELP:
                        for (uint8 i = 0; i < 3; i++)
                            DoCast(SPELL_SUMMON_LEY_WHELP);
                        events.ScheduleEvent(EVENT_SUMMON_LEY_WHELP, urand(15, 30) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            /*if (IsHeroic())
            {
                if (EmeraldVoid)
                    instance->DoCompleteAchievement(2045);
                if (RubyVoid)
                    instance->DoCompleteAchievement(2044);
                if (AmberVoid)
                    instance->DoCompleteAchievement(2046);
            }*/
            
            _JustDied();
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_KILL);
        }
        
    private:
        InstanceScript* _instance;

        uint8 phase;
        bool EmeraldVoid;
        bool RubyVoid;
        bool AmberVoid;
    };
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_eregosAI (creature);
    }

};

enum AnomalySpells
{
    SPELL_PLANAR_DISTORTION                       = 59379, // Periodic damage aura
    SPELL_PLANAR_SPARK                            = 57971, // Visual
};

class mob_planar_anomaly : public CreatureScript
{
public:
    mob_planar_anomaly() : CreatureScript("mob_planar_anomaly") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_planar_anomalyAI(creature);
    }
    
    struct mob_planar_anomalyAI : public ScriptedAI
    {
        mob_planar_anomalyAI(Creature *creature) : ScriptedAI(creature) {}
 
        void Reset()
        {
            BlastTimer = 16000;
            me->CanFly();
            me->SetSpeed(MOVE_FLIGHT, 3.1f);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->AddAura(SPELL_PLANAR_DISTORTION, me);
            me->AddAura(SPELL_PLANAR_SPARK, me);
            me->DespawnOrUnsummon(18000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (BlastTimer && BlastTimer <= uiDiff)
            {
                DoCastAOE(SPELL_PLANAR_BLAST, true);
                BlastTimer = 0;
            }
            else
                BlastTimer -= uiDiff;
        }
        
    private:
        uint32 BlastTimer;
    };
};

class spell_eregos_planar_shift : public SpellScriptLoader
{
    public:
        spell_eregos_planar_shift() : SpellScriptLoader("spell_eregos_planar_shift") { }

        class spell_eregos_planar_shift_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_eregos_planar_shift_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                     if (Creature* creatureCaster = caster->ToCreature())
                        if (InstanceScript* _instance = caster->GetInstanceScript())
                        {
                            Map::PlayerList const &players = _instance->instance->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                if (Player* _player = itr->getSource())
                                    if(Creature* anomaly = _player->SummonCreature(NPC_PLANAR_ANOMALY, _player->GetPositionX() + urand(5, 10), _player->GetPositionY() + urand(5, 10), _player->GetPositionZ()))
                                        if(Unit* drake = _player->GetVehicleBase())
                                            anomaly->GetMotionMaster()->MoveChase(drake);
                                        else
                                            anomaly->GetMotionMaster()->MoveChase(_player);
                        }
            }
            
            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* creatureCaster = caster->ToCreature())
                        creatureCaster->AI()->DoAction(ACTION_SET_NORMAL_EVENTS);
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_eregos_planar_shift_AuraScript::OnApply, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_eregos_planar_shift_AuraScript();
        }
};

void AddSC_boss_eregos()
{
    new boss_eregos();
    new mob_planar_anomaly();
    new spell_eregos_planar_shift();
}
