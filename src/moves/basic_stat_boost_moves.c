#include <pokeagb/pokeagb.h>
#include "moves.h"

/* Attack stat boost by 1 stage
 *
 * Meditate, Sharpen, Howl, Power-up punch, 
 */
 struct move_procs basic_atk_stat_up_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_ATTACK, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {1, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};

/* Attack stat drop by 1 stage
 *
 * Growl, Play Nice, Babydoll eyes, Lunge, Trop Kick, 
 */
 struct move_procs basic_atk_stat_down_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_ATTACK, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {-1, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};

/* Def stat Up by 1 stage
 *
 * Harden, Withdraw, Defense Curl,   
 */
 struct move_procs basic_def_stat_up_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_DEFENSE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {1, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};

/* Def stat drop by 1 stage
 *
 * Tailwhip, Leer, Fire Lash
 */
 struct move_procs basic_def_stat_down_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_DEFENSE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {-1, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};

/* Attack stat up by 2 stage
 *
 * Swords dance
 */
 struct move_procs swords_dance_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_ATTACK, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {2, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};

/* Def stat down by 2 stages
 *
 * Screech
 */
 struct move_procs screech_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_DEFENSE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {-2, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};

/* Def stat up by 2 stages
 *
 * Barrier acid armor
 */
 struct move_procs def_upup_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_DEFENSE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {2, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};


/* Accuracy lowered 1 stage
 *
 * Sand attack, Smokescreen, Kinesis, Flash, Mud slap, 
 */
 struct move_procs acc_down_procs = {
    100,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_ACCURACY, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {-1, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {0, 0}, // Ailment chance
    0, // flinch chance
};


