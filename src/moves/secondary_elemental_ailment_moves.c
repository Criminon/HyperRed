#include <pokeagb/pokeagb.h>
#include "moves.h"


/* 10% chance to burn moves:
 *
 * Fire Punch, Ember, Flamethrower, Fire Blast, Flame wheel, Heatwave, Blaze kick,
 * Flare blitz,  
 */
struct move_procs sec_burn_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_BURN, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    0, // flinch chance
};


/* 10 chance to paralyze moves - Basic:
 *
 * Thunder Punch, Thunder Shock, Thunderbolt, Volt tackle
 */
 struct move_procs sec_para_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_PARALYZE, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    0, // flinch chance
};


/* 10% chance to Freeze moves - basic:
 *
 * Ice Punch, Ice Beam, Powder Snow, Freeze dry, Blizzard
 */
 struct move_procs sec_frz_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_FREEZE, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    0, // flinch chance
};

/* 10% chance to confuse moves - basic:
 *
 * Psybeam, Confusion, Signal beam, Psybeam
 */
  struct move_procs sec_cnfs_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_CONFUSION, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    0, // flinch chance
};








