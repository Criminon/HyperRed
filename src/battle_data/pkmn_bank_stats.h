#ifndef PKMN_BANK_STAT_H_
#define PKMN_BANK_STAT_H_

#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "battle_text/battle_pick_message.h"


/* 
 * Get Pokemon's current battle stats based on stage changes to stat 
 *
 */
#define B_ATTACK_STAT(bank) stage_modify_stat(pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_ATK, NULL), p_bank[bank]->b_data.attack, 0, bank)
#define B_DEFENSE_STAT(bank) stage_modify_stat(pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_DEF, NULL), p_bank[bank]->b_data.defense, 1, bank)
#define B_SPEED_STAT(bank) stage_modify_stat(pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_SPD, NULL), p_bank[bank]->b_data.speed, 2, bank)
#define B_SPATTACK_STAT(bank) stage_modify_stat(pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_SPATK, NULL), p_bank[bank]->b_data.sp_atk, 3, bank)
#define B_SPDEFENSE_STAT(bank) stage_modify_stat(pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_SPDEF, NULL), p_bank[bank]->b_data.sp_def, 4, bank)
#define B_ACCURACY_STAT(bank) stage_modify_stat(0, p_bank[bank]->b_data.accuracy, 5, bank)
#define B_EVASION_STAT(bank) stage_modify_stat(0, p_bank[bank]->b_data.evasion, 6, bank)
#define B_CRITCHANCE_STAT(bank) stage_modify_stat(0, p_bank[bank]->b_data.crit_mod, 7, bank)

#define NUM_MOD(number, percent) ((number * percent) / 100)

/*
 * P_bank b_data volatile macros
 */
#define ADD_VOLATILE(bank, v) p_bank[bank]->b_data.v_status |= v
#define REMOVE_VOLATILE(bank, v) p_bank[bank]->b_data.v_status ^= v
#define HAS_VOLATILE(bank, v) p_bank[bank]->b_data.v_status & v

/*
 * P_bank b_data set and fetch macros
 *
 */
#define CURRENT_MOVE(bank) p_bank[bank]->b_data.current_move
#define LAST_MOVE(bank) p_bank[bank]->b_data.last_move
#define BANK_ABILITY(bank) p_bank[bank]->b_data.ability
#define B_MOVE_BANK(bank) (bank == battle_master->first_bank) ? 0 : 1
#define B_MOVE_TYPE(bank, i) battle_master->b_moves[B_MOVE_BANK(bank)].type[i] 
#define B_MOVE_POWER(bank) battle_master->b_moves[B_MOVE_BANK(bank)].power
#define B_MOVE_ACCURACY(bank) battle_master->b_moves[B_MOVE_BANK(bank)].accuracy
#define B_MOVE_PRIORITY(bank) battle_master->b_moves[B_MOVE_BANK(bank)].priority
#define B_MOVE_REMOVE_CONTACT(bank) battle_master->b_moves[B_MOVE_BANK(bank)].remove_contact
#define B_MOVE_IGNORING_ABILITIES(bank) battle_master->b_moves[B_MOVE_BANK(bank)].ignore_abilities
#define B_MOVE_HAS_TYPE(bank, type) ((B_MOVE_TYPE(bank, 0) == type) || (B_MOVE_TYPE(bank, 1) == type))
#define B_MOVE_IS_STATUS(bank) (battle_master->b_moves[B_MOVE_BANK(bank)].category == MOVE_STATUS)



#define B_PKMN_TYPE(bank, index) p_bank[bank]->b_data.type[index]
#define B_CURRENT_HP(bank) p_bank[bank]->b_data.current_hp
#define TOTAL_HP(x) p_bank[x]->b_data.total_hp
#define B_STATUS(bank) p_bank[bank]->b_data.status
#define TARGET_OF(bank) p_bank[bank]->b_data.my_target
#define SET_CONFUSION_TURNS(bank, v) p_bank[bank]->b_data.confusion_turns = v
#define B_IS_GROUNDED(bank) p_bank[bank]->b_data.is_grounded
#define B_IS_PRANKSTER(bank) battle_master->b_moves[B_MOVE_BANK(bank)].prankstered
#define B_INFILTRATES(bank) battle_master->b_moves[B_MOVE_BANK(bank)].infiltrates

/*
 * General Pbank macros
 */
#define FOE_BANK(bank) bank ? 0 : 2
#define SIDE_OF(bank) (bank > 1) ? 1 : 0

#define MOVE_EFFECTIVENESS(target_type, dmg_type) effectiveness_chart[(target_type * 18) + dmg_type]
 
 
extern void update_move_history(u8 bank, u16 move_id);
extern s8 ability_priority_mod(u8 bank, u16 move_id);
extern s8 ability_attack_mod(u8 bank, u16 stat_total);
extern s8 ability_defense_mod(u8 bank, u16 stat_total);
extern s8 ability_speed_mod(u8 bank, u16 stat_total);
extern s8 ability_sp_defense_mod(u8 bank, u16 stat_total);
extern s8 ability_sp_attack_mod(u8 bank, u16 stat_total);
extern s8 ability_critchance_mod(u8 bank, u16 stat_total);
extern s8 ability_accuracy_mod(u8 bank, u16 stat);
extern s8 ability_evasion_mod(u8 bank, u16 stat);
extern u16 stage_modify_stat(u16 stat, s8 mod, u8 id, u8 bank);
extern void ability_on_before_switch(u8 bank);
extern void ability_on_switch(u8 bank);
extern void ability_on_modify_move(u8 bank, u8 target, u16 move);
extern u8 ability_on_tryhit(u8 attacker, u8 defender, u16 move);


#endif /* PKMN_BANK_STAT_H_ */
