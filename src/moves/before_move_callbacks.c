#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "../battle_text/battle_pick_message.h"
/* 
extern u8 get_target_bank(u8 user_bank, u16 move_id);
extern u16 rand_range(u16 min, u16 max);
extern void pick_battle_message(u16 move_id, u8 user_bank, enum BattleFlag battle_type, enum battle_string_ids id, u16 effect_id);
extern bool ignoring_item(struct Pokemon* p);


void task_add_bmessage(u8 task_id)
{
    switch (tasks[task_id].priv[3]) {
        case 0:
            pick_battle_message(tasks[task_id].priv[2], tasks[task_id].priv[0], battle_type_flags, tasks[task_id].priv[4], tasks[task_id].priv[1]);
            battle_show_message((u8*)string_buffer, 0x18);
            tasks[task_id].priv[3]++;
            break;
        case 1:
           if (!dialogid_was_acknowledged(0x18 & 0x3F)) {
                task_del(task_id);
                super.multi_purpose_state_tracker = tasks[task_id].priv[3];
            }
            break;
    };     
}


void attract_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & ATTRACT_TAG) {   
        if (!rand_range(0, 2)) {
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;
            tasks[t_id].priv[4] = STRING_INFATUATED;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
            return;
        }
    }
        return;
}


void destiny_bond_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & DESTINY_BOND_TAG) {
        p_bank[user_bank]->user_action.buff_tag ^= DESTINY_BOND_TAG; // Bitwise XoR removes the tag
    }
}


void disable_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & DISABLE_TAG) {   
        if (p_bank[user_bank]->user_action.turns_disabled < 4) {
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;
            tasks[t_id].priv[1] = MOVE_DISABLE;
            tasks[t_id].priv[2] = p_bank[user_bank]->user_action.move_id;
            tasks[t_id].priv[4] = STRING_DISABLED;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
            return;
        } else {
            p_bank[user_bank]->user_action.buff_tag ^= DISABLE_TAG;
            p_bank[user_bank]->user_action.turns_disabled = 0;
            return;
        }
    }
}




void gravity_check_before_move_cb(u8 user_bank)
{
    u16 move_id = p_bank[user_bank]->user_action.move_id;
    if (*(move_t[move_id].m_flags) & FLAG_GRAVITY_DISABLED) {
        u8 t_id = task_add(task_add_bmessage, 0x1);
        tasks[t_id].priv[0] = user_bank;        
        tasks[t_id].priv[1] = MOVE_GRAVITY;
        tasks[t_id].priv[2] = move_id;
        tasks[t_id].priv[4] = STRING_CANT_USE;
        tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
        return;
    }
    return;
}


void grudge_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & GRUDGE_TAG) {
        p_bank[user_bank]->user_action.buff_tag ^= GRUDGE_TAG; // Bitwise XoR removes the tag
    }
}


void heal_block_before_move_cb(u8 user_bank)
{
    u16 move_id = p_bank[user_bank]->user_action.move_id;
    if (p_bank[user_bank]->user_action.buff_tag & HEAL_BLOCK_TAG) {
        if (p_bank[user_bank]->user_action.heal_block_turns > 4) {
            p_bank[user_bank]->user_action.buff_tag ^= HEAL_BLOCK_TAG;
            return;
        }
        if (*(move_t[move_id].m_flags) & FLAG_HEAL_BLOCK_DISABLED) {
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;   
            tasks[t_id].priv[2] = move_id;            
            tasks[t_id].priv[1] = MOVE_HEAL_BLOCK;
            tasks[t_id].priv[4] = STRING_CANT_USE;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
            return;
        }
    }
    return;
}


extern bool knows_move(u16 move_id, struct Pokemon* p);
void imprison_before_move_cb(u8 user_bank)
{
    if (!(p_bank[user_bank]->user_action.buff_tag & IMPRISON_TAG))
        return;
        
    u8 i;
    u8 opp_move;
    for (i = 0; i < 4; i++) {
        u8 warden_bank = p_bank[user_bank]->user_action.imprisoned_by_bank;
        opp_move = pokemon_getattr(p_bank[warden_bank]->this_pkmn, REQUEST_MOVE1 + i, NULL);
        if ((opp_move != MOVE_NONE) && (knows_move(opp_move, p_bank[user_bank]->this_pkmn))) {
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;            
            tasks[t_id].priv[2] = MOVE_IMPRISON;
            tasks[t_id].priv[4] = STRING_DISABLED;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
            return;
        }
    }
}
 */

void natural_gift(u8 user_bank)
{
    /* TODO */
    // Have to make a table for this still.
}

/* 
void rage_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & RAGE_TAG) {
        p_bank[user_bank]->user_action.buff_tag ^= RAGE_TAG; // Bitwise XoR removes the tag
    }
}


void shelltrap_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & SHELLTRAP_TAG) {
        if (p_bank[user_bank]->user_action.physical_dmg_taken) {
            p_bank[user_bank]->user_action.buff_tag ^= SHELLTRAP_TAG;
            p_bank[user_bank]->user_action.physical_dmg_taken = 0;
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;            
            tasks[t_id].priv[2] = MOVE_SHELL_TRAP;
            tasks[t_id].priv[4] = STRING_FAILED;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
            return;
        }
    }
    return;
}


void taunt_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & TAUNT_TAG) {
        u16 move_id = p_bank[user_bank]->user_action.move_id;
        if (move_t[move_id].category == MOVE_STATUS) {
            u8 t_id = task_add(task_add_bmessage, 0x1);
            tasks[t_id].priv[0] = user_bank;
            tasks[t_id].priv[2] = move_id;            
            tasks[t_id].priv[1] = MOVE_TAUNT;
            tasks[t_id].priv[4] = STRING_CANT_USE;
            tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
        }        
    }
}


void throat_chop_before_move_cb(u8 user_bank)
{
    if (!(p_bank[user_bank]->user_action.buff_tag & THROAT_CHOP_TAG)) {
        return;
    }
    u16 move_id = p_bank[user_bank]->user_action.move_id;
    if (*(move_t[move_id].m_flags) & FLAG_SOUND_BASED) {
        u8 t_id = task_add(task_add_bmessage, 0x1);
        tasks[t_id].priv[0] = user_bank;
        tasks[t_id].priv[2] = move_id;        
        tasks[t_id].priv[1] = MOVE_THROAT_CHOP;
        tasks[t_id].priv[4] = STRING_CANT_USE;
        tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
        return;
    }
    return;
}


void fling_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.move_id != MOVE_FLING)
        return;
    u16 item_id = pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_HELD_ITEM, NULL);
    if ((item_id) && (!(ignoring_item(p_bank[user_bank]->this_pkmn)))) {
        p_bank[user_bank]->user_action.item_to_use = item_id;
        item_id = 0;
        pokemon_setattr(p_bank[user_bank]->this_pkmn, REQUEST_HELD_ITEM, &item_id);
        return;
    } else {
        u8 t_id = task_add(task_add_bmessage, 0x1);
        tasks[t_id].priv[0] = user_bank;        
        tasks[t_id].priv[2] = MOVE_FLING;
        tasks[t_id].priv[4] = STRING_FAILED;
        tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
        return;
    }
}


void add_bmcallback(BeforeMoveCallback bmc_func, u8 bank)
{
    u8 i;
    for (i = 0; i < 12; i++) {
        BeforeMoveCallback func = p_bank[bank]->user_action.bmc[i];
        if ((func == NULL) || (func == bmc_func)) {
            p_bank[bank]->user_action.bmc[i] = bmc_func;
            return;
        }
    }
}


void del_bmcallback(BeforeMoveCallback bmc_func, u8 bank)
{
    u8 i;
    for (i = 0; i < 12; i++) {
        BeforeMoveCallback func = p_bank[bank]->user_action.bmc[i];
        if (func == bmc_func) {
            p_bank[bank]->user_action.bmc[i] = NULL;
            return;
        }
    }
}


void exec_bmcallbacks(u8 bank)
{
    u8 i;
    for (i = 0; i < 12; i++) {
        if (p_bank[bank]->user_action.bmc[i]) {
            (p_bank[bank]->user_action.bmc[i])(bank);
            return;
        }
    }
}
 */

/* These are move tags that you need to filter through and check every turn */
/* void anonymous_before_move_cbs(u8 user_bank)
{
    exec_bmcallbacks(user_bank);
    if (task_is_running(task_add_bmessage)) {
        super.multi_purpose_state_tracker = 99;
        return;
    }
    super.multi_purpose_state_tracker++;
}

 */
