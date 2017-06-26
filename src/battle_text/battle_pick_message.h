#ifndef BATTLE_PICK_MESSAGES_H_
#define BATTLE_PICK_MESSAGES_H_

#include <pokeagb/pokeagb.h>

enum battle_string_ids {
    STRING_ATTACK_USED, // 0 -2
    STRING_INFATUATED = 2,
    STRING_BIDE_CHARGE = 4,
    STRING_LOST_FOCUS = 6,
    STRING_CANT_USE = 8,
    STRING_DISABLED = 10,
    STRING_FAILED = 12,
    STRING_CURSE_RESIDUAL = 14,
    STRING_MAGNITUDE_AMOUNT = 16,
    STRING_NO_TARGET = 18,
    STRING_FAILED_ALONE = 20,
    STRING_IMMUNE_ABILITY = 21,
    STRING_RAZORWIND = 23,
    STRING_SOLARBEAM = 25,
    STRING_FREEZE_SHOCK = 27,
    STRING_ICE_BURN = 29,
    STRING_GOEMANCY = 31,
    STRING_SKULL_BASH = 33,
    STRING_RAINING = 35,
    STRING_GAINED_SPEED = 36,
    STRING_STURDY_IMMUNE = 38,
    STRING_DAMP_BLOCKED = 40,
    STRING_STATUS_CURED = 42,
    STRING_EFFECT_ENDED = 44,
    STRING_WEATHER_GONE = 46,
    STRING_GAINED_TYPE = 47,
    STRING_CONFUSION_ENDED = 49,
    STRING_DRAGGED_OUT_FAILED = 51,
    STRING_INTIMIDATE = 53,
    STRING_STAT_MOD_HARSH_DROP = 55,
    STRING_STAT_MOD_DROP = 57,
    STRING_STAT_MOD_HARSH_RISE = 59,
    STRING_STAT_MOD_RISE = 61,
    STRING_AILMENT_APPLIED = 63,
    STRING_AILMENT_IMMUNE = 65,
    STRING_AILMENT_CURED = 67,
    STRING_DELTA_STREAM = 69,
    STRING_DESOLATE_LAND = 70,
    STRING_PRIMORDIAL_SEA = 71,
    STRING_PROTEAN = 72,
    STRING_ABILITY_CHANGE = 74,
    STRING_ATTACK_MISSED = 76,
    STRING_ATTACK_AVOIDED = 77,
};


static const pchar str_atk_used_p[] = _("{ATTACKING_MON} used\n{ATTACK_NAME}!");
static const pchar str_atk_used_o[] = _("Foe {ATTACKING_MON} used\n{ATTACK_NAME}!");
static const pchar str_infatuated_p[] = _("{ATTACKING_MON} is in love\nwith Foe {DEFENDING_MON}\p{ATTACKING_MON}\nis immobolized by love!");
static const pchar str_infatuated_o[] = _("The opposing {ATTACKING_MON} is in love\nwith {DEFENDING_MON}\pThe opposing {ATTACKING_MON}\nis immobolized by love!");
static const pchar str_bide_p[] = _("{ATTACKING_MON} is charging up\n{ATTACK_NAME}!");
static const pchar str_bide_o[] = _("Foe {ATTACKING_MON} is charging up\n{ATTACK_NAME}!");
static const pchar str_focus_lost_p[] = _("{ATTACKING_MON} lost its\nfocus and couldn’t move!");
static const pchar str_focus_lost_o[] = _("Foe {ATTACKING_MON} lost its\nfocus and couldn’t move!");
static const pchar str_cant_use_p[] = _("{ATTACKING_MON} can’t use\n{ATTACK_NAME} because of {EFFECT_NAME}!");
static const pchar str_cant_use_o[] = _("Foe {ATTACKING_MON} can’t use\n{ATTACK_NAME} because of {EFFECT_NAME}!");
static const pchar str_disabled_p[] = _("{ATTACKING_MON}’s {ATTACK_NAME}\nwas disabled!");
static const pchar str_disabled_o[] = _("Foe {ATTACKING_MON}’s {ATTACK_NAME}\nwas disabled!");
static const pchar str_failed_p[] = _("But it failed!");
static const pchar str_failed_o[] = _("But it failed");
static const pchar str_curse_dmg_p[] = _("Foe {ATTACKING_MON} is afflicted\nby {ATTACK_NAME}");
static const pchar str_curse_dmg_o[] = _("{ATTACKING_MON} is afflicted\nby {ATTACK_NAME}");
static const pchar str_magnitude_amount_p[] = _("MAGNITUDE {EFFECT_NAME}!");
static const pchar str_magnitude_amount_o[] = _("MAGNITUDE {EFFECT_NAME}!");
static const pchar str_no_target_p[] = _("But there was no target!");
static const pchar str_no_target_o[] = _("But there was no target!");
static const pchar str_failed_alone[] = _("But it failed!");
static const pchar str_immunity_p[] = _("Foe {DEFENDING_MON}’s {ABILITY_NAME_OPPONENT}\nmade it immune!");
static const pchar str_immunity_o[] = _("{DEFENDING_MON}’s {ABILITY_NAME_PLAYER}\nmade it immune!");
static const pchar str_charging_up_razorwind_p[] = _("{ATTACKING_MON} whipped\nup a whirlwind!"); 
static const pchar str_charging_up_razorwind_o[] = _("Foe {DEFENDING_MON} whipped\nup a whirlwind!"); 
static const pchar str_solarbeam_p[] = _("{ATTACKING_MON} absorbed\nlight!");
static const pchar str_solarbeam_o[] = _("Foe {DEFENDING_MON} absorbed\nlight!");
static const pchar str_freeze_shock_p[] = _("{ATTACKING_MON} became cloaked\nin a freezing light!");
static const pchar str_freeze_shock_o[] = _("Foe {DEFENDING_MON} became cloaked\nin a freezing light!");
static const pchar str_ice_burn_p[] = _("{ATTACKING_MON} is radiating\na blazing aura!");
static const pchar str_ice_burn_o[] = _("Foe {DEFENDING_MON} is radiating\na blazing aura!");
static const pchar str_geomancy_p[] = _("{ATTACKING_MON} is absorbing\npower!");
static const pchar str_geomancy_o[] = _("Foe {DEFENDING_MON} is absorbing\npower!");
static const pchar str_skull_bash_p[] = _("{ATTACKING_MON} lowered\nits head!");
static const pchar str_skull_bash_o[] = _("Foe {DEFENDING_MON} lowered\nits head!");
static const pchar str_started_rain[] = _("It started to rain!");
static const pchar str_speed_up_p[] = _("{ATTACKING_MON}’s Speed rose!");
static const pchar str_speed_up_o[] = _("Foe {ATTACKING_MON}’s Speed rose!");
static const pchar str_sturdy_immune_p[] = _("{DEFENDING_MON}’s sturdy makes\nit immune to {ATTACK_NAME}!");
static const pchar str_sturdy_immune_o[] = _("Foe {DEFENDING_MON}’s sturdy makes\nit immune to {ATTACK_NAME}!");
static const pchar str_damp_p[] = _("{ATTACKING_MON} can’t use\n{ATTACK_NAME} because of {DEFENDING_MON}’s DAMP!");
static const pchar str_damp_o[] = _("Foe {ATTACKING_MON} couldn’t use\n{ATTACK_NAME} because of {DEFENDING_MON}’s DAMP!");
static const pchar str_cure_status_p[] = _("{ATTACKING_MON}’s status\nwas cured!");
static const pchar str_cure_status_o[] = _("Foe {ATTACKING_MON}’s cured\nits status!");
static const pchar str_effect_ended_p[] = _("{ATTACKING_MON}’s {ATTACK_NAME} ended.");
static const pchar str_effect_ended_o[] = _("Foe {ATTACKING_MON}’s\n{ATTACK_NAME} ended.");
static const pchar str_weather_gone[] = _("The effects of the weather\ndisappeared.");
static const pchar str_gained_type_p[] = _("{ATTACKING_MON} gained {TYPE}\nfrom {ABILITY_NAME_PLAYER}!");
static const pchar str_gained_type_o[] = _("Foe {ATTACKING_MON} gained {TYPE}\nfrom {ABILITY_NAME_OPPONENT}!");
static const pchar str_confusion_end_p[] = _("{ATTACKING_MON} is\nno longer confused!");
static const pchar str_confusion_end_o[] = _("Foe {ATTACKING_MON} is\nno longer confused!");
static const pchar str_dragout_failed_p[] = _("{ATTACKING_MON} couldn’t be\ndragged out of battle!");
static const pchar str_dragout_failed_o[] = _("Foe {ATTACKING_MON} couldn’t be\ndragged out of battle!");
static const pchar str_intimidate_p[] = _("{ATTACKING_MON} is immune\nto Intimidate.");
static const pchar str_intimidate_o[] = _("Foe {ATTACKING_MON} is immune\nto Intimidate.");
static const pchar str_stat_mod_harsh_drop_p[] = _("{ATTACKING_MON}’s {STAT_NAME}\ndropped harshly!");
static const pchar str_stat_mod_harsh_drop_o[] = _("Foe {ATTACKING_MON}’s {STAT_NAME}\ndropped harshly!");
static const pchar str_stat_mod_drop_p[] = _("{ATTACKING_MON}’s {STAT_NAME}\ndropped!");
static const pchar str_stat_mod_drop_o[] = _("Foe {ATTACKING_MON}’s {STAT_NAME}\ndropped!");
static const pchar str_stat_mod_harsh_rise_p[] = _("{ATTACKING_MON}’s {STAT_NAME}\nharshly rose!");
static const pchar str_stat_mod_harsh_rise_o[] = _("Foe {ATTACKING_MON}’s {STAT_NAME}\nharshly rose!");
static const pchar str_stat_mod_rise_p[] = _("{ATTACKING_MON}’s {STAT_NAME}\nrose!");
static const pchar str_stat_mod_rise_o[] = _("Foe {ATTACKING_MON}’s {STAT_NAME}\nrose!");
static const pchar str_ailment_applied_p[] = _("{ATTACKING_MON} was {STATUS_NAME}!");
static const pchar str_ailment_applied_o[] = _("Foe {ATTACKING_MON} was {STATUS_NAME}!");
static const pchar str_ailment_immune_p[] = _("{ATTACKING_MON} was immune\nto being {STATUS_NAME}!");
static const pchar str_ailment_immune_o[] = _("Foe {ATTACKING_MON} was immune\n to being {STATUS_NAME}!");
static const pchar str_ailment_cured_p[] = _("{ATTACKING_MON} was cured\nof all status ailments!");
static const pchar str_ailment_cured_o[] = _("Foe {ATTACKING_MON} was cured\nof all status ailments!");
static const pchar str_delta_stream[] = _("A mysterious air current\nis protecting Flying-type Pokémon!");
static const pchar str_desolate_land[] = _("The sunlight turned\nextremely harsh!");
static const pchar str_primordial_sea[] = _("A heavy rain began to fall!");
static const pchar str_protean_p[] = _("{ATTACKING_MON}’s Protean changed\nit’s type!");
static const pchar str_protean_o[] = _("Foe {ATTACKING_MON}’s Protean changed\nit’s type!");
static const pchar str_ability_change_p[] = _("{DEFENDING_MON}’s Mummy changed\n{ATTACKING_MON}’s ability to Mummy!");
static const pchar str_ability_change_o[] = _("Foe {DEFENDING_MON}’s Mummy changed\n{ATTACKING_MON}’s ability to Mummy!");
static const pchar str_atk_missed[] = _("The attack missed!");
static const pchar str_atk_avoided[] = _("{DEFENDING_MON} avoided the attack!");


// stat names
static const pchar str_stat_atk[] = _("attack");
static const pchar str_stat_def[] = _("defense");
static const pchar str_stat_spd[] = _("speed");
static const pchar str_stat_spatk[] = _("special attack");
static const pchar str_stat_spdef[] = _("special defense");
static const pchar str_stat_acc[] = _("accuracy");
static const pchar str_stat_evn[] = _("evasion");
static const pchar str_stat_crit[] = _("critical chance");

// status names
static const pchar str_status_paralyze[] = _("paralyzed");
static const pchar str_status_burn[] = _("burned");
static const pchar str_status_poison[] = _("poisoned");
static const pchar str_status_sleep[] = _("put asleep");
static const pchar str_status_frozen[] = _("frozen");
static const pchar str_status_bpoison[] = _("badly poisoned");
static const pchar str_status_confuse[] = _("confused");


static const pchar* battle_strings[78] = {
   (pchar*)&str_atk_used_p, (pchar*)&str_atk_used_o,
   (pchar*)&str_infatuated_p, (pchar*)&str_infatuated_o,
   (pchar*)&str_bide_p, (pchar*)&str_bide_o,
   (pchar*)&str_focus_lost_p, (pchar*)&str_focus_lost_o,
   (pchar*)&str_cant_use_p, (pchar*)&str_cant_use_p,
   (pchar*)&str_disabled_p, (pchar*)&str_disabled_p,
   (pchar*)&str_failed_p, (pchar*)&str_failed_p,
   (pchar*)&str_curse_dmg_p, (pchar*)&str_curse_dmg_o,
   (pchar*)&str_magnitude_amount_p, (pchar*)str_magnitude_amount_o,
   (pchar*)&str_no_target_p, (pchar*)&str_no_target_o,
   (pchar*)&str_failed_alone, (pchar*)&str_immunity_p,
   (pchar*)&str_immunity_o, (pchar*)&str_charging_up_razorwind_p,
   (pchar*)&str_charging_up_razorwind_o, (pchar*)&str_solarbeam_p,
   (pchar*)&str_solarbeam_o, (pchar*)&str_freeze_shock_p,
   (pchar*)&str_freeze_shock_o, (pchar*)&str_ice_burn_p, // 30
   (pchar*)&str_ice_burn_o, (pchar*)&str_geomancy_p,
   (pchar*)&str_geomancy_o, (pchar*)&str_skull_bash_p,
   (pchar*)&str_skull_bash_o, (pchar*)str_started_rain,
   (pchar*)&str_speed_up_p, (pchar*)&str_speed_up_o,
   (pchar*)&str_sturdy_immune_p,(pchar*)&str_sturdy_immune_o,
   (pchar*)&str_damp_p, (pchar*)&str_damp_o,
   (pchar*)&str_cure_status_p, (pchar*)&str_cure_status_o,
   (pchar*)&str_effect_ended_p, (pchar*)&str_effect_ended_o,
   (pchar*)&str_weather_gone,
   (pchar*)&str_gained_type_p, (pchar*)&str_gained_type_o,
   (pchar*)&str_confusion_end_p, (pchar*)&str_confusion_end_o,
   (pchar*)&str_dragout_failed_p, (pchar*)&str_dragout_failed_o,
   (pchar*)&str_intimidate_p, (pchar*)&str_intimidate_o,
   (pchar*)&str_stat_mod_harsh_drop_p, (pchar*)&str_stat_mod_harsh_drop_o,
   (pchar*)&str_stat_mod_drop_p, (pchar*)&str_stat_mod_drop_o,
   (pchar*)&str_stat_mod_harsh_rise_p, (pchar*)&str_stat_mod_harsh_rise_o,
   (pchar*)&str_stat_mod_rise_p, (pchar*)&str_stat_mod_rise_o,
   (pchar*)&str_ailment_applied_p, (pchar*)&str_ailment_applied_o,
   (pchar*)&str_ailment_immune_p, (pchar*)&str_ailment_immune_o,
   (pchar*)&str_ailment_cured_p, (pchar*)&str_ailment_cured_o,
   (pchar*)&str_delta_stream, (pchar*)&str_desolate_land,
   (pchar*)&str_primordial_sea,
   (pchar*)&str_protean_p, (pchar*)&str_protean_o,
   (pchar*)&str_ability_change_p, (pchar*)&str_ability_change_o,
   (pchar*)&str_atk_missed, (pchar*)&str_atk_avoided,
};


#endif /* BATTLE_PICK_MESSAGES_H_ */
