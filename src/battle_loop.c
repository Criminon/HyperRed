#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_data/pkmn_bank_stats.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "battle_text/battle_pick_message.h"

extern void pick_battle_message(u16 move_id, u8 user_bank, enum BattleFlag battle_type, enum battle_string_ids id, u16 effect_id);
extern u8 get_side(u8 bank);
extern u8 move_target(u8 bank, u16 move_id);
extern void run_decision(void);
extern u16 rand_range(u16 min, u16 max);
extern bool enqueue_message(u16 move, u8 bank, enum battle_string_ids id, u16 effect);
extern bool peek_message(void);
extern void run_move(void);

u16 pick_player_attack()
{
    u16 player_moveid = battle_master->battle_cursor.cursor_pos + REQUEST_MOVE1;
    if (player_moveid == (REQUEST_MOVE1 + 1)) {
        player_moveid += 1;
    } else if (player_moveid == (REQUEST_MOVE1 + 2)) {
        player_moveid -= 1;
    }  
    return pokemon_getattr(p_bank[PLAYER_SINGLES_BANK]->this_pkmn, player_moveid, NULL);    
}

u16 pick_opponent_attack()
{
    u8 move_total = 0;
    u8 i;
    for (i = 0; i < 4; i++) {
        if (pokemon_getattr(p_bank[OPPONENT_SINGLES_BANK]->this_pkmn, REQUEST_MOVE1 + i, NULL)) {
            move_total++;
        } else {
            break;
        }     
    }  
    return pokemon_getattr(p_bank[OPPONENT_SINGLES_BANK]->this_pkmn, rand_range(0, move_total)+ REQUEST_MOVE1, NULL);
}

void set_attack_bm(u8 bank, u8 index, s8 priority)
{
    u16 move_id = p_bank[bank]->b_data.current_move;

    battle_master->b_moves[index].user_bank = bank;
    battle_master->b_moves[index].move_id = move_id;
    battle_master->b_moves[index].priority = priority;
    battle_master->b_moves[index].stab = 150; // move stab bonus
    battle_master->b_moves[index].power = MOVE_POWER(move_id);
    battle_master->b_moves[index].category = MOVE_CATEGORY(move_id);
    battle_master->b_moves[index].type[0] = MOVE_TYPE(move_id);
    battle_master->b_moves[index].type[1] = MOVE_TYPE(move_id);
    battle_master->b_moves[index].flinch = M_FLINCH(move_id);
    battle_master->b_moves[index].accuracy = MOVE_ACCURACY(move_id);
    battle_master->b_moves[index].remove_contact = false;
    battle_master->b_moves[index].copied = false;
    battle_master->b_moves[index].ignore_abilities = false;
    battle_master->b_moves[index].prankstered = HAS_VOLATILE(bank, VOLATILE_PRANKSTERED);
    REMOVE_VOLATILE(bank, VOLATILE_PRANKSTERED);
    battle_master->b_moves[index].infiltrates = false;
    battle_master->b_moves[bank].chance_self = move_t[move_id].procs->chance_self;
    battle_master->b_moves[bank].chance_target = move_t[move_id].procs->chance_target;
    
    u8 i;
    for (i = 0; i < 6; i++) {
        battle_master->b_moves[bank].stat_self[i] = move_t[move_id].procs->stat_self[i];
        battle_master->b_moves[bank].stat_target[i] = move_t[move_id].procs->stat_target[i];
        battle_master->b_moves[bank].amount_self[i] = move_t[move_id].procs->amount_self[i];
        battle_master->b_moves[bank].amount_target[i] = move_t[move_id].procs->amount_target[i];
    }
}

u8 set_target_bank(u8 user_bank, u16 move_id)
{
    // check who the move targets
    if (*(move_t[move_id].m_flags) & FLAG_ONSELF) {
        p_bank[user_bank]->b_data.my_target = user_bank;
        return user_bank;
    } else { //if (*(move_t[move_id].m_flags) & FLAG_TARGET) {
        p_bank[user_bank]->b_data.my_target = FOE_BANK(user_bank);
        return FOE_BANK(user_bank);
    }
}

bool target_exists(u8 bank)
{
    /* TODO this should be more thorough */
    // target has hp remaining
    if (B_CURRENT_HP(TARGET_OF(bank)))
        return true;
    return false;
}

void switch_battler(u8 switching_bank)
{
    /* TODO actual switching */
    return;
}

void battle_loop()
{
    // fetch moves used from input
    u16 p_move = pick_player_attack();
    u16 opp_move = pick_opponent_attack();
    battle_master->fight_menu_content_spawned = 0;
    
    // update internal move history
    update_move_history(PLAYER_SINGLES_BANK, p_move);
    update_move_history(OPPONENT_SINGLES_BANK, opp_move);
    
    /* check if ability boosts priority of move, and update */
    s8 player_priority = ability_priority_mod(PLAYER_SINGLES_BANK, p_move);
    s8 opp_priority = ability_priority_mod(PLAYER_SINGLES_BANK, p_move);

    /* update selected move's innate priority */
    player_priority += MOVE_PRIORITY(p_move);
    opp_priority += MOVE_PRIORITY(opp_move);
    
    /* Turn order, higher priority will go first */
    if (player_priority > opp_priority) {
        battle_master->first_bank = PLAYER_SINGLES_BANK;
        battle_master->second_bank = OPPONENT_SINGLES_BANK;
    } else if (player_priority < opp_priority) {
        battle_master->first_bank = OPPONENT_SINGLES_BANK;
        battle_master->second_bank = PLAYER_SINGLES_BANK;
    } else {
        // matching priorities, retrieve speed stat
        u16 player_speed = B_SPEED_STAT(PLAYER_SINGLES_BANK);
        u16 opponent_speed = B_SPEED_STAT(OPPONENT_SINGLES_BANK);
        
        // roll speed tie
        if (player_speed == opponent_speed) {
            if (rand_range(0, 1))
                player_speed++;
            else
                opponent_speed++;
        }
        
        // higher speed goes first
        if (player_speed > opponent_speed) {
            battle_master->first_bank = PLAYER_SINGLES_BANK;
            battle_master->second_bank = OPPONENT_SINGLES_BANK;
        } else {
            battle_master->first_bank = OPPONENT_SINGLES_BANK;
            battle_master->second_bank = PLAYER_SINGLES_BANK;
        }   
    }
    set_attack_bm(battle_master->first_bank, 0, battle_master->first_bank == PLAYER_SINGLES_BANK ? player_priority : opp_priority);
    set_attack_bm(battle_master->second_bank, 1, battle_master->second_bank == OPPONENT_SINGLES_BANK ? opp_priority : player_priority);
    set_target_bank(battle_master->first_bank, p_bank[battle_master->first_bank]->b_data.current_move);
    set_target_bank(battle_master->second_bank, p_bank[battle_master->second_bank]->b_data.current_move);
   
    /* Run each move's before turn */
    /*if (move_t[CURRENT_MOVE(battle_master->first_bank)].move_cb->bt_cb)
        move_t[CURRENT_MOVE(battle_master->first_bank)].move_cb->bt_cb(battle_master->first_bank);
    if (move_t[CURRENT_MOVE(battle_master->second_bank)].move_cb->bt_cb)
        move_t[CURRENT_MOVE(battle_master->second_bank)].move_cb->bt_cb(battle_master->second_bank);*/
    
    super.multi_purpose_state_tracker = 0;
    battle_master->execution_index = 0;
    set_callback1(run_decision);
}

void run_switch()
{
    u8 bank_index = (battle_master->execution_index) ? battle_master->second_bank : battle_master->first_bank;
    switch(super.multi_purpose_state_tracker) {
        case 0:
        {
            // if first bank is switching exec before switch cbs. Else jump to second bank is switching check
            if (p_bank[battle_master->first_bank]->b_data.is_switching) {
                ability_on_before_switch(bank_index);
                super.multi_purpose_state_tracker++;
            } else {
                super.multi_purpose_state_tracker = 2;
            }
            break;
        }
        case 1:
        {
            // play queued messages from before_switch bank 1. Once done go to second bank switch check
            if (!peek_message())
                switch_battler(bank_index);
                super.multi_purpose_state_tracker++;
                break;
        }
        default:
            super.multi_purpose_state_tracker = 1;
            set_callback1(run_decision);
            break;
    };
}

void run_after_switch()
{
    u8 bank_index = (battle_master->execution_index) ? battle_master->second_bank : battle_master->first_bank;
    ability_on_switch(bank_index);
    super.multi_purpose_state_tracker = 2;
    set_callback1(run_decision);
    return;
}

bool try_hit(u8 attacker)
{
    // if moves never misses, exit early
    u8 move_accuracy = B_MOVE_ACCURACY(attacker);
    if (move_accuracy > 100) {
        return true;
    }
    
    // if target is in semi invulnerability do checks
    u8 defender = TARGET_OF(attacker);
    if (HAS_VOLATILE(defender, VOLATILE_SEMI_INVULNERABLE)) {
        if (move_t[LAST_MOVE(defender)].move_cb->inv_tryhit_cb) {
            if (!(move_t[LAST_MOVE(defender)].move_cb->inv_tryhit_cb(CURRENT_MOVE(attacker))))
                return false;
        }
    }

    // standard accuracy formula check
    u16 target_evasion = B_EVASION_STAT(defender);
    u16 user_accuracy = B_ACCURACY_STAT(attacker);
    
    u16 result = (user_accuracy / target_evasion) * move_accuracy;
    if (rand_range(0, 100) <= result) {
        return true;
    }
    if (target_evasion > 100) {
        enqueue_message(0, attacker, STRING_ATTACK_AVOIDED, 0);
    } else {
        enqueue_message(0, attacker, STRING_ATTACK_MISSED, 0);
    }
    return false;
}

bool is_immune(u8 attacker, u8 defender, u16 move)
{
    return false;
}

#define MOVE_TRYHIT 0
#define MOVE_TRYHIT_SIDE 0
void move_hit()
{
    u8 bank_index = (battle_master->execution_index) ? battle_master->second_bank : battle_master->first_bank;
    u16 move = CURRENT_MOVE(bank_index);
    switch(super.multi_purpose_state_tracker) {
        case 0:
        {
            bool move_hits = true;
            if (MOVE_TRYHIT) {
                // move try hit callback exec
            } else if (MOVE_TRYHIT_SIDE) {
                // move tryhit side callback exec
            }
            if (move_hits) {
                super.multi_purpose_state_tracker = 2;
            } else {
                super.multi_purpose_state_tracker++;
            }
            break;
        }
        case 1:
            if (!peek_message()) {
                super.multi_purpose_state_tracker = 5;
                set_callback1(run_move);
            }
            break;
        case 2:
            // run ability tryhits
            if (!(HAS_VOLATILE(bank_index, VOLATILE_MOLDBREAKER))) {
                if (ability_on_tryhit(bank_index, TARGET_OF(bank_index), move)) {
                    super.multi_purpose_state_tracker++;
                } else {
                    super.multi_purpose_state_tracker = 1;
                }
            } else {
                // moldbreaker means we skip ability tryhits
                super.multi_purpose_state_tracker++;
            }
            break;
        case 3:
        {
            if (!peek_message()) {
                if (try_hit(bank_index)) {
                    // check immunity
                    if (is_immune(bank_index, TARGET_OF(bank_index), CURRENT_MOVE(bank_index))) {
                        super.multi_purpose_state_tracker = 1;
                    } else {
                    // not immune, and attack has landed
                        super.multi_purpose_state_tracker = 5;
                        set_callback1(run_move);
                    }
                } else {
                    // move has missed
                    super.multi_purpose_state_tracker = 5;
                    set_callback1(run_move);
                }
            }
            break;
        }
    };
}


#define BEFORE_MOVE_CALLBACK_0 0
void run_move()
{
    u8 bank_index = (battle_master->execution_index) ? battle_master->second_bank : battle_master->first_bank;
    switch(super.multi_purpose_state_tracker) {
        case 0:
            /* TODO :  Before move callbacks */
            if (BEFORE_MOVE_CALLBACK_0) {
                // move failed
                super.multi_purpose_state_tracker = 1;
            } else {
                enqueue_message(CURRENT_MOVE(bank_index), bank_index, STRING_ATTACK_USED, 0);
                super.multi_purpose_state_tracker = 2;
            }
            break;
        case 1:
            if (!peek_message()) {
                super.multi_purpose_state_tracker = 4; // exit
                set_callback1(run_decision);
            }
            break;
        case 2:
            // Modify move callbacks
            if (!peek_message()) {
                ability_on_modify_move(bank_index, TARGET_OF(bank_index), CURRENT_MOVE(bank_index));
                super.multi_purpose_state_tracker++;
            }
            break;
        case 3:
            if (!peek_message()) {
                // check target exists
                if (!target_exists(bank_index)) {
                    enqueue_message(0, bank_index, STRING_FAILED, 0);
                    super.multi_purpose_state_tracker = 5; // PP reduction state
                } else {
                    super.multi_purpose_state_tracker++;
                }
            }
            break;
        case 4:
            if (!peek_message()) {
                set_callback1(move_hit); // move hit will advance the state when complete
                super.multi_purpose_state_tracker = 0;
            }
            break;
        case 5:
            if (!peek_message()) {
                super.multi_purpose_state_tracker = 4; // exit
                set_callback1(run_decision);
            }
            break;
        
    };
}

void run_decision(void)
{
    u8 bank_index = (battle_master->execution_index) ? battle_master->second_bank : battle_master->first_bank;
    switch (super.multi_purpose_state_tracker) {
       case 0:
            set_callback1(run_switch);
            super.multi_purpose_state_tracker = 0;
            break;
        case 1:
            set_callback1(run_after_switch);
            super.multi_purpose_state_tracker = 0;
            break;
        case 2:
            // once first bank's run_switch and run_after_switch have exec'd, run second bank
            if (bank_index == battle_master->second_bank) {
                // if second bank run, switch back to first bank and go to next phase
                battle_master->execution_index = 0;
                super.multi_purpose_state_tracker++;
            } else {
                battle_master->execution_index = 1;
                super.multi_purpose_state_tracker = 0;
            }
            break;
        case 3:
            set_callback1(run_move);
            super.multi_purpose_state_tracker = 0;
            break;
        case 4:
            // run move for second bank after first bank is run. else run on faint stuff
            if (bank_index == battle_master->second_bank) {
                battle_master->execution_index = 0;
                super.multi_purpose_state_tracker++;
            } else {
                battle_master->execution_index = 1;
                super.multi_purpose_state_tracker = 3;
            }
            break;
        case 5:
        {
            extern void option_selection(void);
            set_callback1(option_selection);
            super.multi_purpose_state_tracker = 0;
            battle_master->execution_index = 0;
            break;
        }
        default:
            break;
    };
}























