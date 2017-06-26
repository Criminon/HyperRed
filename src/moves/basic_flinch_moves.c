#include <pokeagb/pokeagb.h>
#include "moves.h"

/* Move callbacks */

u8 snore_tryhit(u8 user_bank)
{
    // sleep talk tryhit clone
   // extern u8 sleep_talk_tryhit(u8 bank);
   // return sleep_talk_tryhit(user_bank);
   return 0;
}


/* Move procs */

/* 10% flinch basic moves
 *
 * Hyper fang, Extrasensory, 
 */
 struct move_procs basic_flinch10_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    10, // flinch chance
};

/* 20% flinch basic moves
 *
 * Waterfall, Twister, Dark pulse, Dragon Rush, Zen Headbutt, 
 */
struct move_procs basic_flinch20_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    20, // flinch chance
};

/* 30% flinch basic moves
 *
 * Stomp, Rolling Kick, Headbutt, Bite, Rock slide, Snore, Needle Arm, Iron Head, Heart Stamp,
 * Astonish, Air slash, Streamroller, Icicle Crash, Zing Zap, 
 */
struct move_procs basic_flinch30_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    30, // flinch chance
};

// Fakeout
struct move_procs basic_flinch_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    0,              // Lower bound for multi hit
    0,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE}, // Ailment type
    {10, 0}, // Ailment chance
    100, // flinch chance
};

