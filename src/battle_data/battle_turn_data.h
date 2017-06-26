/* #ifndef BATTLE_TURN_DATA_PKMN
#define BATTLE_TURN_DATA_PKMN

#include <pokeagb/pokeagb.h>

// executed right before using a move. bm_cb(user_bank)
typedef void (*BeforeMoveCallback)(u8);
typedef void (*DamageCallback)(u8, u8);

enum BuffTags {
    ASSURANCE_TAG = (1 << 0), 
    BEAKBLAST_TAG = (1 << 1),
    COUNTER_TAG = (1 << 2),
    FOCUS_PUNCH_TAG = (1 << 3),
    METAL_BURST_TAG = (1 << 4),
    MIRROR_COAT_TAG = (1 << 5),
    PURSUIT_TAG = (1 << 6),
    SHELLTRAP_TAG = (1 << 7),
    ATTRACT_TAG = (1 << 8),
    BIDE_TAG = (1 << 9),
    DESTINY_BOND_TAG = (1 << 10),
    DISABLE_TAG = (1 << 11),
    GRUDGE_TAG = (1 << 12),
    HEAL_BLOCK_TAG = (1 << 13),
    IMPRISON_TAG = (1 << 14),
    RAGE_TAG = (1 << 15),
    SKY_DROP_TAG = (1 << 16),
    TAUNT_TAG = (1 << 17),
    THROAT_CHOP_TAG = (1 << 18),
    ELECTRIFY_TAG = (1 << 19),
    CURSE_TAG = (1 << 20),
};

enum TypeBits {
    TYPE_BITS_NORMAL = (1 << 0),
    TYPE_BITS_FIGHTING = (1 << 1),
    TYPE_BITS_FLYING = (1 << 2),
    TYPE_BITS_POISON = (1 << 3),
    TYPE_BITS_GROUND = (1 << 4),
    TYPE_BITS_ROCK = (1 << 5),
    TYPE_BITS_BUG = (1 << 6),
    TYPE_BITS_GHOST = (1 << 7),
    TYPE_BITS_STEEL = (1 << 8),
    TYPE_BITS_FIRE = (1 << 9),
    TYPE_BITS_WATER = (1 << 10),
    TYPE_BITS_GRASS = (1 << 11),
    TYPE_BITS_ELECTRIC = (1 << 12),
    TYPE_BITS_PSYCHIC = (1 << 13),
    TYPE_BITS_ICE = (1 << 14),
    TYPE_BITS_DRAGON = (1 << 15),
    TYPE_BITS_DARK = (1 << 16),
};

struct user_turn_action {
    u16 move_id;
    u8 target_bank;
    s8 priority;
    s8 speed;
    
    u8 is_running : 1;
    u8 using_item : 1;
    u8 is_switching : 1;
    u8 skip_move_select : 1;
    u8 used_protect : 1;
    u8 used_endure : 1;
    u8 crafty_shield : 1;
    u8 foresighted : 1;
    u8 locked_on : 1;
    u8 kings_sheild : 1;
    u8 not_first_turn : 1;
    u8 has_substitute : 1;
    u8 double_dmg : 1;
    u8 charge_turn : 1; // single turn chargeup i.e solarbeam
    u8 frz_shock_mod_move_cb_used : 1;
    
    u16 semi_invulnerable_move_id;
    
    u8 times_protected;
    u16 substitute_hp;
    
    u8 crit_mod;
    u16 item_to_use;
    u16 item_id;
    u8 switching_slot;
    u8 ability;
    u8 type[2];
    u16 removed_immunities;
    enum BuffTags buff_tag;
    BeforeMoveCallback bmc[19];
    DamageCallback bdc[5];
    u8 delta_stats[7]; // atk, def, spd, spa, spdf, evasion, accuracy 
    
    u8 attracted_by_bank;
    u8 imprisoned_by_bank;
    u8 charging_move_counter;
    u8 turns_disabled;
    u8 heal_block_turns;
    u16 total_dmg_taken;
    u16 special_dmg_taken;
    u16 physical_dmg_taken;
    u8 stockpile_stacks;
    u8 confusion_turns;
};
*/
//#endif /* BATTLE_TURN_DATA_PKMN */

 