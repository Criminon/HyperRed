#include <pokeagb/pokeagb.h>
#include "moves.h"


// Thunder Fang is an exception. Flinch + Para chance.
struct move_procs thunder_fang_procs = {
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
    10, // flinch chance
};

// Fire Fang is an exception. Flinch + Burn chance.
struct move_procs fire_fang_procs = {
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
    10, // flinch chance
};

// Ice Fang is an exception. Flinch + Frz chance.
struct move_procs ice_fang_procs = {
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
    10, // flinch chance
};
