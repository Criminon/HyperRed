#include <pokeagb/pokeagb.h>
#include "../battle_data/pkmn_bank.h"
#include "../battle_state.h"
#include "battle_pick_message.h"


bool enqueue_message(u16 move, u8 bank, enum battle_string_ids id, u16 effect)
{
    u8 back = battle_master->queue_size;
    if (back > 9)
        return false;
    battle_master->b_message[back].move_id = move;
    battle_master->b_message[back].bank = bank;
    battle_master->b_message[back].string_id = id;
    battle_master->b_message[back].effect = effect;
    battle_master->queue_size++;
    return true;
}

bool peek_message()
{
    /* If no messages are queued, exit */
    u8 back = battle_master->queue_size;
    if (back == battle_master->queue_front_index) {
        battle_master->queue_size = 0;
        battle_master->queue_front_index = 0;
        return false;
    }
    battle_master->state = super.multi_purpose_state_tracker;
    battle_master->c1 = super.callback1;
    extern void play_bmessage(void);
    super.callback1 = play_bmessage;
    super.multi_purpose_state_tracker = 0;
    return true;;
}


void play_bmessage()
{
    u8 front = battle_master->queue_front_index;
    switch(super.multi_purpose_state_tracker) {
        case 0:
        {
            extern void pick_battle_message(u16 move_id, u8 user_bank, enum BattleFlag battle_type, enum battle_string_ids id, u16 move_effect_id);

            pick_battle_message(battle_master->b_message[front].move_id, battle_master->b_message[front].bank, battle_type_flags,
            battle_master->b_message[front].string_id, battle_master->b_message[front].effect);
            battle_show_message((u8*)string_buffer, 0x18);
            super.multi_purpose_state_tracker++;
        }
            break;
        case 1:
            if (!dialogid_was_acknowledged(0x18)) {
                super.multi_purpose_state_tracker++;
            }
            break;
        case 2:
        {
            super.multi_purpose_state_tracker = battle_master->state;
            battle_master->queue_front_index++;
            set_callback1(battle_master->c1);
            
            break;
        }
        default:
            break;
    };
}


