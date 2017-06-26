/* #include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"

extern u8 get_target_bank(u8 user_bank, u16 move_id);

void opponenttag_before_turn_cb(u8 user_bank)
{
    u8 t_bank = get_target_bank(user_bank, p_bank[user_bank]->user_action.move_id);
    p_bank[user_bank]->user_action.target_bank = t_bank;
    
    switch (p_bank[user_bank]->user_action.move_id)
    {
        case MOVE_ASSURANCE:
        {
            p_bank[t_bank]->user_action.buff_tag |= ASSURANCE_TAG;
            break;
        }
        case MOVE_PURSUIT:
        {
            p_bank[t_bank]->user_action.buff_tag |= PURSUIT_TAG;
            break;
        }
    };
    return;
}

void selftag_before_turn_cb(u8 user_bank)
{
    switch (p_bank[user_bank]->user_action.move_id)
    {
        case MOVE_BEAK_BLAST:
        {
            p_bank[user_bank]->user_action.buff_tag |= BEAKBLAST_TAG;
            break;
        }
        case MOVE_FOCUS_PUNCH:
        {
            p_bank[user_bank]->user_action.buff_tag |= FOCUS_PUNCH_TAG;
            break;
        }
        case MOVE_METAL_BURST:
        {
            p_bank[user_bank]->user_action.buff_tag |= METAL_BURST_TAG;
            break;
        }
        case MOVE_MIRROR_COAT:
        {
            p_bank[user_bank]->user_action.buff_tag |= MIRROR_COAT_TAG;
            break;
        }
        case MOVE_SHELL_TRAP:
        {
            p_bank[user_bank]->user_action.buff_tag |= SHELLTRAP_TAG;
            break;
        }
        default:
            if (MOVE_COUNTER == (p_bank[user_bank]->user_action.move_id))
                p_bank[user_bank]->user_action.buff_tag |= COUNTER_TAG;
                break;
    };
    p_bank[user_bank]->user_action.target_bank = user_bank;
    return;
}

struct move_callbacks revengemove_cb = {
    .bt_cb = selftag_before_turn_cb,
};

struct move_callbacks reverse_revengemove_cb = {
    .bt_cb = opponenttag_before_turn_cb,
};


 */