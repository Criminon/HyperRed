#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"

extern u16 rand_range(u16, u16);
extern u8 get_side(u8);
/* 
u8 protection_tryhit(u8 user_bank)
{
    // higher chance to fail on consecutive protects
    if (p_bank[user_bank]->user_action.times_protected) {
        if (!(rand_range(0, 100) < (p_bank[user_bank]->user_action.times_protected * 2))) {
            return false;
        }
    }
    // fails if user moves last
    if (user_bank == battle_master->second_bank)
        return false;
    
    p_bank[user_bank]->user_action.times_protected++;
    p_bank[user_bank]->user_action.used_protect = true;
    return true;
}


u8 endure_tryhit(u8 user_bank)
{
    if (protection_tryhit(user_bank)) {
        p_bank[user_bank]->user_action.used_endure = true;
        return true;
    }
    return false;
}


u8 kings_shield_tryhit(u8 user_bank)
{
    if (protection_tryhit(user_bank)) {
        p_bank[user_bank]->user_action.kings_sheild = true;
        return true;
    }
    return false;
}


u8 quick_guard_tryhit(u8 user_bank)
{    
    // fails if already up
    return (protection_tryhit(user_bank) && (!(battle_master->field_state.quick_guard & (get_side(user_bank) + 1))));
}

void protection_before_dmg_cb(u8 user_bank, u16 move_id)
{
    if (p_bank[user_bank]->user_action.used_protect) {
        // if the move isn't protectable, damage goes through protect.
        if (*(move_t[move_id].m_flags) & FLAG_PROTECTABLE)
            battle_master->damage_to_deal = 0;
    }
}

void detect_endure_before_dmg_cb(u8 user_bank, u16 move_id)
{
    u16 user_hp = p_bank[user_bank]->this_pkmn->current_hp;
    if ((p_bank[user_bank]->user_action.used_endure) &&
        (*(move_t[move_id].m_flags) & FLAG_PROTECTABLE) &&
        (battle_master->damage_to_deal > user_hp)) {
        battle_master->damage_to_deal = user_hp - 1; // survive with 1 HP
        }
}

void quick_guard_before_dmg_cb(u8 user_bank, u16 move_id)
{
    // if move is priority move and doesn't go through protect, negate damage
        if (p_bank[user_bank]->user_action.used_protect) {
            // if the move isn't protectable, damage goes through protect.
            if ((*(move_t[move_id].m_flags) & FLAG_PROTECTABLE) &&
                (move_t[move_id].priority))
                battle_master->damage_to_deal = 0;
    }
}


// Moves: Wide guard, Spiky Shield, Quick guard, King's shield, Endure, Detect, Protect


struct move_procs protection_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE},
    {0, 0}
};

// Wide guard, Spiky shield, protect
struct move_callbacks protection_callbacks = {
    NULL, // before turn callback
    NULL, // before Move callback
    NULL, // modify move callback
    (TryHitCallback)protection_tryhit, // Try hit callback
    (DamageCallback)protection_before_dmg_cb, // Damage callback
};

// king's shield
struct move_callbacks kings_shield_callbacks = {
    NULL, // before turn callback
    NULL, // before Move callback
    NULL, // modify move callback
    (TryHitCallback)kings_shield_tryhit, // Try hit callback
    (DamageCallback)protection_before_dmg_cb, // Damage callback
};

// quick guard
struct move_callbacks quick_guard_callbacks = {
    NULL, // before turn callback
    NULL, // before Move callback
    NULL, // modify move callback
    (TryHitCallback)quick_guard_tryhit, // Try hit callback
    (DamageCallback)protection_before_dmg_cb, // Damage callback
};

// endure & detect
struct move_callbacks endure_callbacks = {
    NULL, // before turn callback
    NULL, // before Move callback
    NULL, // modify move callback
    (TryHitCallback)endure_tryhit, // Try hit callback
    (DamageCallback)detect_endure_before_dmg_cb, // Damage callback
};
 */





