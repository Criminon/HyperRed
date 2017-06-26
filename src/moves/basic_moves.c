#include <pokeagb/pokeagb.h>
#include "moves.h"

/* Basic proc format for moves like tackle */
struct move_procs basic_proc = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    1,              // Lower bound for multi hit
    1,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE},
    {0, 0},
    0
};



struct move_callbacks null_mcb = {
};

