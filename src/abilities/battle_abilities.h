#ifndef BATTLE_ABILITIES_TABLE_H_
#define BATTLE_ABILITIES_TABLE_H_

#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"

typedef u16 (*StatCallback)(u8, u16); // bank, stat amount
typedef void (*BasePowerCallback)(u8, u16); // bank, move
typedef s8 (*AbilityModMovePriorityCallback)(u8, u16); // bank, move
typedef void (*AbilityModMoveCallback)(u8, u8, u16); // bank, tbank, move
typedef void (*AbilitySwitchInCallback)(u8);
typedef void (*AbilityResidualCallback)(u8);
typedef u8 (*AbilityTryHitCallback)(u8, u8, u16); // bank, tbank, move
typedef u16 (*AbilityOnDamageCallback)(u8, u8, u16, u16, u8, u16); // bank, tbank, move, damage taken, ability, item
typedef void (*AbilityAfterDamageCallback)(u8, u8, u16, u16, u8, u16); // bank, tbank, move, damage taken, ability, item
typedef void (*AbilityAfterMoveSecondaryCallback)(u8, u8, u16, u8, u16); // bank, tbank, move, ability, item
typedef void (*AbilityModifySecondaryCallback)(u8, u8, u16, u8, u16); // bank, tbank, move, ability, item
typedef void (*AbilityUpdateCallback)(u8);
typedef bool (*AbilitySetStatusCallback)(u8, u8, enum Effect, bool); //bank, atkbank, Effect, status_is_settable
typedef void (*AbilityOnFaintCallback)(u8, u8); //bank, fainted
typedef void (*AbilityOnTryHealCallback)(u8, u8); //bank, healing bank
typedef void (*AbilityAfterBoostCallback)(u8, s8); //bank, amount boosted
typedef bool (*AbilityOnBoostCallback)(u8, s8, u8); //bank, amount boosted, boosting stat
typedef bool (*AbilityOnImmunityCallback)(u8, enum Effect); //bank, effect
typedef void (*AbilityOnBasePowerSourceCallback)(u8,u8, u16); // attacker, defender, move


typedef u8 (*AbilityOnDraggedOutCallback)(u8);

// Chronological order
struct b_ability {
    /*
     * on_priority_mod is the first callback called out of all ability callbacks.
     * It takes a parameter bank which is the bank id of the pokemon with the ability in question.
     * The second parameter is a move_id of the move the ability user is picking. It is 
     * expected to return a signed delta priority value which to modify the move priority by.
     * I.e Prankster would return 1 on success case and 0 on fail case.
     * This callback is expected to be silent, should not execute text display.
     */
    AbilityModMovePriorityCallback on_priority_mod;
    
    /*
     * The on_speed callback takes two parameters, the bank of the pokemon with the ability
     * and the current speed stat of that pokemon (after boost modifiers). It's expected
     * to return the base speed stat of the pokemon after the ability has affected the pokemon.
     */
    StatCallback on_speed;
    
    /*
     * on_before_switch is the callback that's run before pkmn are switched into the field.
     * It will only run on a switch taking place. Call format is:
     * on_before_switch(pokemon with ability's bank)
     */
    AbilitySwitchInCallback on_before_switch;
    
    /*
     * on_switch is the callback that's run after all pokemon have been switched into the field.
     * It will run regardless of any switches taking place. Call format is:
     * on_switch(pokemon with ability's bank)
     */
    AbilitySwitchInCallback on_switch;
    
    /*
     * on_modify_move is called before the move is executed. It's called after the on_switch callbacks
     * it's expected to modify the move inside the move data structure in RAM. Call format:
     * on_modify_move(pokemon with ability, target bank, move id)
     */    
    AbilityModMoveCallback on_modify_move; 
    
    /*
     * on_tryhit is called after the move tryhit callbacks are executed. Takes in a attacker and defender
     * as the first two parameters and the last parameter is a move id. It will return false if the move fails
     * to land. True if the move lands. Call format:
     * on_tryhit(attacker, defender, move id)
     */
    AbilityTryHitCallback on_tryhit;
    
    
    StatCallback on_attack;
    StatCallback on_defense;
    StatCallback on_sp_attack;
    StatCallback on_sp_defense;
    StatCallback on_accuracy;
    StatCallback on_evasion;
    StatCallback on_critchance;
    BasePowerCallback on_base_power;
    AbilityOnBasePowerSourceCallback on_source_base_power;
    
    
     
    
    AbilityOnDamageCallback on_damage; // right before damage is applied. Can modify dmg
    AbilityAfterDamageCallback on_after_damage;
    AbilitySetStatusCallback on_set_status;
    AbilityModifySecondaryCallback on_mod_secondary;
    AbilityAfterMoveSecondaryCallback on_after_move_secondary;
    AbilityResidualCallback on_residual;
    AbilityUpdateCallback on_update;
    AbilityOnFaintCallback on_faint;
    
    AbilityOnTryHealCallback on_try_heal;
    AbilityOnDraggedOutCallback on_dragout;
    AbilityAfterBoostCallback on_after_boost;
    AbilityOnBoostCallback on_boost;
    AbilityOnImmunityCallback on_immunity;
};

#define ABILITIES_MAX 5
extern struct b_ability* abilities_table[11];








#endif /* BATTLE_ABILITIES_TABLE_H_ */
