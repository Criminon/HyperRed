#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "../abilities/battle_abilities.h"
#include "pkmn_bank_stats.h"

typedef u16 (*StatCallback)(u8, u16);

void update_move_history(u8 bank, u16 move_id)
{
    // figure out target
    if (*(move_t[move_id].m_flags) == FLAG_ONSELF)
        p_bank[bank]->b_data.my_target = bank;
    else if (*(move_t[move_id].m_flags) == FLAG_TARGET)
        p_bank[bank]->b_data.my_target = FOE_BANK(bank);
    
    // update current move and last used moves
    if (p_bank[bank]->b_data.current_move)
        p_bank[bank]->b_data.last_move = p_bank[bank]->b_data.current_move;
    p_bank[bank]->b_data.current_move = move_id;
    
    // update moves used history
    u8 i;
    for (i = 0; i < 4; i++) {
        if (p_bank[bank]->b_data.moves_used[i] == move_id)
            return;
        if (p_bank[bank]->b_data.moves_used[i] == MOVE_NONE)
            p_bank[bank]->b_data.moves_used[i] = move_id;
            return;
    }
}

/*
 * Returns the stat after stage modifications have been done. Id represents which stat has been modified
 * 0 - atk; 1 - def; 2 - speed; 3 - spatk; 4 - spdef; 5 - accuracy; 6 - evasion; 7 - Crit chance
 */
const static u16 stat_mod[13] = {25, 29, 33, 40, 50, 67, 100, 150, 200, 250, 300, 350, 400};
const static u16 acc_mod[13] = {33, 38, 43, 50, 60, 75, 100, 133, 167, 200, 233, 266, 300};
const static u16 crit_mod[4] = {6, 13, 50, 100};

u16 stage_modify_stat(u16 stat, s8 mod, u8 id, u8 bank)
{
    u16 stat_total;
    
    /* atk, def, spd, spa, spdef */
    if (id < 5) {
        stat_total = NUM_MOD(stat, stat_mod[mod + 6]);
    } else if (id < 7) {
        /* Accuracy and Evasion */
        stat_total = acc_mod[mod + 6];
    } else {
        /* crit chance */
        stat_total = (mod > sizeof(crit_mod)) ? acc_mod[sizeof(crit_mod) - 1]: acc_mod[mod];
    }
    
    // apply modifiers to stat via callback. Example: Ability Huge Power
    switch (id) {
        case 0:
            stat_total += ability_attack_mod(bank, stat_total);
            break;
        case 1:
            stat_total += ability_defense_mod(bank, stat_total);
            break;
        case 2:
            stat_total += ability_speed_mod(bank, stat_total);
            break;
        case 3:
            stat_total += ability_sp_attack_mod(bank, stat_total);
            break;
        case 4:
            stat_total += ability_sp_defense_mod(bank, stat_total);
            break;
        case 5:
            stat_total += ability_accuracy_mod(bank, stat_total);
            break;
        case 6:
            stat_total += ability_evasion_mod(bank, stat_total);
            break;
        case 7:
            stat_total += ability_critchance_mod(bank, stat_total);
            break;
    };
    
    return stat_total;
}



















