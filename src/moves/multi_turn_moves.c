#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "../battle_text/battle_pick_message.h"

extern void task_add_bmessage(u8 t_id);

/*
 * Bide, Focus Punch, Sky drop, Solar beam, Razorwind, Freeze shock, Ice Burn
 * Geomancy, Solar blade, Skull Bash
 */
/* 
void bide_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & BIDE_TAG) {
        if (p_bank[user_bank]->user_action.charging_move_counter < 2) {
            p_bank[user_bank]->user_action.charging_move_counter++;
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;
            tasks[t_id].priv[2] = MOVE_BIDE;
            tasks[t_id].priv[4] = STRING_BIDE_CHARGE;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
        }
    }
}

void focus_punch_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & FOCUS_PUNCH_TAG) {
        if (p_bank[user_bank]->user_action.total_dmg_taken) {
            p_bank[user_bank]->user_action.buff_tag ^= FOCUS_PUNCH_TAG;
            p_bank[user_bank]->user_action.total_dmg_taken = 0;
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;      
            tasks[t_id].priv[2] = MOVE_FOCUS_PUNCH;
            tasks[t_id].priv[4] = STRING_LOST_FOCUS;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
            return;
        }
    }
    return;
}

void chargeup_before_move_cb(u8 user_bank, u8 string_id)
{
    if (p_bank[user_bank]->user_action.charge_turn) {
        p_bank[user_bank]->user_action.charge_turn = false;
        return;
    }
    u8 move_bank = (user_bank == battle_master->first_bank) ? 0 : 1;
    u8 t_id = task_add(task_add_bmessage, 0x1);
    tasks[t_id].priv[0] = user_bank;      
    tasks[t_id].priv[2] = battle_master->b_moves[move_bank].move_id;
    tasks[t_id].priv[4] = string_id;
    tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
    p_bank[user_bank]->user_action.charge_turn = true;
}

void chargeup_before_dmg_callback(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.charge_turn) {
        return;
    } else {
        super.multi_purpose_state_tracker = 98;
    }
}

void skull_bash_before_dmg_callback(u8 user_bank)
{
    u8 move_bank = (user_bank == battle_master->first_bank) ? 0 : 1;
    if (p_bank[user_bank]->user_action.charge_turn) {
        battle_master->b_moves[move_bank].power = 0;
        battle_master->b_moves[move_bank].category = MOVE_STATUS;
        return;
    } else {
        battle_master->b_moves[move_bank].power = 130;
        battle_master->b_moves[move_bank].category = MOVE_PHYSICAL;
    }
}

void razor_wind_before_move_cb(u8 user_bank)
{
    chargeup_before_move_cb(user_bank, STRING_RAZORWIND);
}

void skull_bash_before_move_cb(u8 user_bank)
{
    chargeup_before_move_cb(user_bank, STRING_SKULL_BASH);
}

void solar_beam_before_move_cb(u8 user_bank)
{
    if (battle_master->field_state.is_sunny)
        return;
    chargeup_before_move_cb(user_bank, STRING_SOLARBEAM);
}

void legendary_charging_modify_move(u8 user_bank, u8 string_id) {
    if (p_bank[user_bank]->user_action.frz_shock_mod_move_cb_used) {
        return;
    }
    p_bank[user_bank]->user_action.frz_shock_mod_move_cb_used = 1;
    u8 move_bank = (user_bank == battle_master->first_bank) ? 0 : 1;
    u8 t_id = task_add(task_add_bmessage, 0x1);
    tasks[t_id].priv[0] = user_bank;      
    tasks[t_id].priv[2] = battle_master->b_moves[move_bank].move_id;
    tasks[t_id].priv[4] = string_id;
    tasks[t_id].priv[3] = super.multi_purpose_state_tracker = 4;
}

void freeze_shock_modify_move(u8 user_bank)
{
    legendary_charging_modify_move(user_bank, STRING_FREEZE_SHOCK);
}


void ice_burn_modify_move(u8 user_bank)
{
    legendary_charging_modify_move(user_bank, STRING_ICE_BURN);
}

void geomancy_modify_move(u8 user_bank)
{
    legendary_charging_modify_move(user_bank, STRING_GOEMANCY);
}

void solar_blade_modify_move(u8 user_bank)
{
    legendary_charging_modify_move(user_bank, STRING_SOLARBEAM);
}
 */
/* Freeze shock procs */
struct move_procs freeze_shock_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    1,              // Lower bound for multi hit
    1,               // Upper bound for multi hit
    {AILMENT_PARALYZE, AILMENT_NONE},
    {30, 0},
    0
};

/* Ice Burn procs */
struct move_procs ice_burn_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    1,              // Lower bound for multi hit
    1,               // Upper bound for multi hit
    {AILMENT_BURN, AILMENT_NONE},
    {30, 0},
    0
};

/* Geomancy */
struct move_procs geomancy_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_SPECIAL_ATTACK, STAT_SPECIAL_DEFENSE, STAT_SPEED, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {2, 2, 2, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    1,              // Lower bound for multi hit
    1,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE},
    {0, 0},
    0
};

// Skull Bash
struct move_procs skull_bash_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_DEFENSE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {1, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    1,              // Lower bound for multi hit
    1,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE},
    {0, 0},
    0
};