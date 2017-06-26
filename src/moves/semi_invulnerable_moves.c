#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "../battle_text/battle_pick_message.h"

/* General exceptions of moves like earthquake hitting targets using dig is handled in move_on_try.c */
/* extern void task_add_bmessage(u8 t_id);
void sky_drop_before_move_cb(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & SKY_DROP_TAG) {
        u8 t_id = task_add(task_add_bmessage, 0x1);
        tasks[t_id].priv[0] = user_bank;       
        tasks[t_id].priv[2] = MOVE_SKY_DROP;
        tasks[t_id].priv[4] = STRING_FAILED;
        tasks[t_id].priv[3] = super.multi_purpose_state_tracker + 1;
        return;
    }
    return;
}

void sky_drop_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    u8 opponent_bank = user_bank ? 0 : 2;
    if (p_bank[opponent_bank]->user_action.buff_tag & SKY_DROP_TAG) {
        battle_master->b_moves[bank].accuracy = 101;
    }
}

 */