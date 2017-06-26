#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"

/* 
void add_before_damage_callback(DamageCallback bdmg_func, u8 bank)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        DamageCallback func = p_bank[bank]->user_action.bdc[i];
        if ((func == NULL) || (func == bdmg_func)) {
            p_bank[bank]->user_action.bdc[i] = bdmg_func;
            return;
        }
    }
}


void del_before_damage_callback(DamageCallback bdmg_func, u8 bank)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        DamageCallback func = p_bank[bank]->user_action.bdc[i];
        if (func == bdmg_func) {
            p_bank[bank]->user_action.bdc[i] = NULL;
            return;
        }
    }
}


void exec_before_damage_callbacks(u8 bank, u16 move_id)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        if (p_bank[bank]->user_action.bdc[i]) {
            (p_bank[bank]->user_action.bdc[i])(bank, move_id);
            return;
        }
    }
}

 */
/* These are move tags that you need to filter through and check every turn */
/* void anonymous_before_damage_callbacks(u8 user_bank, u16 move_id)
{
    exec_before_damage_callbacks(user_bank, move_id);
    extern void task_add_bmessage(u8 t_id);
    if (task_is_running(task_add_bmessage)) {
        super.multi_purpose_state_tracker = 99;
        return;
    }
    super.multi_purpose_state_tracker++;
}
 */

