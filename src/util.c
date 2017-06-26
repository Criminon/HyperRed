#include <pokeagb/pokeagb.h>
#include "moves/moves.h"
#include "battle_data/pkmn_bank_stats.h"
#include "abilities/battle_abilities.h"

extern bool enqueue_message(u16 move, u8 bank, enum battle_string_ids id, u16 effect);
u16 rand_range(u16 min, u16 max)
{
    return (rand() / (0xFFFF / (max - min))) + min;
}

bool knows_move(u16 move_id, struct Pokemon* p)
{
    u8 i;
    for (i = REQUEST_MOVE1; i < (REQUEST_MOVE1 + 4); i++) {
        u16 move = pokemon_getattr(p, i, NULL);
        if (move == move_id)
            return true;
    }
    return false;
}

u8 get_side(u8 bank)
{
    return (bank > 1) ? 1 : 0;
}

u8 get_opponent_side(u8 bank)
{
    return ((!(get_side(bank))) * 2);
}

u8 get_ability(struct Pokemon* p)
{
    u8 ability_bit = pokemon_getattr(p, REQUEST_ABILITY_BIT, NULL);
    return pokemon_base_stats[pokemon_getattr(p, REQUEST_SPECIES, NULL)].ability[ability_bit];
}

bool ignoring_item(struct Pokemon* p)
{
    return (get_ability(p) == ABILITY_KLUTZ);
}

/* TODO: Update this function. Hard coded and too short sighted */
u8 move_target(u8 bank, u16 move_id)
{
    if (*(move_t[move_id].m_flags) & FLAG_ONSELF) {
        return bank;
    } else {
        return (bank) ? 0 : 2;
    }
}


bool pkmn_has_type(u16 species, enum PokemonType type)
{
    if ((pokemon_base_stats[species].type[0] == type) || (pokemon_base_stats[species].type[1] == type)) {
        return true;
    }
    return false;
}

bool b_pkmn_has_type(u8 bank, enum PokemonType type)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (p_bank[bank]->b_data.type[i] == type) {
            return true;
        }
    }
    return false;
}


bool on_ground(u8 bank)
{
    if (b_pkmn_has_type(bank, TYPE_FLYING) ||
       (p_bank[bank]->b_data.ability == ABILITY_LEVITATE)) {
        if(p_bank[bank]->b_data.is_grounded)
            return true;
        return false;
    }
    return true;
}

s8 move_effectiveness(u8 move_type, u8 target_bank)
{
    extern u8 effectiveness_chart[342];
    // -3 : 1/8x dmg
    // -2 : 1/4x dmg
    // -1 : 1/2x dmg
    //  0 : 1x damage
    // +1 : 2x dmg
    // +2 : 4x dmg
    // +3 : 6x dmg
    s8 effectiveness = 0;
    u8 i;
    for (i = 0; i < 3; i ++) {
        // if one of the types are immune, return 3
        u8 target_type = p_bank[target_bank]->b_data.type[i];
        if (MOVE_EFFECTIVENESS(target_type, move_type) == 3)
            return 0xFF;
        if (MOVE_EFFECTIVENESS(target_type, move_type) == 2)
            effectiveness--;
        if (MOVE_EFFECTIVENESS(target_type, move_type) == 1)
            effectiveness++;
    }
    return effectiveness;
}

void stat_boost(u8 bank, u8 stat_id, s8 amount)
{
    if (abilities_table[BANK_ABILITY(bank)]->on_boost) {
        if (abilities_table[BANK_ABILITY(bank)]->on_boost(bank, amount, stat_id))
            return;
    }        
    switch (stat_id) {
        case REQUEST_ATK:
            {
            p_bank[bank]->b_data.attack += amount;
            break;
            }
        case REQUEST_DEF:
            {
            p_bank[bank]->b_data.defense += amount;
            break;
            }
        case REQUEST_SPD:
            {
            p_bank[bank]->b_data.speed += amount;
            break;
            }
        case REQUEST_SPATK:
            {
            p_bank[bank]->b_data.sp_atk += amount;
            break;
            }
        case REQUEST_SPDEF:
            {
            p_bank[bank]->b_data.sp_def += amount;
            break;
            }
        case 51: // evasion
            {
            p_bank[bank]->b_data.evasion += amount;
            break;
            }
        case 52: // accuracy
            {
            p_bank[bank]->b_data.accuracy += amount;
            break;
            }
        case 53: // crit
            {
            p_bank[bank]->b_data.crit_mod += amount;
            break;
            }
    };

    amount += 6;
    switch (amount) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            enqueue_message(0, bank, STRING_STAT_MOD_HARSH_DROP, stat_id);
            break;
        case 5:
            enqueue_message(0, bank, STRING_STAT_MOD_DROP, stat_id);
            break;
        case 6:
            break;
        case 7:
            enqueue_message(0, bank, STRING_STAT_MOD_RISE, stat_id);
            break;
        default:
            enqueue_message(0, bank, STRING_STAT_MOD_HARSH_RISE, stat_id);
            break;
    };
}

void set_status(u8 bank, u8 source, enum Effect status)
{
    bool status_applied = false;
    // lowest priority for override are types and current status
    switch (status) {
        case EFFECT_NONE:
            // clear all ailments. Cured
            p_bank[bank]->b_data.status = EFFECT_NONE;
            p_bank[bank]->b_data.status_turns = 0;
            p_bank[bank]->b_data.confusion_turns = 0;
            enqueue_message(0, bank, STRING_AILMENT_CURED, 0);
            return;
            break;
        case EFFECT_PARALYZE:
            // electric types are immune. Already status'd is immune
            if ((b_pkmn_has_type(bank, TYPE_ELECTRIC)) || (p_bank[bank]->b_data.status != AILMENT_NONE)) {
                status_applied = false;
            } else {
                status_applied = true;
            }
            break;
        case EFFECT_BURN:
            // fire types are immune.  Already status'd is immune
            if ((b_pkmn_has_type(bank, TYPE_FIRE)) || (p_bank[bank]->b_data.status != AILMENT_NONE)) {
                status_applied = false;
            } else {
                status_applied = true;
            }
            break;
        case EFFECT_POISON:
        case EFFECT_BAD_POISON:
            // poison and steel types are immune. Already status'd is immune
            if ((b_pkmn_has_type(bank, TYPE_POISON)) || (b_pkmn_has_type(bank, TYPE_STEEL)) ||
                (p_bank[bank]->b_data.status != AILMENT_NONE)) {
                status_applied = false;
            } else {
                status_applied = true;
            }
			break;
        case EFFECT_SLEEP:
            // sleep isn't affected by type
            if ((p_bank[bank]->b_data.status != AILMENT_NONE)) {
                status_applied = false;
            } else {
                status_applied = true;
            }
            break;
        case EFFECT_FREEZE:
            // ice types cannot be frozen
            if ((b_pkmn_has_type(bank, TYPE_FIRE)) || (p_bank[bank]->b_data.status != AILMENT_NONE)) {
                status_applied = false;
            } else {
                status_applied = true;
            }
			break;
        case EFFECT_CONFUSION:
            // Confusion isn't affected by type
            if ((p_bank[bank]->b_data.status != AILMENT_NONE)) {
                status_applied = false;
            } else {
                status_applied = true;
            }
            p_bank[bank]->b_data.confusion_turns = rand_range(1, 4);
			break;
        default:
            break;
    };
    
    // execute per side on_set_status callbacks -  things like safeguard checks should be done here
    /* TODO */
    
    // on set status callbacks Ability
    // the ability of target being status'd exec
    if (abilities_table[BANK_ABILITY(bank)]->on_set_status) {
        // check if ability modified outcome of set status
        if (abilities_table[BANK_ABILITY(bank)]->on_set_status(bank, source, status, status_applied)) {
            // status would've been set in callback. Exit.
            return;
        }
    }
    // the ability of the attack user execution
    if (abilities_table[BANK_ABILITY(source)]->on_set_status) {
        // check if ability modified outcome of set status
        if (abilities_table[BANK_ABILITY(source)]->on_set_status(source, source, status, status_applied)) {
            // status would've been set in callback. Exit.
            return;
        }
    }
    
    if (status_applied) {
        p_bank[bank]->b_data.status = status;
        enqueue_message(0, bank, STRING_AILMENT_APPLIED, status);
    } else {
        enqueue_message(0, bank, STRING_AILMENT_IMMUNE, status);
    }
}


//TODO: IMPLEMENT
void set_ability(u8 bank, u8 source, u8 new_ability)
{

}

