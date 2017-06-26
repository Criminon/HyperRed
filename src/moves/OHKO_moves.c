#include <pokeagb/pokeagb.h>
#include "moves.h"

/*
 * Guillotine, Horn Drill, Fissure, Sheer Cold,
 */

/* void OHKO_modify_move(u8 user_bank)
{
    u8 target_bank = p_bank[user_bank]->user_action.target_bank;
    u8 target_lvl = p_bank[target_bank]->this_pkmn->level;
    u8 user_lvl = p_bank[user_bank]->this_pkmn->level;
    u8 move_bank = (user_bank == battle_master->first_bank) ? 0 : 1;
    if (target_lvl > (user_lvl + 30)) {
        battle_master->b_moves[move_bank].accuracy = 0;
    } else {
        battle_master->b_moves[move_bank].accuracy = (user_lvl + 30) - target_lvl;
    }
}

void OHKO_before_damage_callback(u8 bank, u16 move_id)
{
    battle_master->damage_to_deal = p_bank[bank]->this_pkmn->current_hp;
}

 */