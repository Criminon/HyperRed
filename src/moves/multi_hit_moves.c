#include <pokeagb/pokeagb.h>
#include "moves.h"

/* 
 * Moves that hit 2-5x:
 * Double Slap, Comet Punch, Fury Attack, Pin missle, Spike Cannon, Barrage, 
 * Fury swipes, Bone Rush, Arm thrust, Bullet seed, Icicle spear, Rock blast
 * Tail slap, Water Shuriken
 *
 * Moves that hit 2x:
 * Double Kick, Twineedle, Bonemerang, Double Hit, Dual chop, Gear Grind,
 *
 * Moves that hit 3x: 
 * Triple kick
 */

/* Basic proc format for moves like Bullet seed which hit 2-5 times */
struct move_procs basic_multihit_proc = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    2,              // Lower bound for multi hit
    5,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE},
    {0, 0},
    0
};

/* Basic proc format for moves like Double kick which hit only twice */
struct move_procs basic_doublehit_proc = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    2,              // Lower bound for multi hit
    2,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE},
    {0, 0},
    0
};

/* Triple kick hit's 3 times */
struct move_procs basic_triplehit_proc = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    3,              // Lower bound for multi hit
    3,               // Upper bound for multi hit
    {AILMENT_NONE, AILMENT_NONE},
    {0, 0},
    0
};

// Twineedle exception. Chance to Poison 20%.
struct move_procs twineedle_procs = {
    0,              // Chance to boost self, 0-100
    0,              // Chance to boost opponent, 0-100
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost self
    {STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE, STAT_NONE},  // Stat to boost opponent
    {0, 0, 0, 0, 0, 0},  // Amount to boost self on proc (signed)
    {0, 0, 0, 0, 0, 0},  // Amount to boost opponent on proc (signed)
    2,              // Lower bound for multi hit
    2,               // Upper bound for multi hit
    {AILMENT_POISON, AILMENT_NONE},
    {20, 0},
    0
};

