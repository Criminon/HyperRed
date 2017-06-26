#ifndef BATTLE_STATE_H_
#define BATTLE_STATE_H_

#include <pokeagb/pokeagb.h>
#include "moves/moves.h"
#include "battle_data/pkmn_bank.h"

#define GAME_STATE super.multi_purpose_state_tracker
typedef void (*ResidualEffectCallback)(u8);

enum Effect
{
    EFFECT_NONE,
    EFFECT_PARALYZE,
    EFFECT_SLEEP,
    EFFECT_BURN,
    EFFECT_FREEZE,
    EFFECT_POISON,
    EFFECT_BAD_POISON,
    EFFECT_CONFUSION,
    EFFECT_TOXIC_SPIKES,
    EFFECT_SANDSTORM,
};

struct battle_selection_cursor {
    u8 objid;
    u8 objid_mv_crsr[2];
    u8 cursor_pos; // 0-3
    u8 cursor_x[6];
    u8 cursor_y[6];
    
};

struct global_message {
    u16 move_id;
    u8 bank;
    u8 string_id;
    u16 effect;   
};

struct battle_field_state {
    u32 is_raining : 1;
    u32 is_sunny : 1;
    u32 is_sandstorm : 1;
    u32 is_hail : 1;
    u32 is_desolate_land : 1;
    u32 is_primordial_sea : 1;
    u32 is_delta_stream : 1;
    u32 suppress_weather : 1;
    u32 is_tailwind : 2; // side
    u32 is_gravity : 1;
    u32 is_ion_deluge : 1;
    u32 electric_terrain : 1;
    u32 grassy_terrain : 1;
    u32 misty_terrain : 1;
    u32 psychic_terrain : 1;
    u32 aura_break : 1;
    u32 fairy_aura : 1;
    u32 dark_aura : 1;
    u32 quick_guard : 2; // side
    u8 aurora_veil_turns[2];
    u8 tailwind_turns[2];
    u8 reflect_turns[2];
    u8 safe_guard_turns[2];
    u8 lightscreen_turns[2];
    u8 weather_turns;
    
};

struct move_used {
    u8 user_bank;
    u16 move_id;
    s8 priority;
    u8 stab;
    s8 power;
    u8 category;
    u8 type[2];
    u8 flinch;
    u8 accuracy; // over 100 = never miss
    
    u8 remove_contact : 1;
    u8 copied : 1;
    u8 ignore_abilities : 1;
    u8 prankstered : 1;
    u8 infiltrates : 1;
    
    u8 chance_self;
    u8 chance_target;
    u8 stat_self[6];
    u8 stat_target[6];
    s8 amount_self[6];
    s8 amount_target[6];
    u8 secondary_status[2];
    u8 secondary_status_chance[2];
    u16 after_dmg;
};




typedef u16 (*StatModifierCallback)(u16 stat, u8 id, u8 bank);

struct battle_main {
    struct battle_field_state field_state;
    
    /* Object ids and positions */
    struct battle_selection_cursor battle_cursor;
    u8 selected_option;
    u8 type_objid[4];
    u8 move_name_objid[4];
    u8 move_pss_objid[4];
    u8 move_pp_objid[4];
    u8 fight_menu_content_spawned;
    
    /* Message system variables */
    struct global_message b_message[5]; // message queue depth is 5
    u8 queue_size;
    u8 queue_front_index;
    u8 state;
    SuperCallback c1;
    
    /* Battle turn order variables */
    u8 first_bank;
    u8 second_bank;
    u8 execution_index;
    struct move_used b_moves[2];

    /* Battle details */
    u16 damage_to_deal;
    u16 amount_to_heal;
    enum Effect effect[2];
};

enum fight_menu {
    OPTION_FIGHT,
    OPTION_POKEMON,
    OPTION_BAG,
    OPTION_RUN
};



extern struct battle_main* battle_master;
extern u8 bs_anim_status;
extern void play_bmessage(void);

#endif /* BATTLE_STATE_H_ */