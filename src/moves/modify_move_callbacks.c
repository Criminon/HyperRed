 #include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "../battle_text/battle_pick_message.h"
/*
extern bool pkmn_has_type(u16 species, enum PokemonType type);
extern void add_residual_effect(ResidualEffectCallback effect, u8 bank, u8 t_bank, u8 priority);
extern u8 get_opponent_side(u8 bank);
extern void task_add_bmessage(u8 task_id);
extern u16 rand_range(u16 min, u16 max);



void blizzard_modify_move_cb(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    if (battle_master->field_state.is_hail) {
        battle_master->b_moves[bank].accuracy = 101;
    }
}

void thunder_modify_move_cb(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    if (battle_master->field_state.is_raining || battle_master->field_state.is_primordial_sea) {
        battle_master->b_moves[bank].accuracy = 101;
    } else if (battle_master->field_state.is_sunny || battle_master->field_state.is_desolate_land) {
        battle_master->b_moves[bank].accuracy = 50;
    }
}

extern void curse_residual_effect(u8 task_id);
void curse_modify_move_cb(u8 user_bank)
{
    u16 species = pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_SPECIES, NULL);
    if (pkmn_has_type(species, TYPE_GHOST)) {
        u8 opponent_bank = p_bank[user_bank]->user_action.target_bank;
        if (p_bank[opponent_bank]->user_action.buff_tag & CURSE_TAG)
            return;
        add_residual_effect(curse_residual_effect, user_bank, get_opponent_side(user_bank), 10);
    } else {
        u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
        battle_master->b_moves[bank].stat_self[0] = STAT_ATTACK;
        battle_master->b_moves[bank].stat_self[1] = STAT_DEFENSE;
        battle_master->b_moves[bank].stat_self[2] = STAT_SPEED;
        battle_master->b_moves[bank].amount_self[0] = 1;
        battle_master->b_moves[bank].amount_self[1] = 1;
        battle_master->b_moves[bank].amount_self[2] = -1;
        battle_master->b_moves[bank].chance_self = 100;
        return;
    }
}

 */

void fling_modify_move(u8 user_bank)
{
    /* TODO: Need to make a table for fling still */
}

/* 
void growth_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    if (battle_master->field_state.is_sunny) {
        battle_master->b_moves[bank].amount_self[0] = 2;
        battle_master->b_moves[bank].amount_self[1] = 2;
    }
}

void hidden_power_modify_move(u8 user_bank)
{
    u8 hpower_numerator = (1 * pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_HP_IV, NULL));
    hpower_numerator += (2 * pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_ATK_IV, NULL));
    hpower_numerator += (4 * pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_DEF_IV, NULL));
    hpower_numerator += (8 * pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_SPD_IV, NULL));
    hpower_numerator += (16 *  pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_SPATK_IV, NULL));
    hpower_numerator += (32 * pokemon_getattr(p_bank[user_bank]->this_pkmn, REQUEST_SPDEF_IV, NULL));
    hpower_numerator *= 15;
    hpower_numerator /= 63;
    
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    battle_master->b_moves[bank].type[0] = hpower_numerator + 1;
}

void hurricane_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    if (battle_master->field_state.is_raining || battle_master->field_state.is_primordial_sea) {
        battle_master->b_moves[bank].accuracy = 101;
    } else if (battle_master->field_state.is_raining || battle_master->field_state.is_primordial_sea) {
        battle_master->b_moves[bank].accuracy = 50;
    }
}

 */
void judgement_modify_move(u8 user_bank)
{
    /* TODO: Plate items table */
}

/* 
void ion_deluge(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    if (battle_master->field_state.is_ion_deluge) {
        battle_master->b_moves[bank].type[0] = TYPE_ELECTRIC;
    }
}


void electrify_modify_move(u8 user_bank)
{
    if (p_bank[user_bank]->user_action.buff_tag & ELECTRIFY_TAG) {
        u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
        battle_master->b_moves[bank].type[0] = TYPE_ELECTRIC;
    }
}

void magnitude_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    u8 magnitude_lvl = 4;
    u8 magnitude_size = rand_range(0, 100);
    if (magnitude_size < 5) {
        battle_master->b_moves[bank].power = 10;
    } else if (magnitude_size < 15) {
        battle_master->b_moves[bank].power = 30;
        magnitude_lvl = 5;
    } else if (magnitude_size < 35) {
        battle_master->b_moves[bank].power = 50;
        magnitude_lvl = 6;
    } else if (magnitude_size < 65) {
        battle_master->b_moves[bank].power = 70;
        magnitude_lvl = 7;
    } else if (magnitude_size < 85) {
        battle_master->b_moves[bank].power = 90;
        magnitude_lvl = 8;
    } else if (magnitude_size < 95) {
        battle_master->b_moves[bank].power = 110;
        magnitude_lvl = 9;
    } else {
        battle_master->b_moves[bank].power = 150;
        magnitude_lvl = 10;
    }
    
    u8 t_id = task_add(task_add_bmessage, 0x1);
    tasks[t_id].priv[0] = user_bank;
    tasks[t_id].priv[1] = magnitude_lvl;
    tasks[t_id].priv[2] = MOVE_MAGNITUDE;
    tasks[t_id].priv[4] = STRING_MAGNITUDE_AMOUNT;  
} */

void multiattack_modify_move(u8 user_bank)
{
    /* TODO: No table for multiattack available */
}

void natural_gift_modify_move(u8 user_bank)
{
    /* TODO: No table for natural gift available */
}

void technoblast(u8 user_bank)
{
    /* TODO: No table for technoblast available */
}
/* 
void present_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    u8 roll = rand_range(0, 10);
    if (roll < 2) {
        // heal
        battle_master->b_moves[bank].power = -25; // 25% heal
    } else if (roll < 6) {
        battle_master->b_moves[bank].power = 40;
    } else if (roll < 9) {
        battle_master->b_moves[bank].power = 80;
    } else {
        battle_master->b_moves[bank].power = 120;
    }
}

void pursuit_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    battle_master->b_moves[bank].accuracy = 101;
}

void revelation_dance_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    u8 current_type = p_bank[user_bank]->user_action.type[0];
    battle_master->b_moves[bank].type[0] = (current_type) ? current_type : p_bank[user_bank]->user_action.type[1]; 
}

void weather_ball_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    if (battle_master->field_state.is_sunny || battle_master->field_state.is_desolate_land) {
        battle_master->b_moves[bank].type[0] = TYPE_FIRE;
    } else if (battle_master->field_state.is_raining || battle_master->field_state.is_primordial_sea) {
        battle_master->b_moves[bank].type[0] = TYPE_WATER;
    } else if (battle_master->field_state.is_sandstorm) {
        battle_master->b_moves[bank].type[0] = TYPE_ROCK;
    } else if (battle_master->field_state.is_hail) {
        battle_master->b_moves[bank].type[0] = TYPE_ICE;
    } else {
        battle_master->b_moves[bank].type[0] = TYPE_NORMAL;
    }
}

void struggle_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    battle_master->b_moves[bank].type[0] = TYPE_NONE;
    battle_master->b_moves[bank].type[1] = TYPE_NONE;
}


void secret_power_modify_move(u8 user_bank)
{
    u8 bank = (battle_master->first_bank == user_bank) ? 0 : 1;
    if (battle_master->field_state.electric_terrain) {
        battle_master->b_moves[bank].secondary_status[0] = AILMENT_PARALYZE;
        battle_master->b_moves[bank].secondary_status_chance[0] = 30;
    } else if(battle_master->field_state.grassy_terrain) {
        battle_master->b_moves[bank].secondary_status[0] = AILMENT_SLEEP;
        battle_master->b_moves[bank].secondary_status_chance[0] = 30;
    } else if(battle_master->field_state.misty_terrain) {
        battle_master->b_moves[bank].stat_target[0] = STAT_SPECIAL_ATTACK;
        battle_master->b_moves[bank].amount_target[0] = -1;
        battle_master->b_moves[bank].chance_target = 30;
    } else if(battle_master->field_state.misty_terrain) {
        battle_master->b_moves[bank].stat_target[0] = STAT_SPEED;
        battle_master->b_moves[bank].amount_target[0] = -1;
        battle_master->b_moves[bank].chance_target = 30;
    }

}

void pollen_puff_modify_move(u8 user_bank)
{
    u8 target = p_bank[user_bank]->user_action.target_bank;
    extern u8 get_side(u8 bank);
    if (get_side(user_bank) == get_side(target)) {
        u8 order = (user_bank == battle_master->first_bank) ? 0 : 1;
        battle_master->b_moves[order].power = -50;
    }
}


 */










