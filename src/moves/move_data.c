#include <pokeagb/pokeagb.h>
#include "moves.h"
#include "../items/items.h"


pchar Pound_desc[] = _("No additional effect.");
pchar Karate_Chop_desc[] = _("High critical hit ratio.");
pchar Double_Slap_desc[] = _("Hits 2-5 times in one turn.");
pchar Comet_Punch_desc[] = _("Hits 2-5 times in one turn.");
pchar Mega_Punch_desc[] = _("No additional effect.");
pchar Pay_Day_desc[] = _("Scatters coins.");
pchar Fire_Punch_desc[] = _("10% chance to burn the target.");
pchar Ice_Punch_desc[] = _("10% chance to freeze the target.");
pchar Thunder_Punch_desc[] = _("10% chance to paralyze the target.");
pchar Scratch_desc[] = _("No additional effect.");
pchar Vice_Grip_desc[] = _("No additional effect.");
pchar Guillotine_desc[] = _("OHKOs the target. Fails if user is a lower level.");
pchar Razor_Wind_desc[] = _("Charges then hits foe(s) turn 2. High crit ratio.");
pchar Swords_Dance_desc[] = _("Raises the user‘s Attack by 2.");
pchar Cut_desc[] = _("No additional effect.");
pchar Gust_desc[] = _("Power doubles during Fly Bounce and Sky Drop.");
pchar Wing_Attack_desc[] = _("No additional effect.");
pchar Whirlwind_desc[] = _("Forces the target to switch to a random ally.");
pchar Fly_desc[] = _("Flies up on first turn then strikes the next turn.");
pchar Bind_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Slam_desc[] = _("No additional effect.");
pchar Vine_Whip_desc[] = _("No additional effect.");
pchar Stomp_desc[] = _("30% chance to flinch the target.");
pchar Double_Kick_desc[] = _("Hits 2 times in one turn.");
pchar Mega_Kick_desc[] = _("No additional effect.");
pchar Jump_Kick_desc[] = _("User is hurt by 50% of its max HP if it misses.");
pchar Rolling_Kick_desc[] = _("30% chance to flinch the target.");
pchar Sand_Attack_desc[] = _("Lowers the target‘s accuracy by 1.");
pchar Headbutt_desc[] = _("30% chance to flinch the target.");
pchar Horn_Attack_desc[] = _("No additional effect.");
pchar Fury_Attack_desc[] = _("Hits 2-5 times in one turn.");
pchar Horn_Drill_desc[] = _("OHKOs the target. Fails if user is a lower level.");
pchar Tackle_desc[] = _("No additional effect.");
pchar Body_Slam_desc[] = _("30% chance to paralyze the target.");
pchar Wrap_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Take_Down_desc[] = _("Has 1/4 recoil.");
pchar Thrash_desc[] = _("Lasts 2-3 turns. Confuses the user afterwards.");
pchar Double_Edge_desc[] = _("Has 33% recoil.");
pchar Tail_Whip_desc[] = _("Lowers the foe(s) Defense by 1.");
pchar Poison_Sting_desc[] = _("30% chance to poison the target.");
pchar Twineedle_desc[] = _("Hits 2 times. Each hit has 20% chance to poison.");
pchar Pin_Missile_desc[] = _("Hits 2-5 times in one turn.");
pchar Leer_desc[] = _("Lowers the foe(s) Defense by 1.");
pchar Bite_desc[] = _("30% chance to flinch the target.");
pchar Growl_desc[] = _("Lowers the foe(s) Attack by 1.");
pchar Roar_desc[] = _("Forces the target to switch to a random ally.");
pchar Sing_desc[] = _("Puts the target to sleep.");
pchar Supersonic_desc[] = _("Confuses the target.");
pchar Sonic_Boom_desc[] = _("Always does 20 HP of damage.");
pchar Disable_desc[] = _("For 4 turns disables the target‘s last move used.");
pchar Acid_desc[] = _("10% chance to lower the foe(s) Sp. Def by 1.");
pchar Ember_desc[] = _("10% chance to burn the target.");
pchar Flamethrower_desc[] = _("10% chance to burn the target.");
pchar Mist_desc[] = _("For 5 turns protects user‘s party from stat drops.");
pchar Water_Gun_desc[] = _("No additional effect.");
pchar Hydro_Pump_desc[] = _("No additional effect.");
pchar Surf_desc[] = _("Hits adjacent Pokemon. Power doubles on Dive.");
pchar Ice_Beam_desc[] = _("10% chance to freeze the target.");
pchar Blizzard_desc[] = _("10% chance to freeze the foe(s).");
pchar Psybeam_desc[] = _("10% chance to confuse the target.");
pchar Bubble_Beam_desc[] = _("10% chance to lower the target‘s Speed by 1.");
pchar Aurora_Beam_desc[] = _("10% chance to lower the foe‘s Attack by 1.");
pchar Hyper_Beam_desc[] = _("User cannot move next turn.");
pchar Peck_desc[] = _("No additional effect.");
pchar Drill_Peck_desc[] = _("No additional effect.");
pchar Submission_desc[] = _("Has 1/4 recoil.");
pchar Low_Kick_desc[] = _("More power the heavier the target.");
pchar Counter_desc[] = _("If hit by physical attack returns double damage.");
pchar Seismic_Toss_desc[] = _("Does damage equal to the user‘s level.");
pchar Strength_desc[] = _("No additional effect.");
pchar Absorb_desc[] = _("User recovers 50% of the damage dealt.");
pchar Mega_Drain_desc[] = _("User recovers 50% of the damage dealt.");
pchar Leech_Seed_desc[] = _("1/8 of target‘s HP is restored to user every turn.");
pchar Growth_desc[] = _("Raises user‘s Attack and SpAtk by 1, or 2 in Sun.");
pchar Razor_Leaf_desc[] = _("High critical hit ratio. Hits adjacent foes.");
pchar Solar_Beam_desc[] = _("Charges turn 1. Hits turn 2. No charge in sunlight.");
pchar Poison_Powder_desc[] = _("Poisons the target.");
pchar Stun_Spore_desc[] = _("Paralyzes the target.");
pchar Sleep_Powder_desc[] = _("Puts the target to sleep.");
pchar Petal_Dance_desc[] = _("Lasts 2-3 turns. Confuses the user afterwards.");
pchar String_Shot_desc[] = _("Lowers the foe(s) Speed by 2.");
pchar Dragon_Rage_desc[] = _("Always does 40 HP of damage.");
pchar Fire_Spin_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Thunder_Shock_desc[] = _("10% chance to paralyze the target.");
pchar Thunderbolt_desc[] = _("10% chance to paralyze the target.");
pchar Thunder_Wave_desc[] = _("Paralyzes the target.");
pchar Thunder_desc[] = _("30% chance to paralyze target. Can‘t miss in rain.");
pchar Rock_Throw_desc[] = _("No additional effect.");
pchar Earthquake_desc[] = _("Hits adjacent Pokemon. Power doubles on Dig.");
pchar Fissure_desc[] = _("OHKOs the target. Fails if user is a lower level.");
pchar Dig_desc[] = _("Digs underground turn 1 strikes turn 2.");
pchar Toxic_desc[] = _("Badly poisons the target.");
pchar Confusion_desc[] = _("10% chance to confuse the target.");
pchar Psychic_desc[] = _("10% chance to lower the target‘s Sp. Def by 1.");
pchar Hypnosis_desc[] = _("Puts the target to sleep.");
pchar Meditate_desc[] = _("Raises the user‘s Attack by 1.");
pchar Agility_desc[] = _("Raises the user‘s Speed by 2.");
pchar Quick_Attack_desc[] = _("Usually goes first.");
pchar Rage_desc[] = _("Raises the user‘s Attack by 1 if hit during use.");
pchar Teleport_desc[] = _("Flee from wild Pokemon battles.");
pchar Night_Shade_desc[] = _("Does damage equal to the user‘s level.");
pchar Mimic_desc[] = _("The last move the target used replaces this one.");
pchar Screech_desc[] = _("Lowers the target‘s Defense by 2.");
pchar Double_Team_desc[] = _("Raises the user‘s evasiveness by 1.");
pchar Recover_desc[] = _("Heals the user by 50% of its max HP.");
pchar Harden_desc[] = _("Raises the user‘s Defense by 1.");
pchar Minimize_desc[] = _("Raises the user‘s evasiveness by 2.");
pchar Smokescreen_desc[] = _("Lowers the target‘s accuracy by 1.");
pchar Confuse_Ray_desc[] = _("Confuses the target.");
pchar Withdraw_desc[] = _("Raises the user‘s Defense by 1.");
pchar Defense_Curl_desc[] = _("Raises the user‘s Defense by 1.");
pchar Barrier_desc[] = _("Raises the user‘s Defense by 2.");
pchar Light_Screen_desc[] = _("For 5 turns special damage to allies is halved.");
pchar Haze_desc[] = _("Eliminates all stat changes.");
pchar Reflect_desc[] = _("For 5 turns physical damage to allies is halved.");
pchar Focus_Energy_desc[] = _("Raises the user‘s critical hit ratio by 2.");
pchar Bide_desc[] = _("Waits 2 turns- deals double the damage taken.");
pchar Metronome_desc[] = _("Picks a random move.");
pchar Mirror_Move_desc[] = _("User uses the target‘s last used move against it.");
pchar Self_Destruct_desc[] = _("Hits adjacent Pokemon. The user faints.");
pchar Egg_Bomb_desc[] = _("No additional effect.");
pchar Lick_desc[] = _("30% chance to paralyze the target.");
pchar Smog_desc[] = _("40% chance to poison the target.");
pchar Sludge_desc[] = _("30% chance to poison the target.");
pchar Bone_Club_desc[] = _("10% chance to flinch the target.");
pchar Fire_Blast_desc[] = _("10% chance to burn the target.");
pchar Waterfall_desc[] = _("20% chance to flinch the target.");
pchar Clamp_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Swift_desc[] = _("This move does not check accuracy. Hits foes.");
pchar Skull_Bash_desc[] = _("Raises user‘s Defense by 1 on turn 1. Hits turn 2.");
pchar Spike_Cannon_desc[] = _("Hits 2-5 times in one turn.");
pchar Constrict_desc[] = _("10% chance to lower the target‘s Speed by 1.");
pchar Amnesia_desc[] = _("Raises the user‘s Sp. Def by 2.");
pchar Kinesis_desc[] = _("Lowers the target‘s accuracy by 1.");
pchar Soft_Boiled_desc[] = _("Heals the user by 50% of its max HP.");
pchar High_Jump_Kick_desc[] = _("User is hurt by 50% of its max HP if it misses.");
pchar Glare_desc[] = _("Paralyzes the target.");
pchar Dream_Eater_desc[] = _("User gains 1/2 HP inflicted. Sleeping target only.");
pchar Poison_Gas_desc[] = _("Poisons the foe(s).");
pchar Barrage_desc[] = _("Hits 2-5 times in one turn.");
pchar Leech_Life_desc[] = _("User recovers 50% of the damage dealt.");
pchar Lovely_Kiss_desc[] = _("Puts the target to sleep.");
pchar Sky_Attack_desc[] = _("Charges then hits turn 2. 30% flinch. High crit.");
pchar Transform_desc[] = _("Copies target‘s stats moves types and Ability.");
pchar Bubble_desc[] = _("10% chance to lower the foe(s) Speed by 1.");
pchar Dizzy_Punch_desc[] = _("20% chance to confuse the target.");
pchar Spore_desc[] = _("Puts the target to sleep.");
pchar Flash_desc[] = _("Lowers the target‘s accuracy by 1.");
pchar Psywave_desc[] = _("Random damage equal to 0.5x-1.5x user‘s level.");
pchar Splash_desc[] = _("Does nothing (but we still love it).");
pchar Acid_Armor_desc[] = _("Raises the user‘s Defense by 2.");
pchar Crabhammer_desc[] = _("High critical hit ratio.");
pchar Explosion_desc[] = _("Hits adjacent Pokemon. The user faints.");
pchar Fury_Swipes_desc[] = _("Hits 2-5 times in one turn.");
pchar Bonemerang_desc[] = _("Hits 2 times in one turn.");
pchar Rest_desc[] = _("User sleeps 2 turns and restores HP and status.");
pchar Rock_Slide_desc[] = _("30% chance to flinch the foe(s).");
pchar Hyper_Fang_desc[] = _("10% chance to flinch the target.");
pchar Sharpen_desc[] = _("Raises the user‘s Attack by 1.");
pchar Conversion_desc[] = _("Changes user‘s type to match its first move.");
pchar Tri_Attack_desc[] = _("20% chance to paralyze or burn or freeze target.");
pchar Super_Fang_desc[] = _("Does damage equal to 1/2 target‘s current HP.");
pchar Slash_desc[] = _("High critical hit ratio.");
pchar Substitute_desc[] = _("User takes 1/4 its max HP to put in a Substitute.");
pchar Struggle_desc[] = _("User loses 25% of its max HP as recoil.");
pchar Sketch_desc[] = _("Permanently copies the last move target used.");
pchar Triple_Kick_desc[] = _("Hits 3 times. Each hit can miss but power rises.");
pchar Thief_desc[] = _("If the user has no item it steals the target‘s.");
pchar Spider_Web_desc[] = _("The target cannot switch out.");
pchar Mind_Reader_desc[] = _("User‘s next move will not miss the target.");
pchar Nightmare_desc[] = _("A sleeping target is hurt by 1/4 max HP per turn.");
pchar Flame_Wheel_desc[] = _("10% chance to burn the target. Thaws user.");
pchar Snore_desc[] = _("User must be asleep. 30% chance to flinch target.");
pchar Curse_desc[] = _("Curses if Ghost else +1 Atk +1 Def -1 Spe.");
pchar Flail_desc[] = _("More power the less HP the user has left.");
pchar Conversion_2_desc[] = _("Changes user‘s type to resist target‘s last move.");
pchar Aeroblast_desc[] = _("High critical hit ratio.");
pchar Cotton_Spore_desc[] = _("Lowers the target‘s Speed by 2.");
pchar Reversal_desc[] = _("More power the less HP the user has left.");
pchar Spite_desc[] = _("Lowers the PP of the target‘s last move by 4.");
pchar Powder_Snow_desc[] = _("10% chance to freeze the foe(s).");
pchar Protect_desc[] = _("Prevents moves from affecting the user this turn.");
pchar Mach_Punch_desc[] = _("Usually goes first.");
pchar Scary_Face_desc[] = _("Lowers the target‘s Speed by 2.");
pchar Feint_Attack_desc[] = _("This move does not check accuracy.");
pchar Sweet_Kiss_desc[] = _("Confuses the target.");
pchar Belly_Drum_desc[] = _("User loses 50% max HP. Maximizes Attack.");
pchar Sludge_Bomb_desc[] = _("30% chance to poison the target.");
pchar Mud_Slap_desc[] = _("100% chance to lower the target‘s accuracy by 1.");
pchar Octazooka_desc[] = _("50% chance to lower the target‘s accuracy by 1.");
pchar Spikes_desc[] = _("Hurts grounded foes on switch-in. Max 3 layers.");
pchar Zap_Cannon_desc[] = _("100% chance to paralyze the target.");
pchar Foresight_desc[] = _("Fighting Normal hit Ghost. Evasiveness ignored.");
pchar Destiny_Bond_desc[] = _("If an opponent knocks out the user it also faints.");
pchar Perish_Song_desc[] = _("All active Pokemon will faint in 3 turns.");
pchar Icy_Wind_desc[] = _("100% chance to lower the foe(s) Speed by 1.");
pchar Detect_desc[] = _("Prevents moves from affecting the user this turn.");
pchar Bone_Rush_desc[] = _("Hits 2-5 times in one turn.");
pchar Lock_On_desc[] = _("User‘s next move will not miss the target.");
pchar Outrage_desc[] = _("Lasts 2-3 turns. Confuses the user afterwards.");
pchar Sandstorm_desc[] = _("For 5 turns a sandstorm rages.");
pchar Giga_Drain_desc[] = _("User recovers 50% of the damage dealt.");
pchar Endure_desc[] = _("The user survives the next hit with at least 1 HP.");
pchar Charm_desc[] = _("Lowers the target‘s Attack by 2.");
pchar Rollout_desc[] = _("Power doubles with each hit. Repeats for 5 turns.");
pchar False_Swipe_desc[] = _("Always leaves the target with at least 1 HP.");
pchar Swagger_desc[] = _("Raises the target‘s Attack by 2 and confuses it.");
pchar Milk_Drink_desc[] = _("Heals the user by 50% of its max HP.");
pchar Spark_desc[] = _("30% chance to paralyze the target.");
pchar Fury_Cutter_desc[] = _("Power doubles with each hit up to 160.");
pchar Steel_Wing_desc[] = _("10% chance to raise the user‘s Defense by 1.");
pchar Mean_Look_desc[] = _("The target cannot switch out.");
pchar Attract_desc[] = _("A target of the opposite gender gets infatuated.");
pchar Sleep_Talk_desc[] = _("User must be asleep. Uses another known move.");
pchar Heal_Bell_desc[] = _("Cures the user‘s party of all status conditions.");
pchar Return_desc[] = _("Max 102 power at maximum Happiness.");
pchar Present_desc[] = _("40 80 120 power or heals target by 1/4 max HP.");
pchar Frustration_desc[] = _("Max 102 power at minimum Happiness.");
pchar Safeguard_desc[] = _("For 5 turns protects user‘s party from status.");
pchar Pain_Split_desc[] = _("Shares HP of user and target equally.");
pchar Sacred_Fire_desc[] = _("50% chance to burn the target. Thaws user.");
pchar Magnitude_desc[] = _("Hits adjacent Pokemon. Power varies- 2x on Dig.");
pchar Dynamic_Punch_desc[] = _("100% chance to confuse the target.");
pchar Megahorn_desc[] = _("No additional effect.");
pchar Dragon_Breath_desc[] = _("30% chance to paralyze the target.");
pchar Baton_Pass_desc[] = _("User switches passing stat changes and more.");
pchar Encore_desc[] = _("The target repeats its last move for 3 turns.");
pchar Pursuit_desc[] = _("Power doubles if a foe is switching out.");
pchar Rapid_Spin_desc[] = _("Frees user from hazards/partial trap/Leech Seed.");
pchar Sweet_Scent_desc[] = _("Lowers the foe(s) evasion by 2.");
pchar Iron_Tail_desc[] = _("30% chance to lower the target‘s Defense by 1.");
pchar Metal_Claw_desc[] = _("10% chance to raise the user‘s Attack by 1.");
pchar Vital_Throw_desc[] = _("This move does not check accuracy. Goes last.");
pchar Morning_Sun_desc[] = _("Heals the user by a weather-dependent amount.");
pchar Synthesis_desc[] = _("Heals the user by a weather-dependent amount.");
pchar Moonlight_desc[] = _("Heals the user by a weather-dependent amount.");
pchar Hidden_Power_desc[] = _("Varies in type based on the user‘s IVs.");
pchar Cross_Chop_desc[] = _("High critical hit ratio.");
pchar Twister_desc[] = _("20% chance to flinch the foe(s).");
pchar Rain_Dance_desc[] = _("For 5 turns heavy rain powers Water moves.");
pchar Sunny_Day_desc[] = _("For 5 turns intense sunlight powers Fire moves.");
pchar Crunch_desc[] = _("20% chance to lower the target‘s Defense by 1.");
pchar Mirror_Coat_desc[] = _("If hit by special attack returns double damage.");
pchar Psych_Up_desc[] = _("Copies the target‘s current stat stages.");
pchar Extreme_Speed_desc[] = _("Nearly always goes first.");
pchar Ancient_Power_desc[] = _("10% chance to raise all stats by 1 (not acc/eva).");
pchar Shadow_Ball_desc[] = _("20% chance to lower the target‘s Sp. Def by 1.");
pchar Future_Sight_desc[] = _("Hits two turns after being used.");
pchar Rock_Smash_desc[] = _("50% chance to lower the target‘s Defense by 1.");
pchar Whirlpool_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Beat_Up_desc[] = _("All healthy allies aid in damaging the target.");
pchar Fake_Out_desc[] = _("Hits first. First turn out only. 100% flinch chance.");
pchar Uproar_desc[] = _("Lasts 3 turns. Active Pokemon cannot fall asleep.");
pchar Stockpile_desc[] = _("Raises user‘s Defense Sp. Def by 1. Max 3 uses.");
pchar Spit_Up_desc[] = _("More power with more uses of Stockpile.");
pchar Swallow_desc[] = _("Heals the user based on uses of Stockpile.");
pchar Heat_Wave_desc[] = _("10% chance to burn the foe(s).");
pchar Hail_desc[] = _("For 5 turns hail crashes down.");
pchar Torment_desc[] = _("Target can‘t select the same move twice in a row.");
pchar Flatter_desc[] = _("Raises the target‘s Sp. Atk by 1 and confuses it.");
pchar Will_O_Wisp_desc[] = _("Burns the target.");
pchar Memento_desc[] = _("Lowers target‘s Attack Sp. Atk by 2. User faints.");
pchar Facade_desc[] = _("Power doubles if user is burn/poison/paralyzed.");
pchar Focus_Punch_desc[] = _("Fails if the user takes damage before it hits.");
pchar Smelling_Salts_desc[] = _("Power doubles if target is paralyzed and cures it.");
pchar Follow_Me_desc[] = _("The foes‘ moves target the user on the turn used.");
pchar Nature_Power_desc[] = _("Attack depends on terrain (default Tri Attack).");
pchar Charge_desc[] = _("Boosts next Electric move and user‘s Sp. Def by 1.");
pchar Taunt_desc[] = _("For 3 turns the target can‘t use status moves.");
pchar Helping_Hand_desc[] = _("One adjacent ally‘s move power is 1.5x this turn.");
pchar Trick_desc[] = _("User switches its held item with the target‘s.");
pchar Role_Play_desc[] = _("User replaces its Ability with the target‘s.");
pchar Wish_desc[] = _("Next turn 50% of the user‘s max HP is restored.");
pchar Assist_desc[] = _("Uses a random move known by a team member.");
pchar Ingrain_desc[] = _("User recovers 1/16 max HP per turn. Traps user.");
pchar Superpower_desc[] = _("Lowers the user‘s Attack and Defense by 1.");
pchar Magic_Coat_desc[] = _("Bounces back certain non-damaging moves.");
pchar Recycle_desc[] = _("Restores the item the user last used.");
pchar Revenge_desc[] = _("Power doubles if user is damaged by the target.");
pchar Brick_Break_desc[] = _("Destroys screens unless the target is immune.");
pchar Yawn_desc[] = _("Puts the target to sleep after 1 turn.");
pchar Knock_Off_desc[] = _("1.5x damage if foe holds an item. Removes item.");
pchar Endeavor_desc[] = _("Lowers the target‘s HP to the user‘s HP.");
pchar Eruption_desc[] = _("Less power as user‘s HP decreases. Hits foe(s).");
pchar Skill_Swap_desc[] = _("The user and the target trade Abilities.");
pchar Imprison_desc[] = _("No foe can use any move known by the user.");
pchar Refresh_desc[] = _("User cures its burn poison or paralysis.");
pchar Grudge_desc[] = _("If the user faints the attack used loses all its PP.");
pchar Snatch_desc[] = _("User steals certain support moves to use itself.");
pchar Secret_Power_desc[] = _("Effect varies with terrain, 30% paralysis chance");
pchar Dive_desc[] = _("Dives underwater turn 1 strikes turn 2.");
pchar Arm_Thrust_desc[] = _("Hits 2-5 times in one turn.");
pchar Camouflage_desc[] = _("Changes user‘s type by terrain (default Normal).");
pchar Tail_Glow_desc[] = _("Raises the user‘s Sp. Atk by 3.");
pchar Luster_Purge_desc[] = _("50% chance to lower the target‘s Sp. Def by 1.");
pchar Mist_Ball_desc[] = _("50% chance to lower the target‘s Sp. Atk by 1.");
pchar Feather_Dance_desc[] = _("Lowers the target‘s Attack by 2.");
pchar Teeter_Dance_desc[] = _("Confuses adjacent Pokemon.");
pchar Blaze_Kick_desc[] = _("High critical hit ratio. 10% chance to burn.");
pchar Mud_Sport_desc[] = _("For 5 turns Electric-type attacks have 1/3 power.");
pchar Ice_Ball_desc[] = _("Power doubles with each hit. Repeats for 5 turns.");
pchar Needle_Arm_desc[] = _("30% chance to flinch the target.");
pchar Slack_Off_desc[] = _("Heals the user by 50% of its max HP.");
pchar Hyper_Voice_desc[] = _("No additional effect. Hits adjacent foes.");
pchar Poison_Fang_desc[] = _("50% chance to badly poison the target.");
pchar Crush_Claw_desc[] = _("50% chance to lower the target‘s Defense by 1.");
pchar Blast_Burn_desc[] = _("User cannot move next turn.");
pchar Hydro_Cannon_desc[] = _("User cannot move next turn.");
pchar Meteor_Mash_desc[] = _("20% chance to raise the user‘s Attack by 1.");
pchar Astonish_desc[] = _("30% chance to flinch the target.");
pchar Weather_Ball_desc[] = _("Power doubles and type varies in each weather.");
pchar Aromatherapy_desc[] = _("Cures the user‘s party of all status conditions.");
pchar Fake_Tears_desc[] = _("Lowers the target‘s Sp. Def by 2.");
pchar Air_Cutter_desc[] = _("High critical hit ratio. Hits adjacent foes.");
pchar Overheat_desc[] = _("Lowers the user‘s Sp. Atk by 2.");
pchar Odor_Sleuth_desc[] = _("Fighting Normal hit Ghost. Evasiveness ignored.");
pchar Rock_Tomb_desc[] = _("100% chance to lower the target‘s Speed by 1.");
pchar Silver_Wind_desc[] = _("10% chance to raise all stats by 1 (not acc/eva).");
pchar Metal_Sound_desc[] = _("Lowers the target‘s Sp. Def by 2.");
pchar Grass_Whistle_desc[] = _("Puts the target to sleep.");
pchar Tickle_desc[] = _("Lowers the target‘s Attack and Defense by 1.");
pchar Cosmic_Power_desc[] = _("Raises the user‘s Defense and Sp. Def by 1.");
pchar Water_Spout_desc[] = _("Less power as user‘s HP decreases. Hits foe(s).");
pchar Signal_Beam_desc[] = _("10% chance to confuse the target.");
pchar Shadow_Punch_desc[] = _("This move does not check accuracy.");
pchar Extrasensory_desc[] = _("10% chance to flinch the target.");
pchar Sky_Uppercut_desc[] = _("Can hit Pokemon using Bounce Fly or Sky Drop.");
pchar Sand_Tomb_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Sheer_Cold_desc[] = _("OHKOs non-Ice targets. Fails if user‘s lower level.");
pchar Muddy_Water_desc[] = _("30% chance to lower the foe(s) accuracy by 1.");
pchar Bullet_Seed_desc[] = _("Hits 2-5 times in one turn.");
pchar Aerial_Ace_desc[] = _("This move does not check accuracy.");
pchar Icicle_Spear_desc[] = _("Hits 2-5 times in one turn.");
pchar Iron_Defense_desc[] = _("Raises the user‘s Defense by 2.");
pchar Block_desc[] = _("The target cannot switch out.");
pchar Howl_desc[] = _("Raises the user‘s Attack by 1.");
pchar Dragon_Claw_desc[] = _("No additional effect.");
pchar Frenzy_Plant_desc[] = _("User cannot move next turn.");
pchar Bulk_Up_desc[] = _("Raises the user‘s Attack and Defense by 1.");
pchar Bounce_desc[] = _("Bounces turn 1. Hits turn 2. 30% paralyze.");
pchar Mud_Shot_desc[] = _("100% chance to lower the target‘s Speed by 1.");
pchar Poison_Tail_desc[] = _("High critical hit ratio. 10% chance to poison.");
pchar Covet_desc[] = _("If the user has no item it steals the target‘s.");
pchar Volt_Tackle_desc[] = _("Has 33% recoil. 10% chance to paralyze target.");
pchar Magical_Leaf_desc[] = _("This move does not check accuracy.");
pchar Water_Sport_desc[] = _("For 5 turns Fire-type attacks have 1/3 power.");
pchar Calm_Mind_desc[] = _("Raises the user‘s Sp. Atk and Sp. Def by 1.");
pchar Leaf_Blade_desc[] = _("High critical hit ratio.");
pchar Dragon_Dance_desc[] = _("Raises the user‘s Attack and Speed by 1.");
pchar Rock_Blast_desc[] = _("Hits 2-5 times in one turn.");
pchar Shock_Wave_desc[] = _("This move does not check accuracy.");
pchar Water_Pulse_desc[] = _("20% chance to confuse the target.");
pchar Doom_Desire_desc[] = _("Hits two turns after being used.");
pchar Psycho_Boost_desc[] = _("Lowers the user‘s Sp. Atk by 2.");
pchar Roost_desc[] = _("Heals 50% HP. Flying-type removed ‘til turn ends.");
pchar Gravity_desc[] = _("For 5 turns negates all Ground immunities.");
pchar Miracle_Eye_desc[] = _("Psychic hits Dark. Evasiveness ignored.");
pchar Wake_Up_Slap_desc[] = _("Power doubles if target is asleep and wakes it.");
pchar Hammer_Arm_desc[] = _("Lowers the user‘s Speed by 1.");
pchar Gyro_Ball_desc[] = _("More power the slower the user than the target.");
pchar Healing_Wish_desc[] = _("User faints. Replacement is fully healed.");
pchar Brine_desc[] = _("Power doubles if the target‘s HP is 50% or less.");
pchar Natural_Gift_desc[] = _("Power and type depends on the user‘s Berry.");
pchar Feint_desc[] = _("Nullifies Detect Protect and Quick/Wide Guard.");
pchar Pluck_desc[] = _("User steals and eats the target‘s Berry.");
pchar Tailwind_desc[] = _("For 4 turns allies‘ Speed is doubled.");
pchar Acupressure_desc[] = _("Raises a random stat of the user or an ally by 2.");
pchar Metal_Burst_desc[] = _("If hit by an attack returns 1.5x damage.");
pchar U_turn_desc[] = _("User switches out after damaging the target.");
pchar Close_Combat_desc[] = _("Lowers the user‘s Defense and Sp. Def by 1.");
pchar Payback_desc[] = _("Power doubles if the user moves after the target.");
pchar Assurance_desc[] = _("Power doubles if target was damaged this turn.");
pchar Embargo_desc[] = _("For 5 turns the target can‘t use any items.");
pchar Fling_desc[] = _("Flings the user‘s item at the target. Power varies.");
pchar Psycho_Shift_desc[] = _("Transfers the user‘s status ailment to the target.");
pchar Trump_Card_desc[] = _("More power the fewer PP this move has left.");
pchar Heal_Block_desc[] = _("For 5 turns the foe(s) is prevented from healing.");
pchar Wring_Out_desc[] = _("More power the more HP the target has left.");
pchar Power_Trick_desc[] = _("Switches user‘s Attack and Defense stats.");
pchar Gastro_Acid_desc[] = _("Nullifies the target‘s Ability.");
pchar Lucky_Chant_desc[] = _("For 5 turns shields user‘s party from critical hits.");
pchar Me_First_desc[] = _("Copies a foe at 1.5x power. User must be faster.");
pchar Copycat_desc[] = _("Uses the last move used in the battle.");
pchar Power_Swap_desc[] = _("Swaps Attack and Sp. Atk stat stages with target.");
pchar Guard_Swap_desc[] = _("Swaps Defense and Sp. Def changes with target.");
pchar Punishment_desc[] = _("60 power +20 for each of the target‘s stat boosts.");
pchar Last_Resort_desc[] = _("Fails unless each known move has been used.");
pchar Worry_Seed_desc[] = _("The target‘s Ability becomes Insomnia.");
pchar Sucker_Punch_desc[] = _("Usually goes first. Fails if target is not attacking.");
pchar Toxic_Spikes_desc[] = _("Poisons grounded foes on switch-in. Max 2 layers.");
pchar Heart_Swap_desc[] = _("Swaps all stat changes with target.");
pchar Aqua_Ring_desc[] = _("User recovers 1/16 max HP per turn.");
pchar Magnet_Rise_desc[] = _("For 5 turns the user is immune to Ground moves.");
pchar Flare_Blitz_desc[] = _("Has 33% recoil. 10% chance to burn. Thaws user.");
pchar Force_Palm_desc[] = _("30% chance to paralyze the target.");
pchar Aura_Sphere_desc[] = _("This move does not check accuracy.");
pchar Rock_Polish_desc[] = _("Raises the user‘s Speed by 2.");
pchar Poison_Jab_desc[] = _("30% chance to poison the target.");
pchar Dark_Pulse_desc[] = _("20% chance to flinch the target.");
pchar Night_Slash_desc[] = _("High critical hit ratio.");
pchar Aqua_Tail_desc[] = _("No additional effect.");
pchar Seed_Bomb_desc[] = _("No additional effect.");
pchar Air_Slash_desc[] = _("30% chance to flinch the target.");
pchar X_Scissor_desc[] = _("No additional effect.");
pchar Bug_Buzz_desc[] = _("10% chance to lower the target‘s Sp. Def. by 1.");
pchar Dragon_Pulse_desc[] = _("No additional effect.");
pchar Dragon_Rush_desc[] = _("20% chance to flinch the target.");
pchar Power_Gem_desc[] = _("No additional effect.");
pchar Drain_Punch_desc[] = _("User recovers 50% of the damage dealt.");
pchar Vacuum_Wave_desc[] = _("Usually goes first.");
pchar Focus_Blast_desc[] = _("10% chance to lower the target‘s Sp. Def by 1.");
pchar Energy_Ball_desc[] = _("10% chance to lower the target‘s Sp. Def. by 1.");
pchar Brave_Bird_desc[] = _("Has 33% recoil.");
pchar Earth_Power_desc[] = _("10% chance to lower the target‘s Sp. Def. by 1.");
pchar Switcheroo_desc[] = _("User switches its held item with the target‘s.");
pchar Giga_Impact_desc[] = _("User cannot move next turn.");
pchar Nasty_Plot_desc[] = _("Raises the user‘s Sp. Atk by 2.");
pchar Bullet_Punch_desc[] = _("Usually goes first.");
pchar Avalanche_desc[] = _("Power doubles if user is damaged by the target.");
pchar Ice_Shard_desc[] = _("Usually goes first.");
pchar Shadow_Claw_desc[] = _("High critical hit ratio.");
pchar Thunder_Fang_desc[] = _("10% chance to paralyze. 10% chance to flinch.");
pchar Ice_Fang_desc[] = _("10% chance to freeze. 10% chance to flinch.");
pchar Fire_Fang_desc[] = _("10% chance to burn. 10% chance to flinch.");
pchar Shadow_Sneak_desc[] = _("Usually goes first.");
pchar Mud_Bomb_desc[] = _("30% chance to lower the target‘s accuracy by 1.");
pchar Psycho_Cut_desc[] = _("High critical hit ratio.");
pchar Zen_Headbutt_desc[] = _("20% chance to flinch the target.");
pchar Mirror_Shot_desc[] = _("30% chance to lower the target‘s accuracy by 1.");
pchar Flash_Cannon_desc[] = _("10% chance to lower the target‘s Sp. Def by 1.");
pchar Rock_Climb_desc[] = _("20% chance to confuse the target.");
pchar Defog_desc[] = _("-1 evasion- clears user and target side‘s hazards.");
pchar Trick_Room_desc[] = _("For 5 turns slower Pokemon move first.");
pchar Draco_Meteor_desc[] = _("Lowers the user‘s Sp. Atk by 2.");
pchar Discharge_desc[] = _("30% chance to paralyze adjacent Pokemon.");
pchar Lava_Plume_desc[] = _("30% chance to burn adjacent Pokemon.");
pchar Leaf_Storm_desc[] = _("Lowers the user‘s Sp. Atk by 2.");
pchar Power_Whip_desc[] = _("No additional effect.");
pchar Rock_Wrecker_desc[] = _("User cannot move next turn.");
pchar Cross_Poison_desc[] = _("High critical hit ratio. 10% chance to poison.");
pchar Gunk_Shot_desc[] = _("30% chance to poison the target.");
pchar Iron_Head_desc[] = _("30% chance to flinch the target.");
pchar Magnet_Bomb_desc[] = _("This move does not check accuracy.");
pchar Stone_Edge_desc[] = _("High critical hit ratio.");
pchar Captivate_desc[] = _("Lowers the foe(s) Sp. Atk by 2 if opposite gender.");
pchar Stealth_Rock_desc[] = _("Hurts foes on switch-in. Factors Rock weakness.");
pchar Grass_Knot_desc[] = _("More power the heavier the target.");
pchar Chatter_desc[] = _("100% chance to confuse the target.");
pchar Judgment_desc[] = _("Type varies based on the held Plate.");
pchar Bug_Bite_desc[] = _("User steals and eats the target‘s Berry.");
pchar Charge_Beam_desc[] = _("70% chance to raise the user‘s Sp. Atk by 1.");
pchar Wood_Hammer_desc[] = _("Has 33% recoil.");
pchar Aqua_Jet_desc[] = _("Usually goes first.");
pchar Attack_Order_desc[] = _("High critical hit ratio.");
pchar Defend_Order_desc[] = _("Raises the user‘s Defense and Sp. Def by 1.");
pchar Heal_Order_desc[] = _("Heals the user by 50% of its max HP.");
pchar Head_Smash_desc[] = _("Has 1/2 recoil.");
pchar Double_Hit_desc[] = _("Hits 2 times in one turn.");
pchar Roar_of_Time_desc[] = _("User cannot move next turn.");
pchar Spacial_Rend_desc[] = _("High critical hit ratio.");
pchar Lunar_Dance_desc[] = _("User faints. Replacement is fully healed with PP.");
pchar Crush_Grip_desc[] = _("More power the more HP the target has left.");
pchar Magma_Storm_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Dark_Void_desc[] = _("Puts the foe(s) to sleep.");
pchar Seed_Flare_desc[] = _("40% chance to lower the target‘s Sp. Def by 2.");
pchar Ominous_Wind_desc[] = _("10% chance to raise all stats by 1 (not acc/eva).");
pchar Shadow_Force_desc[] = _("Disappears turn 1. Hits turn 2. Breaks protection.");
pchar Hone_Claws_desc[] = _("Raises the user‘s Attack and accuracy by 1.");
pchar Wide_Guard_desc[] = _("Protects allies from multi-target moves this turn.");
pchar Guard_Split_desc[] = _("Averages Defense and Sp. Def stats with target.");
pchar Power_Split_desc[] = _("Averages Attack and Sp. Atk stats with target.");
pchar Wonder_Room_desc[] = _("For 5 turns all Defense and Sp. Def stats switch.");
pchar Psyshock_desc[] = _("Damages target based on Defense not Sp. Def.");
pchar Venoshock_desc[] = _("Power doubles if the target is poisoned.");
pchar Autotomize_desc[] = _("Raises the user‘s Speed by 2- user loses 100 kg.");
pchar Rage_Powder_desc[] = _("The foes‘ moves target the user on the turn used.");
pchar Telekinesis_desc[] = _("For 3 turns target floats but moves can‘t miss it.");
pchar Magic_Room_desc[] = _("For 5 turns all held items have no effect.");
pchar Smack_Down_desc[] = _("Removes the target‘s Ground immunity.");
pchar Storm_Throw_desc[] = _("Always results in a critical hit.");
pchar Flame_Burst_desc[] = _("Damages Pokemon next to the target as well.");
pchar Sludge_Wave_desc[] = _("10% chance to poison adjacent Pokemon.");
pchar Quiver_Dance_desc[] = _("Raises the user‘s Sp. Atk Sp. Def Speed by 1.");
pchar Heavy_Slam_desc[] = _("More power the heavier the user than the target.");
pchar Synchronoise_desc[] = _("Hits adjacent Pokemon sharing the user‘s type.");
pchar Electro_Ball_desc[] = _("More power the faster the user is than the target.");
pchar Soak_desc[] = _("Changes the target‘s type to Water.");
pchar Flame_Charge_desc[] = _("100% chance to raise the user‘s Speed by 1.");
pchar Coil_desc[] = _("Raises user‘s Attack Defense and accuracy by 1.");
pchar Low_Sweep_desc[] = _("100% chance to lower the target‘s Speed by 1.");
pchar Acid_Spray_desc[] = _("100% chance to lower the target‘s Sp. Def by 2.");
pchar Foul_Play_desc[] = _("Uses target‘s Attack stat in damage calculation.");
pchar Simple_Beam_desc[] = _("The target‘s Ability becomes Simple.");
pchar Entrainment_desc[] = _("The target‘s Ability changes to match the user‘s.");
pchar After_You_desc[] = _("The target makes its move right after the user.");
pchar Round_desc[] = _("Power doubles if others used Round this turn.");
pchar Echoed_Voice_desc[] = _("Power increases when used on consecutive turns.");
pchar Chip_Away_desc[] = _("Ignores the target‘s stat stage changes.");
pchar Clear_Smog_desc[] = _("Eliminates the target‘s stat changes.");
pchar Stored_Power_desc[] = _(" + 20 power for each of the user‘s stat boosts.");
pchar Quick_Guard_desc[] = _("Protects allies from priority attacks this turn.");
pchar Ally_Switch_desc[] = _("The user swaps positions with its ally.");
pchar Scald_desc[] = _("30% chance to burn the target. Thaws target.");
pchar Shell_Smash_desc[] = _("Lowers Def SpD by 1- raises Atk SpA Spe by 2.");
pchar Heal_Pulse_desc[] = _("Heals the target by 50% of its max HP.");
pchar Hex_desc[] = _("Power doubles if the target has a status ailment.");
pchar Sky_Drop_desc[] = _("User and foe fly up turn 1. Damages on turn 2.");
pchar Shift_Gear_desc[] = _("Raises the user‘s Speed by 2 and Attack by 1.");
pchar Circle_Throw_desc[] = _("Forces the target to switch to a random ally.");
pchar Incinerate_desc[] = _("Destroys the foe(s) Berry/Gem.");
pchar Quash_desc[] = _("Forces the target to move last this turn.");
pchar Acrobatics_desc[] = _("Power doubles if the user has no held item.");
pchar Reflect_Type_desc[] = _("User becomes the same type as the target.");
pchar Retaliate_desc[] = _("Power doubles if an ally fainted last turn.");
pchar Final_Gambit_desc[] = _("Does damage equal to the user‘s HP. User faints.");
pchar Bestow_desc[] = _("User passes its held item to the target.");
pchar Inferno_desc[] = _("100% chance to burn the target.");
pchar Water_Pledge_desc[] = _("Use with Grass or Fire Pledge for added effect.");
pchar Fire_Pledge_desc[] = _("Use with Grass or Water Pledge for added effect.");
pchar Grass_Pledge_desc[] = _("Use with Fire or Water Pledge for added effect.");
pchar Volt_Switch_desc[] = _("User switches out after damaging the target.");
pchar Struggle_Bug_desc[] = _("100% chance to lower the foe(s) Sp. Atk by 1.");
pchar Bulldoze_desc[] = _("100% chance to lower adjacent Pkmn Speed by 1.");
pchar Frost_Breath_desc[] = _("Always results in a critical hit.");
pchar Dragon_Tail_desc[] = _("Forces the target to switch to a random ally.");
pchar Work_Up_desc[] = _("Raises the user‘s Attack and Sp. Atk by 1.");
pchar Electroweb_desc[] = _("100% chance to lower the foe(s) Speed by 1.");
pchar Wild_Charge_desc[] = _("Has 1/4 recoil.");
pchar Drill_Run_desc[] = _("High critical hit ratio.");
pchar Dual_Chop_desc[] = _("Hits 2 times in one turn.");
pchar Heart_Stamp_desc[] = _("30% chance to flinch the target.");
pchar Horn_Leech_desc[] = _("User recovers 50% of the damage dealt.");
pchar Sacred_Sword_desc[] = _("Ignores the target‘s stat stage changes.");
pchar Razor_Shell_desc[] = _("50% chance to lower the target‘s Defense by 1.");
pchar Heat_Crash_desc[] = _("More power the heavier the user than the target.");
pchar Leaf_Tornado_desc[] = _("50% chance to lower the target‘s accuracy by 1.");
pchar Steamroller_desc[] = _("30% chance to flinch the target.");
pchar Cotton_Guard_desc[] = _("Raises the user‘s Defense by 3.");
pchar Night_Daze_desc[] = _("40% chance to lower the target‘s accuracy by 1.");
pchar Psystrike_desc[] = _("Damages target based on Defense not Sp. Def.");
pchar Tail_Slap_desc[] = _("Hits 2-5 times in one turn.");
pchar Hurricane_desc[] = _("30% chance to confuse target. Can‘t miss in rain.");
pchar Head_Charge_desc[] = _("Has 1/4 recoil.");
pchar Gear_Grind_desc[] = _("Hits 2 times in one turn.");
pchar Searing_Shot_desc[] = _("30% chance to burn adjacent Pokemon.");
pchar Techno_Blast_desc[] = _("Type varies based on the held Drive.");
pchar Relic_Song_desc[] = _("10% chance to sleep foe(s). Meloetta transforms.");
pchar Secret_Sword_desc[] = _("Damages target based on Defense not Sp. Def.");
pchar Glaciate_desc[] = _("100% chance to lower the foe(s) Speed by 1.");
pchar Bolt_Strike_desc[] = _("20% chance to paralyze the target.");
pchar Blue_Flare_desc[] = _("20% chance to burn the target.");
pchar Fiery_Dance_desc[] = _("50% chance to raise the user‘s Sp. Atk by 1.");
pchar Freeze_Shock_desc[] = _("Charges turn 1. Hits turn 2. 30% paralyze.");
pchar Ice_Burn_desc[] = _("Charges turn 1. Hits turn 2. 30% burn.");
pchar Snarl_desc[] = _("100% chance to lower the foe(s) Sp. Atk by 1.");
pchar Icicle_Crash_desc[] = _("30% chance to flinch the target.");
pchar V_create_desc[] = _("Lowers the user‘s Defense Sp. Def Speed by 1.");
pchar Fusion_Flare_desc[] = _("Power doubles if used after Fusion Bolt.");
pchar Fusion_Bolt_desc[] = _("Power doubles if used after Fusion Flare.");
pchar Flying_Press_desc[] = _("Combines Flying in its type effectiveness.");
pchar Mat_Block_desc[] = _("Protects allies from attacks. First turn out only.");
pchar Belch_desc[] = _("Cannot be selected until the user eats a Berry.");
pchar Rototiller_desc[] = _("Raises Atk Sp. Atk of grounded Grass types by 1.");
pchar Sticky_Web_desc[] = _("Lowers Speed of grounded foes by 1 on switch-in.");
pchar Fell_Stinger_desc[] = _("Raises user‘s Attack by 3 if this KOes the target.");
pchar Phantom_Force_desc[] = _("Disappears turn 1. Hits turn 2. Breaks protection.");
pchar Trick_or_Treat_desc[] = _("Adds Ghost to the target‘s type(s).");
pchar Noble_Roar_desc[] = _("Lowers the target‘s Attack and Sp. Atk by 1.");
pchar Ion_Deluge_desc[] = _("Normal moves become Electric type this turn.");
pchar Parabolic_Charge_desc[] = _("User recovers 50% of the damage dealt.");
pchar Forests_Curse_desc[] = _("Adds Grass to the target‘s type(s).");
pchar Petal_Blizzard_desc[] = _("No additional effect. Hits adjacent Pokemon.");
pchar Freeze_Dry_desc[] = _("10% chance to freeze. Super effective on Water.");
pchar Disarming_Voice_desc[] = _("This move does not check accuracy. Hits foes.");
pchar Parting_Shot_desc[] = _("Lowers target‘s Atk Sp. Atk by 1. User switches.");
pchar Topsy_Turvy_desc[] = _("Inverts the target‘s stat stages.");
pchar Draining_Kiss_desc[] = _("User recovers 75% of the damage dealt.");
pchar Crafty_Shield_desc[] = _("Protects allies from Status moves this turn.");
pchar Flower_Shield_desc[] = _("Raises Defense by 1 of all active Grass types.");
pchar Grassy_Terrain_desc[] = _("5 turns. Grounded: +Grass power+1/16 max HP.");
pchar Misty_Terrain_desc[] = _("5 turns. Can‘t status-Dragon power vs grounded.");
pchar Electrify_desc[] = _("Changes the target‘s move to Electric this turn.");
pchar Play_Rough_desc[] = _("10% chance to lower the target‘s Attack by 1.");
pchar Fairy_Wind_desc[] = _("No additional effect.");
pchar Moonblast_desc[] = _("30% chance to lower the target‘s Sp. Atk by 1.");
pchar Boomburst_desc[] = _("No additional effect. Hits adjacent Pokemon.");
pchar Fairy_Lock_desc[] = _("Prevents all Pokemon from switching next turn.");
pchar Kings_Shield_desc[] = _("Protects from attacks. Contact: lowers Atk by 2.");
pchar Play_Nice_desc[] = _("Lowers the target‘s Attack by 1.");
pchar Confide_desc[] = _("Lowers the target‘s Sp. Atk by 1.");
pchar Diamond_Storm_desc[] = _("50% chance to raise user‘s Def by 2 for each hit.");
pchar Steam_Eruption_desc[] = _("30% chance to burn the target.");
pchar Hyperspace_Hole_desc[] = _("Breaks the target‘s protection for this turn.");
pchar Water_Shuriken_desc[] = _("Hits 2-5 times in one turn.");
pchar Mystical_Fire_desc[] = _("100% chance to lower the target‘s Sp. Atk by 1.");
pchar Spiky_Shield_desc[] = _("Protects from moves. Contact: loses 1/8 max HP.");
pchar Aromatic_Mist_desc[] = _("Raises an ally‘s Sp. Def by 1.");
pchar Eerie_Impulse_desc[] = _("Lowers the target‘s Sp. Atk by 2.");
pchar Venom_Drench_desc[] = _("Lowers Atk Sp. Atk Speed of poisoned foes by 1.");
pchar Powder_desc[] = _("If using a Fire move target loses 1/4 max HP.");
pchar Geomancy_desc[] = _("Charges then raises SpA SpD Spe by 2 turn 2.");
pchar Magnetic_Flux_desc[] = _("Raises Def Sp. Def of allies with Plus/Minus by 1.");
pchar Happy_Hour_desc[] = _("No competitive use.");
pchar Electric_Terrain_desc[] = _("5 turns. Grounded: +Electric power can‘t sleep.");
pchar Dazzling_Gleam_desc[] = _("No additional effect. Hits adjacent foes.");
pchar Celebrate_desc[] = _("No competitive use. Or any use.");
pchar Baby_Doll_Eyes_desc[] = _("Lowers the target‘s Attack by 1.");
pchar Nuzzle_desc[] = _("100% chance to paralyze the target.");
pchar Hold_Back_desc[] = _("Always leaves the target with at least 1 HP.");
pchar Infestation_desc[] = _("Traps and damages the target for 4-5 turns.");
pchar Power_Up_Punch_desc[] = _("100% chance to raise the user‘s Attack by 1.");
pchar Oblivion_Wing_desc[] = _("User recovers 75% of the damage dealt.");
pchar Thousand_Arrows_desc[] = _("Grounds adjacent foes. First hit neutral on Flying.");
pchar Thousand_Waves_desc[] = _("Hits adjacent foes. Prevents them from switching.");
pchar Hold_Hands_desc[] = _("No competitive use. Or any use.");
pchar Lands_Wrath_desc[] = _("No additional effect. Hits adjacent foes.");
pchar Light_of_Ruin_desc[] = _("Has 1/2 recoil.");
pchar Origin_Pulse_desc[] = _("No additional effect. Hits adjacent foes.");
pchar Precipice_Blades_desc[] = _("No additional effect. Hits adjacent Pokemon.");
pchar Dragon_Ascent_desc[] = _("Lowers the user‘s Defense and Sp. Def by 1.");
pchar Hyperspace_Fury_desc[] = _("Hoopa-U: Lowers user‘s Def by 1- breaks protection.");
pchar Shore_Up_desc[] = _("Heals the user by a weather-dependent amount.");
pchar First_Impression_desc[] = _("Hits first. First turn out only.");
pchar Baneful_Bunker_desc[] = _("Protects from moves. Contact: poison.");
pchar Spirit_Shackle_desc[] = _("Prevents the target from switching out.");
pchar Darkest_Lariat_desc[] = _("Ignores the target‘s stat stage changes.");
pchar Sparkling_Aria_desc[] = _("The target is cured of its burn.");
pchar Ice_Hammer_desc[] = _("Lowers the user‘s Speed by 1.");
pchar Floral_Healing_desc[] = _("Heals the target by 50% of its max HP.");
pchar High_Horsepower_desc[] = _("No additional effect.");
pchar Strength_Sap_desc[] = _("User heals HP=target‘s Atk stat. Lowers Atk by 1.");
pchar Solar_Blade_desc[] = _("Charges turn 1. Hits turn 2. No charge in sunlight.");
pchar Leafage_desc[] = _("No additional effect.");
pchar Spotlight_desc[] = _("Moves redirect to the target on the turn used.");
pchar Toxic_Thread_desc[] = _("Lowers the target‘s Speed by 1 and poisons it.");
pchar Laser_Focus_desc[] = _("Next turn the user‘s attack will be a critical hit.");
pchar Gear_Up_desc[] = _("Raises Atk Sp. Atk of allies with Plus/Minus by 1.");
pchar Throat_Chop_desc[] = _("For 2 turns the target cannot use sound moves.");
pchar Pollen_Puff_desc[] = _("If the target is an ally heals 50% of its max HP.");
pchar Anchor_Shot_desc[] = _("Prevents the target from switching out.");
pchar Psychic_Terrain_desc[] = _("5 turns. Grounded: +Psychic power priority-safe.");
pchar Lunge_desc[] = _("100% chance to lower the target‘s Attack by 1.");
pchar Fire_Lash_desc[] = _("100% chance to lower the target‘s Defense by 1.");
pchar Power_Trip_desc[] = _(" + 20 power for each of the user‘s stat boosts.");
pchar Burn_Up_desc[] = _("User‘s Fire-type is removed until it switches out.");
pchar Speed_Swap_desc[] = _("Swaps Speed stat with target.");
pchar Smart_Strike_desc[] = _("This move does not check accuracy.");
pchar Purify_desc[] = _("Cures target‘s status- heals user 1/2 maxHP if so.");
pchar Revelation_Dance_desc[] = _("Type varies based on the user‘s primary type.");
pchar Core_Enforcer_desc[] = _("Nullifies the foe(s) Ability if the target moves first.");
pchar Trop_Kick_desc[] = _("100% chance to lower the target‘s Attack by 1.");
pchar Instruct_desc[] = _("The target immediately uses its last used move.");
pchar Beak_Blast_desc[] = _("Burns on contact with the user before it moves.");
pchar Clanging_Scales_desc[] = _("Lowers the user‘s Defense by 1.");
pchar Dragon_Hammer_desc[] = _("No additional effect.");
pchar Brutal_Swing_desc[] = _("No additional effect. Hits adjacent Pokemon.");
pchar Aurora_Veil_desc[] = _("For 5 turns damage to allies is halved. Hail only.");
pchar Shell_Trap_desc[] = _("User must take physical damage before moving.");
pchar Fleur_Cannon_desc[] = _("Lowers the user‘s Sp. Atk by 2.");
pchar Psychic_Fangs_desc[] = _("Destroys screens unless the target is immune.");
pchar Stomping_Tantrum_desc[] = _("Power doubles if the user‘s last move failed.");
pchar Shadow_Bone_desc[] = _("20% chance to lower the target‘s Defense by 1.");
pchar Accelerock_desc[] = _("Usually goes first.");
pchar Liquidation_desc[] = _("20% chance to lower the target‘s Defense by 1.");
pchar Prismatic_Laser_desc[] = _("User cannot move next turn.");
pchar Spectral_Thief_desc[] = _("Steals target‘s boosts before dealing damage.");
pchar Sunsteel_Strike_desc[] = _("Ignores the Abilities of other Pokemon.");
pchar Moongeist_Beam_desc[] = _("Ignores the Abilities of other Pokemon.");
pchar Tearful_Look_desc[] = _("Lowers the target‘s Attack and Sp. Atk by 1.");
pchar Zing_Zap_desc[] = _("30% chance to flinch the target.");
pchar Natures_Madness_desc[] = _("Does damage equal to 1/2 target‘s current HP.");
pchar Multi_Attack_desc[] = _("Type varies based on the held Memory.");


u32 m_flags[672] = {
	/*POUND_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*KARATE_CHOP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DOUBLE_SLAP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*COMET_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MEGA_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*PAY_DAY_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FIRE_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ICE_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*THUNDER_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SCRATCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*VICE_GRIP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*GUILLOTINE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*RAZOR_WIND_FLAGS*/	FLAG_CHARGEUP | FLAG_HITS_ALL,
	/*SWORDS_DANCE_FLAGS*/	FLAG_SNATCH | FLAG_ONSELF,
	/*CUT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*GUST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WING_ATTACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*WHIRLWIND_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*FLY_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BIND_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SLAM_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*VINE_WHIP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*STOMP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DOUBLE_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MEGA_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*JUMP_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ROLLING_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SAND_ATTACK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*HEADBUTT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HORN_ATTACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FURY_ATTACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HORN_DRILL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TACKLE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BODY_SLAM_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*WRAP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TAKE_DOWN_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*THRASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DOUBLE-EDGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TAIL_WHIP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*POISON_STING_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TWINEEDLE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PIN_MISSILE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LEER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*BITE_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*GROWL_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*ROAR_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*SING_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*SUPERSONIC_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*SONIC_BOOM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*DISABLE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ACID_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_HITS_ALL,
	/*EMBER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLAMETHROWER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MIST_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*WATER_GUN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HYDRO_PUMP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SURF_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ICE_BEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BLIZZARD_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PSYBEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BUBBLE_BEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*AURORA_BEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HYPER_BEAM_FLAGS*/	FLAG_RECHARGE | FLAG_TARGET,
	/*PECK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DRILL_PECK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SUBMISSION_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*LOW_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*COUNTER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SEISMIC_TOSS_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*STRENGTH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ABSORB_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*MEGA_DRAIN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*LEECH_SEED_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*GROWTH_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*RAZOR_LEAF_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SOLAR_BEAM_FLAGS*/	FLAG_CHARGEUP | FLAG_TARGET,
	/*POISON_POWDER_FLAGS*/	FLAG_POWDER | FLAG_TARGET,
	/*STUN_SPORE_FLAGS*/	FLAG_POWDER | FLAG_TARGET,
	/*SLEEP_POWDER_FLAGS*/	FLAG_POWDER | FLAG_TARGET,
	/*PETAL_DANCE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*STRING_SHOT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAGON_RAGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FIRE_SPIN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*THUNDER_SHOCK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*THUNDERBOLT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*THUNDER_WAVE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*THUNDER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ROCK_THROW_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*EARTHQUAKE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FISSURE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DIG_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TOXIC_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CONFUSION_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PSYCHIC_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HYPNOSIS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MEDITATE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*AGILITY_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*QUICK_ATTACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*RAGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TELEPORT_FLAGS*/	FLAG_TARGET,
	/*NIGHT_SHADE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MIMIC_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SCREECH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DOUBLE_TEAM_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*RECOVER_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*HARDEN_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*MINIMIZE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*SMOKESCREEN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CONFUSE_RAY_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WITHDRAW_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*DEFENSE_CURL_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*BARRIER_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*LIGHT_SCREEN_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*HAZE_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*REFLECT_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*FOCUS_ENERGY_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*BIDE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*METRONOME_FLAGS*/	FLAG_TARGET,
	/*MIRROR_MOVE_FLAGS*/	FLAG_TARGET,
	/*SELF-DESTRUCT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*EGG_BOMB_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*LICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SMOG_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SLUDGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BONE_CLUB_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FIRE_BLAST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WATERFALL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*CLAMP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SWIFT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SKULL_BASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SPIKE_CANNON_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CONSTRICT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*AMNESIA_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*KINESIS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SOFT-BOILED_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*HIGH_JUMP_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*GLARE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DREAM_EATER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*POISON_GAS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BARRAGE_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*LEECH_LIFE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*LOVELY_KISS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SKY_ATTACK_FLAGS*/	FLAG_CHARGEUP | FLAG_TARGET,
	/*TRANSFORM*/	FLAG_TARGET,
	/*BUBBLE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DIZZY_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SPORE_FLAGS*/	FLAG_POWDER | FLAG_TARGET,
	/*FLASH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PSYWAVE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SPLASH_FLAGS*/	FLAG_GRAVITY_DISABLED | FLAG_TARGET,
	/*ACID_ARMOR_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*CRABHAMMER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*EXPLOSION_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FURY_SWIPES_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BONEMERANG_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*REST_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*ROCK_SLIDE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HYPER_FANG_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*SHARPEN_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*CONVERSION_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*TRI_ATTACK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SUPER_FANG_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SLASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SUBSTITUTE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*STRUGGLE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SKETCH_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*TRIPLE_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*THIEF_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SPIDER_WEB_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MIND_READER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*NIGHTMARE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLAME_WHEEL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SNORE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CURSE_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*FLAIL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*CONVERSION_2_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*AEROBLAST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*COTTON_SPORE_FLAGS*/	FLAG_POWDER | FLAG_TARGET,
	/*REVERSAL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SPITE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*POWDER_SNOW_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PROTECT_FLAGS*/	FLAG_TARGET,
	/*MACH_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SCARY_FACE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FEINT_ATTACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SWEET_KISS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BELLY_DRUM_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*SLUDGE_BOMB_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*MUD-SLAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*OCTAZOOKA_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*SPIKES_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*ZAP_CANNON_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*FORESIGHT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DESTINY_BOND_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*PERISH_SONG_FLAGS*/	FLAG_SOUND_BASED | FLAG_TARGET,
	/*ICY_WIND_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DETECT_FLAGS*/	FLAG_TARGET,
	/*BONE_RUSH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LOCK-ON_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*OUTRAGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SANDSTORM_FLAGS*/	FLAG_TARGET,
	/*GIGA_DRAIN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*ENDURE_FLAGS*/	FLAG_TARGET,
	/*CHARM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ROLLOUT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FALSE_SWIPE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SWAGGER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MILK_DRINK_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*SPARK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FURY_CUTTER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*STEEL_WING_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MEAN_LOOK_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*ATTRACT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SLEEP_TALK_FLAGS*/	FLAG_TARGET,
	/*HEAL_BELL_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*RETURN_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*PRESENT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FRUSTRATION_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SAFEGUARD_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*PAIN_SPLIT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SACRED_FIRE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MAGNITUDE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DYNAMIC_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MEGAHORN_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DRAGON_BREATH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BATON_PASS_FLAGS*/	FLAG_TARGET,
	/*ENCORE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PURSUIT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*RAPID_SPIN_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SWEET_SCENT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*IRON_TAIL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*METAL_CLAW_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*VITAL_THROW_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MORNING_SUN_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*SYNTHESIS_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*MOONLIGHT_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*HIDDEN_POWER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CROSS_CHOP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TWISTER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*RAIN_DANCE_FLAGS*/	FLAG_TARGET,
	/*SUNNY_DAY_FLAGS*/	FLAG_TARGET,
	/*CRUNCH_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*MIRROR_COAT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PSYCH_UP_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*EXTREME_SPEED_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ANCIENT_POWER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SHADOW_BALL_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*FUTURE_SIGHT_FLAGS*/	FLAG_TARGET,
	/*ROCK_SMASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*WHIRLPOOL_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BEAT_UP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FAKE_OUT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*UPROAR_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*STOCKPILE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*SPIT_UP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SWALLOW_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*HEAT_WAVE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HAIL_FLAGS*/	FLAG_TARGET,
	/*TORMENT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLATTER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WILL-O-WISP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MEMENTO_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FACADE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FOCUS_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SMELLING_SALTS_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FOLLOW_ME_FLAGS*/	FLAG_TARGET,
	/*NATURE_POWER_FLAGS*/	FLAG_TARGET,
	/*CHARGE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*TAUNT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HELPING_HAND_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*TRICK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ROLE_PLAY_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*WISH_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*ASSIST_FLAGS*/	FLAG_TARGET,
	/*INGRAIN_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*SUPERPOWER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MAGIC_COAT_FLAGS*/	FLAG_TARGET,
	/*RECYCLE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*REVENGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BRICK_BREAK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*YAWN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*KNOCK_OFF_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ENDEAVOR_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ERUPTION_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SKILL_SWAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*IMPRISON_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*REFRESH_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*GRUDGE_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*SNATCH_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*SECRET_POWER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DIVE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ARM_THRUST_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*CAMOUFLAGE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*TAIL_GLOW_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*LUSTER_PURGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MIST_BALL_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*FEATHER_DANCE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TEETER_DANCE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BLAZE_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MUD_SPORT_FLAGS*/	FLAG_TARGET,
	/*ICE_BALL_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*NEEDLE_ARM_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SLACK_OFF_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*HYPER_VOICE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*POISON_FANG_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*CRUSH_CLAW_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BLAST_BURN_FLAGS*/	FLAG_RECHARGE | FLAG_TARGET,
	/*HYDRO_CANNON_FLAGS*/	FLAG_RECHARGE | FLAG_TARGET,
	/*METEOR_MASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ASTONISH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*WEATHER_BALL_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*AROMATHERAPY_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*FAKE_TEARS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*AIR_CUTTER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*OVERHEAT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ODOR_SLEUTH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ROCK_TOMB_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SILVER_WIND_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*METAL_SOUND_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*GRASS_WHISTLE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TICKLE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*COSMIC_POWER_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*WATER_SPOUT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SIGNAL_BEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SHADOW_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*EXTRASENSORY_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SKY_UPPERCUT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SAND_TOMB_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SHEER_COLD_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MUDDY_WATER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BULLET_SEED_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*AERIAL_ACE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ICICLE_SPEAR_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*IRON_DEFENSE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*BLOCK_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*HOWL_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*DRAGON_CLAW_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FRENZY_PLANT_FLAGS*/	FLAG_RECHARGE | FLAG_TARGET,
	/*BULK_UP_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*BOUNCE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MUD_SHOT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*POISON_TAIL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*COVET_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*VOLT_TACKLE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MAGICAL_LEAF_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WATER_SPORT_FLAGS*/	FLAG_TARGET,
	/*CALM_MIND_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*LEAF_BLADE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DRAGON_DANCE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*ROCK_BLAST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SHOCK_WAVE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WATER_PULSE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DOOM_DESIRE_FLAGS*/	FLAG_TARGET,
	/*PSYCHO_BOOST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ROOST_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*GRAVITY_FLAGS*/	FLAG_TARGET,
	/*MIRACLE_EYE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WAKE-UP_SLAP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HAMMER_ARM_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*GYRO_BALL_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*HEALING_WISH_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*BRINE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*NATURAL_GIFT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FEINT_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*PLUCK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TAILWIND_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*ACUPRESSURE_FLAGS*/	FLAG_TARGET,
	/*METAL_BURST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*U-TURN_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*CLOSE_COMBAT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*PAYBACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ASSURANCE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*EMBARGO_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLING_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PSYCHO_SHIFT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TRUMP_CARD_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HEAL_BLOCK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WRING_OUT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*POWER_TRICK_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*GASTRO_ACID_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LUCKY_CHANT_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*ME_FIRST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*COPYCAT_FLAGS*/	FLAG_TARGET,
	/*POWER_SWAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*GUARD_SWAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PUNISHMENT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*LAST_RESORT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*WORRY_SEED_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SUCKER_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TOXIC_SPIKES_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*HEART_SWAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*AQUA_RING_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*MAGNET_RISE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*FLARE_BLITZ_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FORCE_PALM_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*AURA_SPHERE_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*ROCK_POLISH_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*POISON_JAB_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DARK_PULSE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*NIGHT_SLASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*AQUA_TAIL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SEED_BOMB_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*AIR_SLASH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*X-SCISSOR_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BUG_BUZZ_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAGON_PULSE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAGON_RUSH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*POWER_GEM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAIN_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*VACUUM_WAVE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FOCUS_BLAST_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*ENERGY_BALL_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*BRAVE_BIRD_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*EARTH_POWER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SWITCHEROO_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*GIGA_IMPACT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*NASTY_PLOT_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*BULLET_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*AVALANCHE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ICE_SHARD_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SHADOW_CLAW_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*THUNDER_FANG_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*ICE_FANG_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*FIRE_FANG_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*SHADOW_SNEAK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MUD_BOMB_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*PSYCHO_CUT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ZEN_HEADBUTT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MIRROR_SHOT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLASH_CANNON_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ROCK_CLIMB_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DEFOG_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TRICK_ROOM_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*DRACO_METEOR_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DISCHARGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LAVA_PLUME_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LEAF_STORM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*POWER_WHIP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ROCK_WRECKER_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*CROSS_POISON_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*GUNK_SHOT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*IRON_HEAD_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MAGNET_BOMB_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*STONE_EDGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CAPTIVATE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*STEALTH_ROCK_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*GRASS_KNOT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*CHATTER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*JUDGMENT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BUG_BITE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*CHARGE_BEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WOOD_HAMMER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*AQUA_JET_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ATTACK_ORDER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DEFEND_ORDER_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*HEAL_ORDER_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*HEAD_SMASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DOUBLE_HIT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ROAR_OF_TIME_FLAGS*/	FLAG_RECHARGE | FLAG_TARGET,
	/*SPACIAL_REND_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LUNAR_DANCE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*CRUSH_GRIP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MAGMA_STORM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DARK_VOID_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SEED_FLARE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*OMINOUS_WIND_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SHADOW_FORCE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HONE_CLAWS_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*WIDE_GUARD_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*GUARD_SPLIT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*POWER_SPLIT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WONDER_ROOM_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*PSYSHOCK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*VENOSHOCK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*AUTOTOMIZE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*RAGE_POWDER_FLAGS*/	FLAG_POWDER | FLAG_TARGET,
	/*TELEKINESIS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MAGIC_ROOM_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*SMACK_DOWN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*STORM_THROW_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FLAME_BURST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SLUDGE_WAVE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*QUIVER_DANCE_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*HEAVY_SLAM_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SYNCHRONOISE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ELECTRO_BALL_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*SOAK_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLAME_CHARGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*COIL_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*LOW_SWEEP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*ACID_SPRAY_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*FOUL_PLAY_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SIMPLE_BEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ENTRAINMENT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*AFTER_YOU_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*ROUND_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ECHOED_VOICE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CHIP_AWAY_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*CLEAR_SMOG_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*STORED_POWER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*QUICK_GUARD_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*ALLY_SWITCH_FLAGS*/	FLAG_TARGET,
	/*SCALD_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SHELL_SMASH_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*HEAL_PULSE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*HEX_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SKY_DROP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SHIFT_GEAR_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*CIRCLE_THROW_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*INCINERATE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*QUASH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ACROBATICS_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*REFLECT_TYPE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*RETALIATE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FINAL_GAMBIT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BESTOW_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*INFERNO_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WATER_PLEDGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FIRE_PLEDGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*GRASS_PLEDGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*VOLT_SWITCH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*STRUGGLE_BUG_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BULLDOZE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FROST_BREATH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAGON_TAIL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*WORK_UP_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*ELECTROWEB_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*WILD_CHARGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DRILL_RUN_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*DUAL_CHOP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HEART_STAMP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HORN_LEECH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*SACRED_SWORD_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*RAZOR_SHELL_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HEAT_CRASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*LEAF_TORNADO_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*STEAMROLLER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*COTTON_GUARD_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*NIGHT_DAZE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PSYSTRIKE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TAIL_SLAP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HURRICANE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HEAD_CHARGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*GEAR_GRIND_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SEARING_SHOT_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*TECHNO_BLAST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*RELIC_SONG_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SECRET_SWORD_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*GLACIATE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BOLT_STRIKE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BLUE_FLARE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FIERY_DANCE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FREEZE_SHOCK_FLAGS*/	FLAG_CHARGEUP | FLAG_TARGET,
	/*ICE_BURN_FLAGS*/	FLAG_CHARGEUP | FLAG_TARGET,
	/*SNARL_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ICICLE_CRASH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*V-CREATE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FUSION_FLARE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FUSION_BOLT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLYING_PRESS_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MAT_BLOCK_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*BELCH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ROTOTILLER_FLAGS*/	FLAG_TARGET,
	/*STICKY_WEB_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*FELL_STINGER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*PHANTOM_FORCE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*TRICK-OR-TREAT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*NOBLE_ROAR_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ION_DELUGE_FLAGS*/	FLAG_TARGET,
	/*PARABOLIC_CHARGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*FOREST‘S_CURSE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PETAL_BLIZZARD_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FREEZE-DRY_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DISARMING_VOICE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PARTING_SHOT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TOPSY-TURVY_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAINING_KISS_FLAGS*/	FLAG_CONTACT | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*CRAFTY_SHIELD_FLAGS*/	FLAG_TARGET,
	/*FLOWER_SHIELD_FLAGS*/	FLAG_TARGET,
	/*GRASSY_TERRAIN_FLAGS*/	FLAG_TARGET,
	/*MISTY_TERRAIN_FLAGS*/	FLAG_TARGET,
	/*ELECTRIFY_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PLAY_ROUGH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FAIRY_WIND_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MOONBLAST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BOOMBURST_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FAIRY_LOCK_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*KING‘S_SHIELD_FLAGS*/	FLAG_TARGET,
	/*PLAY_NICE_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*CONFIDE_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*DIAMOND_STORM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*STEAM_ERUPTION_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HYPERSPACE_HOLE_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*WATER_SHURIKEN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MYSTICAL_FIRE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SPIKY_SHIELD_FLAGS*/	FLAG_TARGET,
	/*AROMATIC_MIST_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*EERIE_IMPULSE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*VENOM_DRENCH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*POWDER_FLAGS*/	FLAG_POWDER | FLAG_TARGET,
	/*GEOMANCY_FLAGS*/	FLAG_CHARGEUP | FLAG_TARGET,
	/*MAGNETIC_FLUX_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*HAPPY_HOUR_FLAGS*/	FLAG_TARGET,
	/*ELECTRIC_TERRAIN_FLAGS*/	FLAG_TARGET,
	/*DAZZLING_GLEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CELEBRATE_FLAGS*/	FLAG_TARGET,
	/*BABY-DOLL_EYES_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*NUZZLE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HOLD_BACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*INFESTATION_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*POWER-UP_PUNCH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*OBLIVION_WING_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*THOUSAND_ARROWS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*THOUSAND_WAVES_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*HOLD_HANDS_FLAGS*/	FLAG_IGNORE_SUBSTITUTE | FLAG_TARGET,
	/*LAND‘S_WRATH_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LIGHT_OF_RUIN_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ORIGIN_PULSE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PRECIPICE_BLADES_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAGON_ASCENT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*HYPERSPACE_FURY_FLAGS*/	FLAG_MIRRORABLE | FLAG_TARGET,
	/*SHORE_UP_FLAGS*/	FLAG_SNATCH | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*FIRST_IMPRESSION_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BANEFUL_BUNKER_FLAGS*/	FLAG_TARGET,
	/*SPIRIT_SHACKLE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DARKEST_LARIAT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SPARKLING_ARIA_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ICE_HAMMER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FLORAL_HEALING_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*HIGH_HORSEPOWER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*STRENGTH_SAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*SOLAR_BLADE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*LEAFAGE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SPOTLIGHT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TOXIC_THREAD_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*LASER_FOCUS_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*GEAR_UP_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*THROAT_CHOP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*POLLEN_PUFF_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*ANCHOR_SHOT_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*PSYCHIC_TERRAIN_FLAGS*/	FLAG_TARGET,
	/*LUNGE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*FIRE_LASH_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*POWER_TRIP*/	FLAG_TARGET,
	/*BURN_UP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SPEED_SWAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*SMART_STRIKE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*PURIFY_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET | FLAG_TRIAGE_AFFECTED,
	/*REVELATION_DANCE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*CORE_ENFORCER_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TROP_KICK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*INSTRUCT_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*BEAK_BLAST_FLAGS*/	FLAG_BULLET_PROOF | FLAG_TARGET,
	/*CLANGING_SCALES_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*DRAGON_HAMMER_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*BRUTAL_SWING_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*AURORA_VEIL_FLAGS*/	FLAG_SNATCH | FLAG_TARGET,
	/*SHELL_TRAP_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*FLEUR_CANNON_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*PSYCHIC_FANGS_FLAGS*/	FLAG_STRONG_JAW | FLAG_TARGET,
	/*STOMPING_TANTRUM_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SHADOW_BONE_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*ACCELEROCK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*LIQUIDATION_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*PRISMATIC_LASER_FLAGS*/	FLAG_RECHARGE | FLAG_TARGET,
	/*SPECTRAL_THIEF_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*SUNSTEEL_STRIKE_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*MOONGEIST_BEAM_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*TEARFUL_LOOK_FLAGS*/	FLAG_REFLECTABLE | FLAG_TARGET,
	/*ZING_ZAP_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
	/*NATURE‘S_MADNESS_FLAGS*/	FLAG_PROTECTABLE | FLAG_TARGET,
	/*MULTI-ATTACK_FLAGS*/	FLAG_CONTACT | FLAG_TARGET,
};

extern struct move_procs basic_proc;
extern struct move_procs basic_multihit_proc;
extern struct move_procs basic_doublehit_proc;
extern struct move_procs basic_triplehit_proc;
extern struct move_callbacks null_mcb;


struct move_data move_t[] = {
    {_("-"), 0, 0, (pchar*)Pound_desc, 0, 0, 0, MOVE_PHYSICAL, MTYPE_EGG, &m_flags[0], &basic_proc, &null_mcb},
	{_("Pound"), 100, 40, (pchar*)Pound_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[1], &basic_proc, &null_mcb},
	{_("Karate Chop"), 100, 50, (pchar*)Karate_Chop_desc, 25, 0, 2, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[2], &basic_proc, &null_mcb},
	{_("Double Slap"), 85, 15, (pchar*)Double_Slap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[3], &basic_proc, &null_mcb},
	{_("Comet Punch"), 85, 18, (pchar*)Comet_Punch_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[4], &basic_proc, &null_mcb},
	{_("Mega Punch"), 85, 80, (pchar*)Mega_Punch_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[5], &basic_proc, &null_mcb},
	{_("Pay Day"), 100, 40, (pchar*)Pay_Day_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[6], &basic_proc, &null_mcb},
	{_("Fire Punch"), 100, 75, (pchar*)Fire_Punch_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[7], &basic_proc, &null_mcb},
	{_("Ice Punch"), 100, 75, (pchar*)Ice_Punch_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[8], &basic_proc, &null_mcb},
	{_("Thunder Punch"), 100, 75, (pchar*)Thunder_Punch_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[9], &basic_proc, &null_mcb},
	{_("Scratch"), 100, 40, (pchar*)Scratch_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[10], &basic_proc, &null_mcb},
	{_("Vice Grip"), 100, 55, (pchar*)Vice_Grip_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[11], &basic_proc, &null_mcb},
	{_("Guillotine"), 30, 0, (pchar*)Guillotine_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[12], &basic_proc, &null_mcb},
	{_("Razor Wind"), 100, 80, (pchar*)Razor_Wind_desc, 10, 0, 2, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[13], &basic_proc, &null_mcb},
	{_("Swords Dance"), 101, 0, (pchar*)Swords_Dance_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[14], &basic_proc, &null_mcb},
	{_("Cut"), 95, 50, (pchar*)Cut_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[15], &basic_proc, &null_mcb},
	{_("Gust"), 100, 40, (pchar*)Gust_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[16], &basic_proc, &null_mcb},
	{_("Wing Attack"), 100, 60, (pchar*)Wing_Attack_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[17], &basic_proc, &null_mcb},
	{_("Whirlwind"), 101, 0, (pchar*)Whirlwind_desc, 20, -6, 1, 3, MTYPE_NORMAL, &m_flags[18], &basic_proc, &null_mcb},
	{_("Fly"), 95, 90, (pchar*)Fly_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[19], &basic_proc, &null_mcb},
	{_("Bind"), 85, 15, (pchar*)Bind_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[20], &basic_proc, &null_mcb},
	{_("Slam"), 75, 80, (pchar*)Slam_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[21], &basic_proc, &null_mcb},
	{_("Vine Whip"), 100, 45, (pchar*)Vine_Whip_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[22], &basic_proc, &null_mcb},
	{_("Stomp"), 100, 65, (pchar*)Stomp_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[23], &basic_proc, &null_mcb},
	{_("Double Kick"), 100, 30, (pchar*)Double_Kick_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[24], &basic_doublehit_proc, &null_mcb},
	{_("Mega Kick"), 75, 120, (pchar*)Mega_Kick_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[25], &basic_proc, &null_mcb},
	{_("Jump Kick"), 95, 100, (pchar*)Jump_Kick_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[26], &basic_proc, &null_mcb},
	{_("Rolling Kick"), 85, 60, (pchar*)Rolling_Kick_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[27], &basic_proc, &null_mcb},
	{_("Sand Attack"), 100, 0, (pchar*)Sand_Attack_desc, 15, 0, 1, MOVE_STATUS, MTYPE_GROUND, &m_flags[28], &basic_proc, &null_mcb},
	{_("Headbutt"), 100, 70, (pchar*)Headbutt_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[29], &basic_proc, &null_mcb},
	{_("Horn Attack"), 100, 65, (pchar*)Horn_Attack_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[30], &basic_proc, &null_mcb},
	{_("Fury Attack"), 85, 15, (pchar*)Fury_Attack_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[31], &basic_proc, &null_mcb},
	{_("Horn Drill"), 30, 0, (pchar*)Horn_Drill_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[32], &basic_proc, &null_mcb},
	{_("Tackle"), 100, 40, (pchar*)Tackle_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[33], &basic_proc, &null_mcb},
	{_("Body Slam"), 100, 85, (pchar*)Body_Slam_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[34], &basic_proc, &null_mcb},
	{_("Wrap"), 90, 15, (pchar*)Wrap_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[35], &basic_proc, &null_mcb},
	{_("Take Down"), 85, 90, (pchar*)Take_Down_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[36], &basic_proc, &null_mcb},
	{_("Thrash"), 100, 120, (pchar*)Thrash_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[37], &basic_proc, &null_mcb},
	{_("Double-Edge"), 100, 120, (pchar*)Double_Edge_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[38], &basic_proc, &null_mcb},
	{_("Tail Whip"), 100, 0, (pchar*)Tail_Whip_desc, 30, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[39], &basic_proc, &null_mcb},
	{_("Poison Sting"), 100, 15, (pchar*)Poison_Sting_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[40], &basic_proc, &null_mcb},
	{_("Twineedle"), 100, 25, (pchar*)Twineedle_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[41], &basic_doublehit_proc, &null_mcb},
	{_("Pin Missile"), 95, 25, (pchar*)Pin_Missile_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[42], &basic_proc, &null_mcb},
	{_("Leer"), 100, 0, (pchar*)Leer_desc, 30, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[43], &basic_proc, &null_mcb},
	{_("Bite"), 100, 60, (pchar*)Bite_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[44], &basic_proc, &null_mcb},
	{_("Growl"), 100, 0, (pchar*)Growl_desc, 40, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[45], &basic_proc, &null_mcb},
	{_("Roar"), 101, 0, (pchar*)Roar_desc, 20, -6, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[46], &basic_proc, &null_mcb},
	{_("Sing"), 55, 0, (pchar*)Sing_desc, 15, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[47], &basic_proc, &null_mcb},
	{_("Supersonic"), 55, 0, (pchar*)Supersonic_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[48], &basic_proc, &null_mcb},
	{_("Sonic Boom"), 90, 0, (pchar*)Sonic_Boom_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[49], &basic_proc, &null_mcb},
	{_("Disable"), 100, 0, (pchar*)Disable_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[50], &basic_proc, &null_mcb},
	{_("Acid"), 100, 40, (pchar*)Acid_desc, 30, 0, 1, MOVE_SPECIAL, MTYPE_POISON, &m_flags[51], &basic_proc, &null_mcb},
	{_("Ember"), 100, 40, (pchar*)Ember_desc, 25, 0, 1, MOVE_SPECIAL, MTYPE_FIRE, &m_flags[52], &basic_proc, &null_mcb},
	{_("Flamethrower"), 100, 90, (pchar*)Flamethrower_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_FIRE, &m_flags[53], &basic_proc, &null_mcb},
	{_("Mist"), 101, 0, (pchar*)Mist_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[54], &basic_proc, &null_mcb},
	{_("Water Gun"), 100, 40, (pchar*)Water_Gun_desc, 25, 0, 1, MOVE_SPECIAL, MTYPE_WATER, &m_flags[55], &basic_proc, &null_mcb},
	{_("Hydro Pump"), 80, 110, (pchar*)Hydro_Pump_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_WATER, &m_flags[56], &basic_proc, &null_mcb},
	{_("Surf"), 100, 90, (pchar*)Surf_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_WATER, &m_flags[57], &basic_proc, &null_mcb},
	{_("Ice Beam"), 100, 90, (pchar*)Ice_Beam_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_ICE, &m_flags[58], &basic_proc, &null_mcb},
	{_("Blizzard"), 70, 110, (pchar*)Blizzard_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_ICE, &m_flags[59], &basic_proc, &null_mcb},
	{_("Psybeam"), 100, 65, (pchar*)Psybeam_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_PSYCHIC, &m_flags[60], &basic_proc, &null_mcb},
	{_("Bubble Beam"), 100, 65, (pchar*)Bubble_Beam_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_WATER, &m_flags[61], &basic_proc, &null_mcb},
	{_("Aurora Beam"), 100, 65, (pchar*)Aurora_Beam_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_ICE, &m_flags[62], &basic_proc, &null_mcb},
	{_("Hyper Beam"), 90, 150, (pchar*)Hyper_Beam_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[63], &basic_proc, &null_mcb},
	{_("Peck"), 100, 35, (pchar*)Peck_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[64], &basic_proc, &null_mcb},
	{_("Drill Peck"), 100, 80, (pchar*)Drill_Peck_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[65], &basic_proc, &null_mcb},
	{_("Submission"), 80, 80, (pchar*)Submission_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[66], &basic_proc, &null_mcb},
	{_("Low Kick"), 100, 0, (pchar*)Low_Kick_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[67], &basic_proc, &null_mcb},
	{_("Counter"), 100, 0, (pchar*)Counter_desc, 20, -5, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[68], &basic_proc, &null_mcb},
	{_("Seismic Toss"), 100, 0, (pchar*)Seismic_Toss_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[69], &basic_proc, &null_mcb},
	{_("Strength"), 100, 80, (pchar*)Strength_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[70], &basic_proc, &null_mcb},
	{_("Absorb"), 100, 20, (pchar*)Absorb_desc, 25, 0, 1, MOVE_SPECIAL, MTYPE_GRASS, &m_flags[71], &basic_proc, &null_mcb},
	{_("Mega Drain"), 100, 40, (pchar*)Mega_Drain_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_GRASS, &m_flags[72], &basic_proc, &null_mcb},
	{_("Leech Seed"), 90, 0, (pchar*)Leech_Seed_desc, 10, 0, 1, MOVE_STATUS, MTYPE_GRASS, &m_flags[73], &basic_proc, &null_mcb},
	{_("Growth"), 101, 0, (pchar*)Growth_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[74], &basic_proc, &null_mcb},
	{_("Razor Leaf"), 95, 55, (pchar*)Razor_Leaf_desc, 25, 0, 2, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[75], &basic_proc, &null_mcb},
	{_("Solar Beam"), 100, 120, (pchar*)Solar_Beam_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_GRASS, &m_flags[76], &basic_proc, &null_mcb},
	{_("Poison Powder"), 75, 0, (pchar*)Poison_Powder_desc, 35, 0, 1, MOVE_STATUS, MTYPE_POISON, &m_flags[77], &basic_proc, &null_mcb},
	{_("Stun Spore"), 75, 0, (pchar*)Stun_Spore_desc, 30, 0, 1, MOVE_STATUS, MTYPE_GRASS, &m_flags[78], &basic_proc, &null_mcb},
	{_("Sleep Powder"), 75, 0, (pchar*)Sleep_Powder_desc, 15, 0, 1, MOVE_STATUS, MTYPE_GRASS, &m_flags[79], &basic_proc, &null_mcb},
	{_("Petal Dance"), 100, 120, (pchar*)Petal_Dance_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_GRASS, &m_flags[80], &basic_proc, &null_mcb},
	{_("String Shot"), 95, 0, (pchar*)String_Shot_desc, 40, 0, 1, MOVE_STATUS, MTYPE_BUG, &m_flags[81], &basic_proc, &null_mcb},
	{_("Dragon Rage"), 100, 0, (pchar*)Dragon_Rage_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_DRAGON, &m_flags[82], &basic_proc, &null_mcb},
	{_("Fire Spin"), 85, 35, (pchar*)Fire_Spin_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_FIRE, &m_flags[83], &basic_proc, &null_mcb},
	{_("Thunder Shock"), 100, 40, (pchar*)Thunder_Shock_desc, 30, 0, 1, MOVE_SPECIAL, MTYPE_ELECTRIC, &m_flags[84], &basic_proc, &null_mcb},
	{_("Thunderbolt"), 100, 90, (pchar*)Thunderbolt_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_ELECTRIC, &m_flags[85], &basic_proc, &null_mcb},
	{_("Thunder Wave"), 90, 0, (pchar*)Thunder_Wave_desc, 20, 0, 1, MOVE_STATUS, MTYPE_ELECTRIC, &m_flags[86], &basic_proc, &null_mcb},
	{_("Thunder"), 70, 110, (pchar*)Thunder_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_ELECTRIC, &m_flags[87], &basic_proc, &null_mcb},
	{_("Rock Throw"), 90, 50, (pchar*)Rock_Throw_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[88], &basic_proc, &null_mcb},
	{_("Earthquake"), 100, 100, (pchar*)Earthquake_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[89], &basic_proc, &null_mcb},
	{_("Fissure"), 30, 0, (pchar*)Fissure_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[90], &basic_proc, &null_mcb},
	{_("Dig"), 100, 80, (pchar*)Dig_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[91], &basic_proc, &null_mcb},
	{_("Toxic"), 90, 0, (pchar*)Toxic_desc, 10, 0, 1, MOVE_STATUS, MTYPE_POISON, &m_flags[92], &basic_proc, &null_mcb},
	{_("Confusion"), 100, 50, (pchar*)Confusion_desc, 25, 0, 1, MOVE_SPECIAL, MTYPE_PSYCHIC, &m_flags[93], &basic_proc, &null_mcb},
	{_("Psychic"), 100, 90, (pchar*)Psychic_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_PSYCHIC, &m_flags[94], &basic_proc, &null_mcb},
	{_("Hypnosis"), 60, 0, (pchar*)Hypnosis_desc, 20, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[95], &basic_proc, &null_mcb},
	{_("Meditate"), 101, 0, (pchar*)Meditate_desc, 40, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[96], &basic_proc, &null_mcb},
	{_("Agility"), 101, 0, (pchar*)Agility_desc, 30, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[97], &basic_proc, &null_mcb},
	{_("Quick Attack"), 100, 40, (pchar*)Quick_Attack_desc, 30, 1, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[98], &basic_proc, &null_mcb},
	{_("Rage"), 100, 20, (pchar*)Rage_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[99], &basic_proc, &null_mcb},
	{_("Teleport"), 101, 0, (pchar*)Teleport_desc, 20, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[100], &basic_proc, &null_mcb},
	{_("Night Shade"), 100, 0, (pchar*)Night_Shade_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_GHOST, &m_flags[101], &basic_proc, &null_mcb},
	{_("Mimic"), 101, 0, (pchar*)Mimic_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[102], &basic_proc, &null_mcb},
	{_("Screech"), 85, 0, (pchar*)Screech_desc, 40, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[103], &basic_proc, &null_mcb},
	{_("Double Team"), 101, 0, (pchar*)Double_Team_desc, 15, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[104], &basic_proc, &null_mcb},
	{_("Recover"), 101, 0, (pchar*)Recover_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[105], &basic_proc, &null_mcb},
	{_("Harden"), 101, 0, (pchar*)Harden_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[106], &basic_proc, &null_mcb},
	{_("Minimize"), 101, 0, (pchar*)Minimize_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[107], &basic_proc, &null_mcb},
	{_("Smokescreen"), 100, 0, (pchar*)Smokescreen_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[108], &basic_proc, &null_mcb},
	{_("Confuse Ray"), 100, 0, (pchar*)Confuse_Ray_desc, 10, 0, 1, MOVE_STATUS, MTYPE_GHOST, &m_flags[109], &basic_proc, &null_mcb},
	{_("Withdraw"), 101, 0, (pchar*)Withdraw_desc, 40, 0, 1, MOVE_STATUS, MTYPE_WATER, &m_flags[110], &basic_proc, &null_mcb},
	{_("Defense Curl"), 101, 0, (pchar*)Defense_Curl_desc, 40, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[111], &basic_proc, &null_mcb},
	{_("Barrier"), 101, 0, (pchar*)Barrier_desc, 20, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[112], &basic_proc, &null_mcb},
	{_("Light Screen"), 101, 0, (pchar*)Light_Screen_desc, 30, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[113], &basic_proc, &null_mcb},
	{_("Haze"), 101, 0, (pchar*)Haze_desc, 30, 0, 1, MOVE_STATUS, MTYPE_ICE, &m_flags[114], &basic_proc, &null_mcb},
	{_("Reflect"), 101, 0, (pchar*)Reflect_desc, 20, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[115], &basic_proc, &null_mcb},
	{_("Focus Energy"), 101, 0, (pchar*)Focus_Energy_desc, 30, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[116], &basic_proc, &null_mcb},
	{_("Bide"), 101, 0, (pchar*)Bide_desc, 10, 1, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[117], &basic_proc, &null_mcb},
	{_("Metronome"), 101, 0, (pchar*)Metronome_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[118], &basic_proc, &null_mcb},
	{_("Mirror Move"), 101, 0, (pchar*)Mirror_Move_desc, 20, 0, 1, MOVE_STATUS, MTYPE_FLYING, &m_flags[119], &basic_proc, &null_mcb},
	{_("Self-Destruct"), 100, 200, (pchar*)Self_Destruct_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[120], &basic_proc, &null_mcb},
	{_("Egg Bomb"), 75, 100, (pchar*)Egg_Bomb_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[121], &basic_proc, &null_mcb},
	{_("Lick"), 100, 30, (pchar*)Lick_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[122], &basic_proc, &null_mcb},
	{_("Smog"), 70, 30, (pchar*)Smog_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_POISON, &m_flags[123], &basic_proc, &null_mcb},
	{_("Sludge"), 100, 65, (pchar*)Sludge_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_POISON, &m_flags[124], &basic_proc, &null_mcb},
	{_("Bone Club"), 85, 65, (pchar*)Bone_Club_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[125], &basic_proc, &null_mcb},
	{_("Fire Blast"), 85, 110, (pchar*)Fire_Blast_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_FIRE, &m_flags[126], &basic_proc, &null_mcb},
	{_("Waterfall"), 100, 80, (pchar*)Waterfall_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[127], &basic_proc, &null_mcb},
	{_("Clamp"), 85, 35, (pchar*)Clamp_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[128], &basic_proc, &null_mcb},
	{_("Swift"), 101, 60, (pchar*)Swift_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[129], &basic_proc, &null_mcb},
	{_("Skull Bash"), 100, 130, (pchar*)Skull_Bash_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[130], &basic_proc, &null_mcb},
	{_("Spike Cannon"), 100, 20, (pchar*)Spike_Cannon_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[131], &basic_proc, &null_mcb},
	{_("Constrict"), 100, 10, (pchar*)Constrict_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[132], &basic_proc, &null_mcb},
	{_("Amnesia"), 101, 0, (pchar*)Amnesia_desc, 20, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[133], &basic_proc, &null_mcb},
	{_("Kinesis"), 80, 0, (pchar*)Kinesis_desc, 15, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[134], &basic_proc, &null_mcb},
	{_("Soft-Boiled"), 101, 0, (pchar*)Soft_Boiled_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[135], &basic_proc, &null_mcb},
	{_("High Jump Kick"), 90, 130, (pchar*)High_Jump_Kick_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[136], &basic_proc, &null_mcb},
	{_("Glare"), 100, 0, (pchar*)Glare_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[137], &basic_proc, &null_mcb},
	{_("Dream Eater"), 100, 100, (pchar*)Dream_Eater_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_PSYCHIC, &m_flags[138], &basic_proc, &null_mcb},
	{_("Poison Gas"), 90, 0, (pchar*)Poison_Gas_desc, 40, 0, 1, MOVE_SPECIAL, MTYPE_POISON, &m_flags[139], &basic_proc, &null_mcb},
	{_("Barrage"), 85, 15, (pchar*)Barrage_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[140], &basic_proc, &null_mcb},
	{_("Leech Life"), 100, 80, (pchar*)Leech_Life_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[141], &basic_proc, &null_mcb},
	{_("Lovely Kiss"), 75, 0, (pchar*)Lovely_Kiss_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[142], &basic_proc, &null_mcb},
	{_("Sky Attack"), 90, 140, (pchar*)Sky_Attack_desc, 5, 0, 2, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[143], &basic_proc, &null_mcb},
	{_("Transform"), 101, 0, (pchar*)Transform_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[144], &basic_proc, &null_mcb},
	{_("Bubble"), 100, 40, (pchar*)Bubble_desc, 30, 0, 1, MOVE_SPECIAL, MTYPE_WATER, &m_flags[145], &basic_proc, &null_mcb},
	{_("Dizzy Punch"), 100, 70, (pchar*)Dizzy_Punch_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[146], &basic_proc, &null_mcb},
	{_("Spore"), 100, 0, (pchar*)Spore_desc, 15, 0, 1, MOVE_STATUS, MTYPE_GRASS, &m_flags[147], &basic_proc, &null_mcb},
	{_("Flash"), 100, 0, (pchar*)Flash_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[148], &basic_proc, &null_mcb},
	{_("Psywave"), 100, 0, (pchar*)Psywave_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_PSYCHIC, &m_flags[149], &basic_proc, &null_mcb},
	{_("Splash"), 101, 0, (pchar*)Splash_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[150], &basic_proc, &null_mcb},
	{_("Acid Armor"), 101, 0, (pchar*)Acid_Armor_desc, 20, 0, 1, MOVE_STATUS, MTYPE_POISON, &m_flags[151], &basic_proc, &null_mcb},
	{_("Crabhammer"), 90, 100, (pchar*)Crabhammer_desc, 10, 0, 2, MOVE_SPECIAL, MTYPE_WATER, &m_flags[152], &basic_proc, &null_mcb},
	{_("Explosion"), 100, 250, (pchar*)Explosion_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[153], &basic_proc, &null_mcb},
	{_("Fury Swipes"), 80, 18, (pchar*)Fury_Swipes_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[154], &basic_proc, &null_mcb},
	{_("Bonemerang"), 90, 50, (pchar*)Bonemerang_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[155], &basic_doublehit_proc, &null_mcb},
	{_("Rest"), 101, 0, (pchar*)Rest_desc, 10, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[156], &basic_proc, &null_mcb},
	{_("Rock Slide"), 90, 75, (pchar*)Rock_Slide_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[157], &basic_proc, &null_mcb},
	{_("Hyper Fang"), 90, 80, (pchar*)Hyper_Fang_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[158], &basic_proc, &null_mcb},
	{_("Sharpen"), 101, 0, (pchar*)Sharpen_desc, 30, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[159], &basic_proc, &null_mcb},
	{_("Conversion"), 101, 0, (pchar*)Conversion_desc, 30, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[160], &basic_proc, &null_mcb},
	{_("Tri Attack"), 100, 80, (pchar*)Tri_Attack_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[161], &basic_proc, &null_mcb},
	{_("Super Fang"), 90, 0, (pchar*)Super_Fang_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[162], &basic_proc, &null_mcb},
	{_("Slash"), 100, 70, (pchar*)Slash_desc, 20, 0, 2, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[163], &basic_proc, &null_mcb},
	{_("Substitute"), 101, 0, (pchar*)Substitute_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[164], &basic_proc, &null_mcb},
	{_("Struggle"), 101, 50, (pchar*)Struggle_desc, 1, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[165], &basic_proc, &null_mcb},
	{_("Sketch"), 101, 0, (pchar*)Sketch_desc, 1, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[166], &basic_proc, &null_mcb},
	{_("Triple Kick"), 90, 10, (pchar*)Triple_Kick_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[167], &basic_triplehit_proc, &null_mcb},
	{_("Thief"), 100, 60, (pchar*)Thief_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[168], &basic_proc, &null_mcb},
	{_("Spider Web"), 101, 0, (pchar*)Spider_Web_desc, 10, 0, 1, MOVE_STATUS, MTYPE_BUG, &m_flags[169], &basic_proc, &null_mcb},
	{_("Mind Reader"), 101, 0, (pchar*)Mind_Reader_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[170], &basic_proc, &null_mcb},
	{_("Nightmare"), 100, 0, (pchar*)Nightmare_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_GHOST, &m_flags[171], &basic_proc, &null_mcb},
	{_("Flame Wheel"), 100, 60, (pchar*)Flame_Wheel_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[172], &basic_proc, &null_mcb},
	{_("Snore"), 100, 50, (pchar*)Snore_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[173], &basic_proc, &null_mcb},
	{_("Curse"), 101, 0, (pchar*)Curse_desc, 10, 0, 1, MOVE_STATUS, MTYPE_GHOST, &m_flags[174], &basic_proc, &null_mcb},
	{_("Flail"), 100, 0, (pchar*)Flail_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[175], &basic_proc, &null_mcb},
	{_("Conversion 2"), 101, 0, (pchar*)Conversion_2_desc, 30, 0, 1, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[176], &basic_proc, &null_mcb},
	{_("Aeroblast"), 95, 100, (pchar*)Aeroblast_desc, 5, 0, 2, MOVE_SPECIAL, MTYPE_FLYING, &m_flags[177], &basic_proc, &null_mcb},
	{_("Cotton Spore"), 100, 0, (pchar*)Cotton_Spore_desc, 40, 0, 1, MOVE_STATUS, MTYPE_GRASS, &m_flags[178], &basic_proc, &null_mcb},
	{_("Reversal"), 100, 0, (pchar*)Reversal_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[179], &basic_proc, &null_mcb},
	{_("Spite"), 100, 0, (pchar*)Spite_desc, 10, 0, 1, MOVE_STATUS, MTYPE_GHOST, &m_flags[180], &basic_proc, &null_mcb},
	{_("Powder Snow"), 100, 40, (pchar*)Powder_Snow_desc, 25, 0, 1, MOVE_SPECIAL, MTYPE_ICE, &m_flags[181], &basic_proc, &null_mcb},
	{_("Protect"), 101, 0, (pchar*)Protect_desc, 10, 4, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[182], &basic_proc, &null_mcb},
	{_("Mach Punch"), 100, 40, (pchar*)Mach_Punch_desc, 30, 1, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[183], &basic_proc, &null_mcb},
	{_("Scary Face"), 100, 0, (pchar*)Scary_Face_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[184], &basic_proc, &null_mcb},
	{_("Feint Attack"), 101, 60, (pchar*)Feint_Attack_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[185], &basic_proc, &null_mcb},
	{_("Sweet Kiss"), 75, 0, (pchar*)Sweet_Kiss_desc, 10, 0, 1, MOVE_STATUS, MTYPE_FAIRY, &m_flags[186], &basic_proc, &null_mcb},
	{_("Belly Drum"), 101, 0, (pchar*)Belly_Drum_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[187], &basic_proc, &null_mcb},
	{_("Sludge Bomb"), 100, 90, (pchar*)Sludge_Bomb_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_POISON, &m_flags[188], &basic_proc, &null_mcb},
	{_("Mud-Slap"), 100, 20, (pchar*)Mud_Slap_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_GROUND, &m_flags[189], &basic_proc, &null_mcb},
	{_("Octazooka"), 85, 65, (pchar*)Octazooka_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_WATER, &m_flags[190], &basic_proc, &null_mcb},
	{_("Spikes"), 101, 0, (pchar*)Spikes_desc, 20, 0, 1, MOVE_STATUS, MTYPE_GROUND, &m_flags[191], &basic_proc, &null_mcb},
	{_("Zap Cannon"), 50, 120, (pchar*)Zap_Cannon_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_ELECTRIC, &m_flags[192], &basic_proc, &null_mcb},
	{_("Foresight"), 101, 0, (pchar*)Foresight_desc, 40, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[193], &basic_proc, &null_mcb},
	{_("Destiny Bond"), 101, 0, (pchar*)Destiny_Bond_desc, 5, 0, 1, MOVE_STATUS, MTYPE_GHOST, &m_flags[194], &basic_proc, &null_mcb},
	{_("Perish Song"), 101, 0, (pchar*)Perish_Song_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[195], &basic_proc, &null_mcb},
	{_("Icy Wind"), 95, 55, (pchar*)Icy_Wind_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_ICE, &m_flags[196], &basic_proc, &null_mcb},
	{_("Detect"), 101, 0, (pchar*)Detect_desc, 5, 4, 1, MOVE_STATUS, MTYPE_FIGHTING, &m_flags[197], &basic_proc, &null_mcb},
	{_("Bone Rush"), 90, 25, (pchar*)Bone_Rush_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[198], &basic_proc, &null_mcb},
	{_("Lock-On"), 101, 0, (pchar*)Lock_On_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[199], &basic_proc, &null_mcb},
	{_("Outrage"), 100, 120, (pchar*)Outrage_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[200], &basic_proc, &null_mcb},
	{_("Sandstorm"), 101, 0, (pchar*)Sandstorm_desc, 10, 0, 1, MOVE_STATUS, MTYPE_ROCK, &m_flags[201], &basic_proc, &null_mcb},
	{_("Giga Drain"), 100, 75, (pchar*)Giga_Drain_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_GRASS, &m_flags[202], &basic_proc, &null_mcb},
	{_("Endure"), 101, 0, (pchar*)Endure_desc, 10, 4, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[203], &basic_proc, &null_mcb},
	{_("Charm"), 100, 0, (pchar*)Charm_desc, 20, 0, 1, MOVE_STATUS, MTYPE_FAIRY, &m_flags[204], &basic_proc, &null_mcb},
	{_("Rollout"), 90, 30, (pchar*)Rollout_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[205], &basic_proc, &null_mcb},
	{_("False Swipe"), 100, 40, (pchar*)False_Swipe_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[206], &basic_proc, &null_mcb},
	{_("Swagger"), 85, 0, (pchar*)Swagger_desc, 15, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[207], &basic_proc, &null_mcb},
	{_("Milk Drink"), 101, 0, (pchar*)Milk_Drink_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[208], &basic_proc, &null_mcb},
	{_("Spark"), 100, 65, (pchar*)Spark_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[209], &basic_proc, &null_mcb},
	{_("Fury Cutter"), 95, 40, (pchar*)Fury_Cutter_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[210], &basic_proc, &null_mcb},
	{_("Steel Wing"), 90, 70, (pchar*)Steel_Wing_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[211], &basic_proc, &null_mcb},
	{_("Mean Look"), 101, 0, (pchar*)Mean_Look_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[212], &basic_proc, &null_mcb},
	{_("Attract"), 100, 0, (pchar*)Attract_desc, 15, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[213], &basic_proc, &null_mcb},
	{_("Sleep Talk"), 101, 0, (pchar*)Sleep_Talk_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[214], &basic_proc, &null_mcb},
	{_("Heal Bell"), 101, 0, (pchar*)Heal_Bell_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[215], &basic_proc, &null_mcb},
	{_("Return"), 100, 0, (pchar*)Return_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[216], &basic_proc, &null_mcb},
	{_("Present"), 90, 0, (pchar*)Present_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[217], &basic_proc, &null_mcb},
	{_("Frustration"), 100, 0, (pchar*)Frustration_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[218], &basic_proc, &null_mcb},
	{_("Safeguard"), 101, 0, (pchar*)Safeguard_desc, 25, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[219], &basic_proc, &null_mcb},
	{_("Pain Split"), 101, 0, (pchar*)Pain_Split_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[220], &basic_proc, &null_mcb},
	{_("Sacred Fire"), 95, 100, (pchar*)Sacred_Fire_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[221], &basic_proc, &null_mcb},
	{_("Magnitude"), 100, 0, (pchar*)Magnitude_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[222], &basic_proc, &null_mcb},
	{_("Dynamic Punch"), 50, 100, (pchar*)Dynamic_Punch_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[223], &basic_proc, &null_mcb},
	{_("Megahorn"), 85, 120, (pchar*)Megahorn_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[224], &basic_proc, &null_mcb},
	{_("Dragon Breath"), 100, 60, (pchar*)Dragon_Breath_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_DRAGON, &m_flags[225], &basic_proc, &null_mcb},
	{_("Baton Pass"), 101, 0, (pchar*)Baton_Pass_desc, 40, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[226], &basic_proc, &null_mcb},
	{_("Encore"), 100, 0, (pchar*)Encore_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[227], &basic_proc, &null_mcb},
	{_("Pursuit"), 100, 40, (pchar*)Pursuit_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[228], &basic_proc, &null_mcb},
	{_("Rapid Spin"), 100, 20, (pchar*)Rapid_Spin_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[229], &basic_proc, &null_mcb},
	{_("Sweet Scent"), 100, 0, (pchar*)Sweet_Scent_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[230], &basic_proc, &null_mcb},
	{_("Iron Tail"), 75, 100, (pchar*)Iron_Tail_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[231], &basic_proc, &null_mcb},
	{_("Metal Claw"), 95, 50, (pchar*)Metal_Claw_desc, 35, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[232], &basic_proc, &null_mcb},
	{_("Vital Throw"), 101, 70, (pchar*)Vital_Throw_desc, 10, -1, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[233], &basic_proc, &null_mcb},
	{_("Morning Sun"), 101, 0, (pchar*)Morning_Sun_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[234], &basic_proc, &null_mcb},
	{_("Synthesis"), 101, 0, (pchar*)Synthesis_desc, 5, 0, 1, MOVE_STATUS, MTYPE_GRASS, &m_flags[235], &basic_proc, &null_mcb},
	{_("Moonlight"), 101, 0, (pchar*)Moonlight_desc, 5, 0, 1, MOVE_STATUS, MTYPE_FAIRY, &m_flags[236], &basic_proc, &null_mcb},
	{_("Hidden Power"), 100, 60, (pchar*)Hidden_Power_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[237], &basic_proc, &null_mcb},
	{_("Cross Chop"), 80, 100, (pchar*)Cross_Chop_desc, 5, 0, 2, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[238], &basic_proc, &null_mcb},
	{_("Twister"), 100, 40, (pchar*)Twister_desc, 20, 0, 1, MOVE_SPECIAL, MTYPE_DRAGON, &m_flags[239], &basic_proc, &null_mcb},
	{_("Rain Dance"), 101, 0, (pchar*)Rain_Dance_desc, 5, 0, 1, MOVE_STATUS, MTYPE_WATER, &m_flags[240], &basic_proc, &null_mcb},
	{_("Sunny Day"), 101, 0, (pchar*)Sunny_Day_desc, 5, 0, 1, MOVE_STATUS, MTYPE_FIRE, &m_flags[241], &basic_proc, &null_mcb},
	{_("Crunch"), 100, 80, (pchar*)Crunch_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[242], &basic_proc, &null_mcb},
	{_("Mirror Coat"), 100, 0, (pchar*)Mirror_Coat_desc, 20, -5, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[243], &basic_proc, &null_mcb},
	{_("Psych Up"), 101, 0, (pchar*)Psych_Up_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[244], &basic_proc, &null_mcb},
	{_("Extreme Speed"), 100, 80, (pchar*)Extreme_Speed_desc, 5, 2, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[245], &basic_proc, &null_mcb},
	{_("Ancient Power"), 100, 60, (pchar*)Ancient_Power_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_ROCK, &m_flags[246], &basic_proc, &null_mcb},
	{_("Shadow Ball"), 100, 80, (pchar*)Shadow_Ball_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_GHOST, &m_flags[247], &basic_proc, &null_mcb},
	{_("Future Sight"), 100, 120, (pchar*)Future_Sight_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_PSYCHIC, &m_flags[248], &basic_proc, &null_mcb},
	{_("Rock Smash"), 100, 40, (pchar*)Rock_Smash_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[249], &basic_proc, &null_mcb},
	{_("Whirlpool"), 85, 35, (pchar*)Whirlpool_desc, 15, 0, 1, MOVE_SPECIAL, MTYPE_WATER, &m_flags[250], &basic_proc, &null_mcb},
	{_("Beat Up"), 100, 0, (pchar*)Beat_Up_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[251], &basic_proc, &null_mcb},
	{_("Fake Out"), 100, 40, (pchar*)Fake_Out_desc, 10, 3, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[252], &basic_proc, &null_mcb},
	{_("Uproar"), 100, 90, (pchar*)Uproar_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_NORMAL, &m_flags[253], &basic_proc, &null_mcb},
	{_("Stockpile"), 101, 0, (pchar*)Stockpile_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[254], &basic_proc, &null_mcb},
	{_("Spit Up"), 100, 0, (pchar*)Spit_Up_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[255], &basic_proc, &null_mcb},
	{_("Swallow"), 101, 0, (pchar*)Swallow_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[256], &basic_proc, &null_mcb},
	{_("Heat Wave"), 90, 95, (pchar*)Heat_Wave_desc, 10, 0, 1, MOVE_SPECIAL, MTYPE_FIRE, &m_flags[257], &basic_proc, &null_mcb},
	{_("Hail"), 101, 0, (pchar*)Hail_desc, 10, 0, 1, MOVE_STATUS, MTYPE_ICE, &m_flags[258], &basic_proc, &null_mcb},
	{_("Torment"), 100, 0, (pchar*)Torment_desc, 15, 0, 1, MOVE_STATUS, MTYPE_DARK, &m_flags[259], &basic_proc, &null_mcb},
	{_("Flatter"), 100, 0, (pchar*)Flatter_desc, 15, 0, 1, MOVE_STATUS, MTYPE_DARK, &m_flags[260], &basic_proc, &null_mcb},
	{_("Will-O-Wisp"), 85, 0, (pchar*)Will_O_Wisp_desc, 15, 0, 1, MOVE_STATUS, MTYPE_FIRE, &m_flags[261], &basic_proc, &null_mcb},
	{_("Memento"), 100, 0, (pchar*)Memento_desc, 10, 0, 1, MOVE_STATUS, MTYPE_DARK, &m_flags[262], &basic_proc, &null_mcb},
	{_("Facade"), 100, 70, (pchar*)Facade_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[263], &basic_proc, &null_mcb},
	{_("Focus Punch"), 100, 150, (pchar*)Focus_Punch_desc, 20, -3, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[264], &basic_proc, &null_mcb},
	{_("Smelling Salts"), 100, 70, (pchar*)Smelling_Salts_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[265], &basic_proc, &null_mcb},
	{_("Follow Me"), 101, 0, (pchar*)Follow_Me_desc, 20, 2, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[266], &basic_proc, &null_mcb},
	{_("Nature Power"), 101, 0, (pchar*)Nature_Power_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[267], &basic_proc, &null_mcb},
	{_("Charge"), 101, 0, (pchar*)Charge_desc, 20, 0, 1, MOVE_STATUS, MTYPE_ELECTRIC, &m_flags[268], &basic_proc, &null_mcb},
	{_("Taunt"), 100, 0, (pchar*)Taunt_desc, 20, 0, 1, MOVE_STATUS, MTYPE_DARK, &m_flags[269], &basic_proc, &null_mcb},
	{_("Helping Hand"), 101, 0, (pchar*)Helping_Hand_desc, 20, 5, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[270], &basic_proc, &null_mcb},
	{_("Trick"), 100, 0, (pchar*)Trick_desc, 10, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[271], &basic_proc, &null_mcb},
	{_("Role Play"), 101, 0, (pchar*)Role_Play_desc, 10, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[272], &basic_proc, &null_mcb},
	{_("Wish"), 101, 0, (pchar*)Wish_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[273], &basic_proc, &null_mcb},
	{_("Assist"), 101, 0, (pchar*)Assist_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[274], &basic_proc, &null_mcb},
	{_("Ingrain"), 101, 0, (pchar*)Ingrain_desc, 20, 0, 1, MOVE_STATUS, MTYPE_GRASS, &m_flags[275], &basic_proc, &null_mcb},
	{_("Superpower"), 100, 120, (pchar*)Superpower_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[276], &basic_proc, &null_mcb},
	{_("Magic Coat"), 101, 0, (pchar*)Magic_Coat_desc, 15, 4, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[277], &basic_proc, &null_mcb},
	{_("Recycle"), 101, 0, (pchar*)Recycle_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[278], &basic_proc, &null_mcb},
	{_("Revenge"), 100, 60, (pchar*)Revenge_desc, 10, -4, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[279], &basic_proc, &null_mcb},
	{_("Brick Break"), 100, 75, (pchar*)Brick_Break_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[280], &basic_proc, &null_mcb},
	{_("Yawn"), 101, 0, (pchar*)Yawn_desc, 10, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[281], &basic_proc, &null_mcb},
	{_("Knock Off"), 100, 65, (pchar*)Knock_Off_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[282], &basic_proc, &null_mcb},
	{_("Endeavor"), 100, 0, (pchar*)Endeavor_desc, 5, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[283], &basic_proc, &null_mcb},
	{_("Eruption"), 100, 150, (pchar*)Eruption_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_FIRE, &m_flags[284], &basic_proc, &null_mcb},
	{_("Skill Swap"), 101, 0, (pchar*)Skill_Swap_desc, 10, 0, 1,MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[285], &basic_proc, &null_mcb},
	{_("Imprison"), 101, 0, (pchar*)Imprison_desc, 10, 0, 1, MOVE_STATUS, MTYPE_PSYCHIC, &m_flags[286], &basic_proc, &null_mcb},
	{_("Refresh"), 101, 0, (pchar*)Refresh_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[287], &basic_proc, &null_mcb},
	{_("Grudge"), 101, 0, (pchar*)Grudge_desc, 5, 0, 1, MOVE_STATUS, MTYPE_GHOST, &m_flags[288], &basic_proc, &null_mcb},
	{_("Snatch"), 101, 0, (pchar*)Snatch_desc, 10, 4, 1, MOVE_STATUS, MTYPE_DARK, &m_flags[289], &basic_proc, &null_mcb},
	{_("Secret Power"), 100, 70, (pchar*)Secret_Power_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[290], &basic_proc, &null_mcb},
	{_("Dive"), 100, 80, (pchar*)Dive_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[291], &basic_proc, &null_mcb},
	{_("Arm Thrust"), 100, 15, (pchar*)Arm_Thrust_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[292], &basic_proc, &null_mcb},
	{_("Camouflage"), 101, 0, (pchar*)Camouflage_desc, 20, 0, 1, MOVE_STATUS, MTYPE_NORMAL, &m_flags[293], &basic_proc, &null_mcb},
	{_("Tail Glow"), 101, 0, (pchar*)Tail_Glow_desc, 20, 0, 1, MOVE_STATUS, MTYPE_BUG, &m_flags[294], &basic_proc, &null_mcb},
	{_("Luster Purge"), 100, 70, (pchar*)Luster_Purge_desc, 5, 0, 1, MOVE_SPECIAL, MTYPE_PSYCHIC, &m_flags[295], &basic_proc, &null_mcb},
	{_("Mist Ball"), 100, 70, (pchar*)Mist_Ball_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[296], &basic_proc, &null_mcb},
	{_("Feather Dance"), 100, 0, (pchar*)Feather_Dance_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[297], &basic_proc, &null_mcb},
	{_("Teeter Dance"), 100, 0, (pchar*)Teeter_Dance_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[298], &basic_proc, &null_mcb},
	{_("Blaze Kick"), 90, 85, (pchar*)Blaze_Kick_desc, 10, 0, 2, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[299], &basic_proc, &null_mcb},
	{_("Mud Sport"), 101, 0, (pchar*)Mud_Sport_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[300], &basic_proc, &null_mcb},
	{_("Ice Ball"), 90, 30, (pchar*)Ice_Ball_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[301], &basic_proc, &null_mcb},
	{_("Needle Arm"), 100, 60, (pchar*)Needle_Arm_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[302], &basic_proc, &null_mcb},
	{_("Slack Off"), 101, 0, (pchar*)Slack_Off_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[303], &basic_proc, &null_mcb},
	{_("Hyper Voice"), 100, 90, (pchar*)Hyper_Voice_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[304], &basic_proc, &null_mcb},
	{_("Poison Fang"), 100, 50, (pchar*)Poison_Fang_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[305], &basic_proc, &null_mcb},
	{_("Crush Claw"), 95, 75, (pchar*)Crush_Claw_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[306], &basic_proc, &null_mcb},
	{_("Blast Burn"), 90, 150, (pchar*)Blast_Burn_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[307], &basic_proc, &null_mcb},
	{_("Hydro Cannon"), 90, 150, (pchar*)Hydro_Cannon_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[308], &basic_proc, &null_mcb},
	{_("Meteor Mash"), 90, 90, (pchar*)Meteor_Mash_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[309], &basic_proc, &null_mcb},
	{_("Astonish"), 100, 30, (pchar*)Astonish_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[310], &basic_proc, &null_mcb},
	{_("Weather Ball"), 100, 50, (pchar*)Weather_Ball_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[311], &basic_proc, &null_mcb},
	{_("Aromatherapy"), 101, 0, (pchar*)Aromatherapy_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[312], &basic_proc, &null_mcb},
	{_("Fake Tears"), 100, 0, (pchar*)Fake_Tears_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[313], &basic_proc, &null_mcb},
	{_("Air Cutter"), 95, 60, (pchar*)Air_Cutter_desc, 25, 0, 2, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[314], &basic_proc, &null_mcb},
	{_("Overheat"), 90, 130, (pchar*)Overheat_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[315], &basic_proc, &null_mcb},
	{_("Odor Sleuth"), 101, 0, (pchar*)Odor_Sleuth_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[316], &basic_proc, &null_mcb},
	{_("Rock Tomb"), 95, 60, (pchar*)Rock_Tomb_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[317], &basic_proc, &null_mcb},
	{_("Silver Wind"), 100, 60, (pchar*)Silver_Wind_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[318], &basic_proc, &null_mcb},
	{_("Metal Sound"), 85, 0, (pchar*)Metal_Sound_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[319], &basic_proc, &null_mcb},
	{_("Grass Whistle"), 55, 0, (pchar*)Grass_Whistle_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[320], &basic_proc, &null_mcb},
	{_("Tickle"), 100, 0, (pchar*)Tickle_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[321], &basic_proc, &null_mcb},
	{_("Cosmic Power"), 101, 0, (pchar*)Cosmic_Power_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[322], &basic_proc, &null_mcb},
	{_("Water Spout"), 100, 150, (pchar*)Water_Spout_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[323], &basic_proc, &null_mcb},
	{_("Signal Beam"), 100, 75, (pchar*)Signal_Beam_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[324], &basic_proc, &null_mcb},
	{_("Shadow Punch"), 101, 60, (pchar*)Shadow_Punch_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[325], &basic_proc, &null_mcb},
	{_("Extrasensory"), 100, 80, (pchar*)Extrasensory_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[326], &basic_proc, &null_mcb},
	{_("Sky Uppercut"), 90, 85, (pchar*)Sky_Uppercut_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[327], &basic_proc, &null_mcb},
	{_("Sand Tomb"), 85, 35, (pchar*)Sand_Tomb_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[328], &basic_proc, &null_mcb},
	{_("Sheer Cold"), 30, 0, (pchar*)Sheer_Cold_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[329], &basic_proc, &null_mcb},
	{_("Muddy Water"), 85, 90, (pchar*)Muddy_Water_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[330], &basic_proc, &null_mcb},
	{_("Bullet Seed"), 100, 25, (pchar*)Bullet_Seed_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[331], &basic_proc, &null_mcb},
	{_("Aerial Ace"), 101, 60, (pchar*)Aerial_Ace_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[332], &basic_proc, &null_mcb},
	{_("Icicle Spear"), 100, 25, (pchar*)Icicle_Spear_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[333], &basic_proc, &null_mcb},
	{_("Iron Defense"), 101, 0, (pchar*)Iron_Defense_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[334], &basic_proc, &null_mcb},
	{_("Block"), 101, 0, (pchar*)Block_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[335], &basic_proc, &null_mcb},
	{_("Howl"), 101, 0, (pchar*)Howl_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[336], &basic_proc, &null_mcb},
	{_("Dragon Claw"), 100, 80, (pchar*)Dragon_Claw_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[337], &basic_proc, &null_mcb},
	{_("Frenzy Plant"), 90, 150, (pchar*)Frenzy_Plant_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[338], &basic_proc, &null_mcb},
	{_("Bulk Up"), 101, 0, (pchar*)Bulk_Up_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[339], &basic_proc, &null_mcb},
	{_("Bounce"), 85, 85, (pchar*)Bounce_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[340], &basic_proc, &null_mcb},
	{_("Mud Shot"), 95, 55, (pchar*)Mud_Shot_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[341], &basic_proc, &null_mcb},
	{_("Poison Tail"), 100, 50, (pchar*)Poison_Tail_desc, 25, 0, 2, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[342], &basic_proc, &null_mcb},
	{_("Covet"), 100, 60, (pchar*)Covet_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[343], &basic_proc, &null_mcb},
	{_("Volt Tackle"), 100, 120, (pchar*)Volt_Tackle_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[344], &basic_proc, &null_mcb},
	{_("Magical Leaf"), 101, 60, (pchar*)Magical_Leaf_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[345], &basic_proc, &null_mcb},
	{_("Water Sport"), 101, 0, (pchar*)Water_Sport_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[346], &basic_proc, &null_mcb},
	{_("Calm Mind"), 101, 0, (pchar*)Calm_Mind_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[347], &basic_proc, &null_mcb},
	{_("Leaf Blade"), 100, 90, (pchar*)Leaf_Blade_desc, 15, 0, 2, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[348], &basic_proc, &null_mcb},
	{_("Dragon Dance"), 101, 0, (pchar*)Dragon_Dance_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[349], &basic_proc, &null_mcb},
	{_("Rock Blast"), 90, 25, (pchar*)Rock_Blast_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[350], &basic_proc, &null_mcb},
	{_("Shock Wave"), 101, 60, (pchar*)Shock_Wave_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[351], &basic_proc, &null_mcb},
	{_("Water Pulse"), 100, 60, (pchar*)Water_Pulse_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[352], &basic_proc, &null_mcb},
	{_("Doom Desire"), 100, 140, (pchar*)Doom_Desire_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[353], &basic_proc, &null_mcb},
	{_("Psycho Boost"), 90, 140, (pchar*)Psycho_Boost_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[354], &basic_proc, &null_mcb},
	{_("Roost"), 101, 0, (pchar*)Roost_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[355], &basic_proc, &null_mcb},
	{_("Gravity"), 101, 0, (pchar*)Gravity_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[356], &basic_proc, &null_mcb},
	{_("Miracle Eye"), 101, 0, (pchar*)Miracle_Eye_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[357], &basic_proc, &null_mcb},
	{_("Wake-Up Slap"), 100, 70, (pchar*)Wake_Up_Slap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[358], &basic_proc, &null_mcb},
	{_("Hammer Arm"), 90, 100, (pchar*)Hammer_Arm_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[359], &basic_proc, &null_mcb},
	{_("Gyro Ball"), 100, 0, (pchar*)Gyro_Ball_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[360], &basic_proc, &null_mcb},
	{_("Healing Wish"), 101, 0, (pchar*)Healing_Wish_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[361], &basic_proc, &null_mcb},
	{_("Brine"), 100, 65, (pchar*)Brine_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[362], &basic_proc, &null_mcb},
	{_("Natural Gift"), 100, 0, (pchar*)Natural_Gift_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[363], &basic_proc, &null_mcb},
	{_("Feint"), 100, 30, (pchar*)Feint_desc, 10, 2, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[364], &basic_proc, &null_mcb},
	{_("Pluck"), 100, 60, (pchar*)Pluck_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[365], &basic_proc, &null_mcb},
	{_("Tailwind"), 101, 0, (pchar*)Tailwind_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[366], &basic_proc, &null_mcb},
	{_("Acupressure"), 101, 0, (pchar*)Acupressure_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[367], &basic_proc, &null_mcb},
	{_("Metal Burst"), 100, 0, (pchar*)Metal_Burst_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[368], &basic_proc, &null_mcb},
	{_("U-turn"), 100, 70, (pchar*)U_turn_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[369], &basic_proc, &null_mcb},
	{_("Close Combat"), 100, 120, (pchar*)Close_Combat_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[370], &basic_proc, &null_mcb},
	{_("Payback"), 100, 50, (pchar*)Payback_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[371], &basic_proc, &null_mcb},
	{_("Assurance"), 100, 60, (pchar*)Assurance_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[372], &basic_proc, &null_mcb},
	{_("Embargo"), 100, 0, (pchar*)Embargo_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[373], &basic_proc, &null_mcb},
	{_("Fling"), 100, 0, (pchar*)Fling_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[374], &basic_proc, &null_mcb},
	{_("Psycho Shift"), 100, 0, (pchar*)Psycho_Shift_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[375], &basic_proc, &null_mcb},
	{_("Trump Card"), 101, 0, (pchar*)Trump_Card_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[376], &basic_proc, &null_mcb},
	{_("Heal Block"), 100, 0, (pchar*)Heal_Block_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[377], &basic_proc, &null_mcb},
	{_("Wring Out"), 100, 0, (pchar*)Wring_Out_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[378], &basic_proc, &null_mcb},
	{_("Power Trick"), 101, 0, (pchar*)Power_Trick_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[379], &basic_proc, &null_mcb},
	{_("Gastro Acid"), 100, 0, (pchar*)Gastro_Acid_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[380], &basic_proc, &null_mcb},
	{_("Lucky Chant"), 101, 0, (pchar*)Lucky_Chant_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[381], &basic_proc, &null_mcb},
	{_("Me First"), 101, 0, (pchar*)Me_First_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[382], &basic_proc, &null_mcb},
	{_("Copycat"), 101, 0, (pchar*)Copycat_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[383], &basic_proc, &null_mcb},
	{_("Power Swap"), 101, 0, (pchar*)Power_Swap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[384], &basic_proc, &null_mcb},
	{_("Guard Swap"), 101, 0, (pchar*)Guard_Swap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[385], &basic_proc, &null_mcb},
	{_("Punishment"), 100, 0, (pchar*)Punishment_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[386], &basic_proc, &null_mcb},
	{_("Last Resort"), 100, 140, (pchar*)Last_Resort_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[387], &basic_proc, &null_mcb},
	{_("Worry Seed"), 100, 0, (pchar*)Worry_Seed_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[388], &basic_proc, &null_mcb},
	{_("Sucker Punch"), 100, 70, (pchar*)Sucker_Punch_desc, 5, 1, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[389], &basic_proc, &null_mcb},
	{_("Toxic Spikes"), 101, 0, (pchar*)Toxic_Spikes_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[390], &basic_proc, &null_mcb},
	{_("Heart Swap"), 101, 0, (pchar*)Heart_Swap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[391], &basic_proc, &null_mcb},
	{_("Aqua Ring"), 101, 0, (pchar*)Aqua_Ring_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[392], &basic_proc, &null_mcb},
	{_("Magnet Rise"), 101, 0, (pchar*)Magnet_Rise_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[393], &basic_proc, &null_mcb},
	{_("Flare Blitz"), 100, 120, (pchar*)Flare_Blitz_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[394], &basic_proc, &null_mcb},
	{_("Force Palm"), 100, 60, (pchar*)Force_Palm_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[395], &basic_proc, &null_mcb},
	{_("Aura Sphere"), 101, 80, (pchar*)Aura_Sphere_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[396], &basic_proc, &null_mcb},
	{_("Rock Polish"), 101, 0, (pchar*)Rock_Polish_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[397], &basic_proc, &null_mcb},
	{_("Poison Jab"), 100, 80, (pchar*)Poison_Jab_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[398], &basic_proc, &null_mcb},
	{_("Dark Pulse"), 100, 80, (pchar*)Dark_Pulse_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[399], &basic_proc, &null_mcb},
	{_("Night Slash"), 100, 70, (pchar*)Night_Slash_desc, 15, 0, 2, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[400], &basic_proc, &null_mcb},
	{_("Aqua Tail"), 90, 90, (pchar*)Aqua_Tail_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[401], &basic_proc, &null_mcb},
	{_("Seed Bomb"), 100, 80, (pchar*)Seed_Bomb_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[402], &basic_proc, &null_mcb},
	{_("Air Slash"), 95, 75, (pchar*)Air_Slash_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[403], &basic_proc, &null_mcb},
	{_("X-Scissor"), 100, 80, (pchar*)X_Scissor_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[404], &basic_proc, &null_mcb},
	{_("Bug Buzz"), 100, 90, (pchar*)Bug_Buzz_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[405], &basic_proc, &null_mcb},
	{_("Dragon Pulse"), 100, 85, (pchar*)Dragon_Pulse_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[406], &basic_proc, &null_mcb},
	{_("Dragon Rush"), 75, 100, (pchar*)Dragon_Rush_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[407], &basic_proc, &null_mcb},
	{_("Power Gem"), 100, 80, (pchar*)Power_Gem_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[408], &basic_proc, &null_mcb},
	{_("Drain Punch"), 100, 75, (pchar*)Drain_Punch_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[409], &basic_proc, &null_mcb},
	{_("Vacuum Wave"), 100, 40, (pchar*)Vacuum_Wave_desc, 30, 1, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[410], &basic_proc, &null_mcb},
	{_("Focus Blast"), 70, 120, (pchar*)Focus_Blast_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[411], &basic_proc, &null_mcb},
	{_("Energy Ball"), 100, 90, (pchar*)Energy_Ball_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[412], &basic_proc, &null_mcb},
	{_("Brave Bird"), 100, 120, (pchar*)Brave_Bird_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[413], &basic_proc, &null_mcb},
	{_("Earth Power"), 100, 90, (pchar*)Earth_Power_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[414], &basic_proc, &null_mcb},
	{_("Switcheroo"), 100, 0, (pchar*)Switcheroo_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[415], &basic_proc, &null_mcb},
	{_("Giga Impact"), 90, 150, (pchar*)Giga_Impact_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[416], &basic_proc, &null_mcb},
	{_("Nasty Plot"), 101, 0, (pchar*)Nasty_Plot_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[417], &basic_proc, &null_mcb},
	{_("Bullet Punch"), 100, 40, (pchar*)Bullet_Punch_desc, 30, 1, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[418], &basic_proc, &null_mcb},
	{_("Avalanche"), 100, 60, (pchar*)Avalanche_desc, 10, -4, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[419], &basic_proc, &null_mcb},
	{_("Ice Shard"), 100, 40, (pchar*)Ice_Shard_desc, 30, 1, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[420], &basic_proc, &null_mcb},
	{_("Shadow Claw"), 100, 70, (pchar*)Shadow_Claw_desc, 15, 0, 2, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[421], &basic_proc, &null_mcb},
	{_("Thunder Fang"), 95, 65, (pchar*)Thunder_Fang_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[422], &basic_proc, &null_mcb},
	{_("Ice Fang"), 95, 65, (pchar*)Ice_Fang_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[423], &basic_proc, &null_mcb},
	{_("Fire Fang"), 95, 65, (pchar*)Fire_Fang_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[424], &basic_proc, &null_mcb},
	{_("Shadow Sneak"), 100, 40, (pchar*)Shadow_Sneak_desc, 30, 1, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[425], &basic_proc, &null_mcb},
	{_("Mud Bomb"), 85, 65, (pchar*)Mud_Bomb_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[426], &basic_proc, &null_mcb},
	{_("Psycho Cut"), 100, 70, (pchar*)Psycho_Cut_desc, 20, 0, 2, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[427], &basic_proc, &null_mcb},
	{_("Zen Headbutt"), 90, 80, (pchar*)Zen_Headbutt_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[428], &basic_proc, &null_mcb},
	{_("Mirror Shot"), 85, 65, (pchar*)Mirror_Shot_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[429], &basic_proc, &null_mcb},
	{_("Flash Cannon"), 100, 80, (pchar*)Flash_Cannon_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[430], &basic_proc, &null_mcb},
	{_("Rock Climb"), 85, 90, (pchar*)Rock_Climb_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[431], &basic_proc, &null_mcb},
	{_("Defog"), 101, 0, (pchar*)Defog_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[432], &basic_proc, &null_mcb},
	{_("Trick Room"), 101, 0, (pchar*)Trick_Room_desc, 5, -7, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[433], &basic_proc, &null_mcb},
	{_("Draco Meteor"), 90, 130, (pchar*)Draco_Meteor_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[434], &basic_proc, &null_mcb},
	{_("Discharge"), 100, 80, (pchar*)Discharge_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[435], &basic_proc, &null_mcb},
	{_("Lava Plume"), 100, 80, (pchar*)Lava_Plume_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[436], &basic_proc, &null_mcb},
	{_("Leaf Storm"), 90, 130, (pchar*)Leaf_Storm_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[437], &basic_proc, &null_mcb},
	{_("Power Whip"), 85, 120, (pchar*)Power_Whip_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[438], &basic_proc, &null_mcb},
	{_("Rock Wrecker"), 90, 150, (pchar*)Rock_Wrecker_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[439], &basic_proc, &null_mcb},
	{_("Cross Poison"), 100, 70, (pchar*)Cross_Poison_desc, 20, 0, 2, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[440], &basic_proc, &null_mcb},
	{_("Gunk Shot"), 80, 120, (pchar*)Gunk_Shot_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[441], &basic_proc, &null_mcb},
	{_("Iron Head"), 100, 80, (pchar*)Iron_Head_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[442], &basic_proc, &null_mcb},
	{_("Magnet Bomb"), 101, 60, (pchar*)Magnet_Bomb_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[443], &basic_proc, &null_mcb},
	{_("Stone Edge"), 80, 100, (pchar*)Stone_Edge_desc, 5, 0, 2, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[444], &basic_proc, &null_mcb},
	{_("Captivate"), 100, 0, (pchar*)Captivate_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[445], &basic_proc, &null_mcb},
	{_("Stealth Rock"), 101, 0, (pchar*)Stealth_Rock_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[446], &basic_proc, &null_mcb},
	{_("Grass Knot"), 100, 0, (pchar*)Grass_Knot_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[447], &basic_proc, &null_mcb},
	{_("Chatter"), 100, 65, (pchar*)Chatter_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[448], &basic_proc, &null_mcb},
	{_("Judgment"), 100, 100, (pchar*)Judgment_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[449], &basic_proc, &null_mcb},
	{_("Bug Bite"), 100, 60, (pchar*)Bug_Bite_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[450], &basic_proc, &null_mcb},
	{_("Charge Beam"), 90, 50, (pchar*)Charge_Beam_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[451], &basic_proc, &null_mcb},
	{_("Wood Hammer"), 100, 120, (pchar*)Wood_Hammer_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[452], &basic_proc, &null_mcb},
	{_("Aqua Jet"), 100, 40, (pchar*)Aqua_Jet_desc, 20, 1, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[453], &basic_proc, &null_mcb},
	{_("Attack Order"), 100, 90, (pchar*)Attack_Order_desc, 15, 0, 2, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[454], &basic_proc, &null_mcb},
	{_("Defend Order"), 101, 0, (pchar*)Defend_Order_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[455], &basic_proc, &null_mcb},
	{_("Heal Order"), 101, 0, (pchar*)Heal_Order_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[456], &basic_proc, &null_mcb},
	{_("Head Smash"), 80, 150, (pchar*)Head_Smash_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[457], &basic_proc, &null_mcb},
	{_("Double Hit"), 90, 35, (pchar*)Double_Hit_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[458], &basic_doublehit_proc, &null_mcb},
	{_("Roar of Time"), 90, 150, (pchar*)Roar_of_Time_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[459], &basic_proc, &null_mcb},
	{_("Spacial Rend"), 95, 100, (pchar*)Spacial_Rend_desc, 5, 0, 2, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[460], &basic_proc, &null_mcb},
	{_("Lunar Dance"), 101, 0, (pchar*)Lunar_Dance_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[461], &basic_proc, &null_mcb},
	{_("Crush Grip"), 100, 0, (pchar*)Crush_Grip_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[462], &basic_proc, &null_mcb},
	{_("Magma Storm"), 75, 100, (pchar*)Magma_Storm_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[463], &basic_proc, &null_mcb},
	{_("Dark Void"), 50, 0, (pchar*)Dark_Void_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[464], &basic_proc, &null_mcb},
	{_("Seed Flare"), 85, 120, (pchar*)Seed_Flare_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[465], &basic_proc, &null_mcb},
	{_("Ominous Wind"), 100, 60, (pchar*)Ominous_Wind_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[466], &basic_proc, &null_mcb},
	{_("Shadow Force"), 100, 120, (pchar*)Shadow_Force_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[467], &basic_proc, &null_mcb},
	{_("Hone Claws"), 101, 0, (pchar*)Hone_Claws_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[468], &basic_proc, &null_mcb},
	{_("Wide Guard"), 101, 0, (pchar*)Wide_Guard_desc, 10, 3, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[469], &basic_proc, &null_mcb},
	{_("Guard Split"), 101, 0, (pchar*)Guard_Split_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[470], &basic_proc, &null_mcb},
	{_("Power Split"), 101, 0, (pchar*)Power_Split_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[471], &basic_proc, &null_mcb},
	{_("Wonder Room"), 101, 0, (pchar*)Wonder_Room_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[472], &basic_proc, &null_mcb},
	{_("Psyshock"), 100, 80, (pchar*)Psyshock_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[473], &basic_proc, &null_mcb},
	{_("Venoshock"), 100, 65, (pchar*)Venoshock_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[474], &basic_proc, &null_mcb},
	{_("Autotomize"), 101, 0, (pchar*)Autotomize_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[475], &basic_proc, &null_mcb},
	{_("Rage Powder"), 101, 0, (pchar*)Rage_Powder_desc, 20, 2, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[476], &basic_proc, &null_mcb},
	{_("Telekinesis"), 101, 0, (pchar*)Telekinesis_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[477], &basic_proc, &null_mcb},
	{_("Magic Room"), 101, 0, (pchar*)Magic_Room_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[478], &basic_proc, &null_mcb},
	{_("Smack Down"), 100, 50, (pchar*)Smack_Down_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[479], &basic_proc, &null_mcb},
	{_("Storm Throw"), 100, 60, (pchar*)Storm_Throw_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[480], &basic_proc, &null_mcb},
	{_("Flame Burst"), 100, 70, (pchar*)Flame_Burst_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[481], &basic_proc, &null_mcb},
	{_("Sludge Wave"), 100, 95, (pchar*)Sludge_Wave_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[482], &basic_proc, &null_mcb},
	{_("Quiver Dance"), 101, 0, (pchar*)Quiver_Dance_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[483], &basic_proc, &null_mcb},
	{_("Heavy Slam"), 100, 0, (pchar*)Heavy_Slam_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[484], &basic_proc, &null_mcb},
	{_("Synchronoise"), 100, 120, (pchar*)Synchronoise_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[485], &basic_proc, &null_mcb},
	{_("Electro Ball"), 100, 0, (pchar*)Electro_Ball_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[486], &basic_proc, &null_mcb},
	{_("Soak"), 100, 0, (pchar*)Soak_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[487], &basic_proc, &null_mcb},
	{_("Flame Charge"), 100, 50, (pchar*)Flame_Charge_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[488], &basic_proc, &null_mcb},
	{_("Coil"), 101, 0, (pchar*)Coil_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[489], &basic_proc, &null_mcb},
	{_("Low Sweep"), 100, 65, (pchar*)Low_Sweep_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[490], &basic_proc, &null_mcb},
	{_("Acid Spray"), 100, 40, (pchar*)Acid_Spray_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[491], &basic_proc, &null_mcb},
	{_("Foul Play"), 100, 95, (pchar*)Foul_Play_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[492], &basic_proc, &null_mcb},
	{_("Simple Beam"), 100, 0, (pchar*)Simple_Beam_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[493], &basic_proc, &null_mcb},
	{_("Entrainment"), 100, 0, (pchar*)Entrainment_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[494], &basic_proc, &null_mcb},
	{_("After You"), 101, 0, (pchar*)After_You_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[495], &basic_proc, &null_mcb},
	{_("Round"), 100, 60, (pchar*)Round_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[496], &basic_proc, &null_mcb},
	{_("Echoed Voice"), 100, 40, (pchar*)Echoed_Voice_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[497], &basic_proc, &null_mcb},
	{_("Chip Away"), 100, 70, (pchar*)Chip_Away_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[498], &basic_proc, &null_mcb},
	{_("Clear Smog"), 101, 50, (pchar*)Clear_Smog_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[499], &basic_proc, &null_mcb},
	{_("Stored Power"), 100, 20, (pchar*)Stored_Power_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[500], &basic_proc, &null_mcb},
	{_("Quick Guard"), 101, 0, (pchar*)Quick_Guard_desc, 15, 3, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[501], &basic_proc, &null_mcb},
	{_("Ally Switch"), 101, 0, (pchar*)Ally_Switch_desc, 15, 2, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[502], &basic_proc, &null_mcb},
	{_("Scald"), 100, 80, (pchar*)Scald_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[503], &basic_proc, &null_mcb},
	{_("Shell Smash"), 101, 0, (pchar*)Shell_Smash_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[504], &basic_proc, &null_mcb},
	{_("Heal Pulse"), 101, 0, (pchar*)Heal_Pulse_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[505], &basic_proc, &null_mcb},
	{_("Hex"), 100, 65, (pchar*)Hex_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[506], &basic_proc, &null_mcb},
	{_("Sky Drop"), 100, 60, (pchar*)Sky_Drop_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[507], &basic_proc, &null_mcb},
	{_("Shift Gear"), 101, 0, (pchar*)Shift_Gear_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[508], &basic_proc, &null_mcb},
	{_("Circle Throw"), 90, 60, (pchar*)Circle_Throw_desc, 10, -6, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[509], &basic_proc, &null_mcb},
	{_("Incinerate"), 100, 60, (pchar*)Incinerate_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[510], &basic_proc, &null_mcb},
	{_("Quash"), 100, 0, (pchar*)Quash_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[511], &basic_proc, &null_mcb},
	{_("Acrobatics"), 100, 55, (pchar*)Acrobatics_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[512], &basic_proc, &null_mcb},
	{_("Reflect Type"), 101, 0, (pchar*)Reflect_Type_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[513], &basic_proc, &null_mcb},
	{_("Retaliate"), 100, 70, (pchar*)Retaliate_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[514], &basic_proc, &null_mcb},
	{_("Final Gambit"), 100, 0, (pchar*)Final_Gambit_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[515], &basic_proc, &null_mcb},
	{_("Bestow"), 101, 0, (pchar*)Bestow_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[516], &basic_proc, &null_mcb},
	{_("Inferno"), 50, 100, (pchar*)Inferno_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[517], &basic_proc, &null_mcb},
	{_("Water Pledge"), 100, 80, (pchar*)Water_Pledge_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[518], &basic_proc, &null_mcb},
	{_("Fire Pledge"), 100, 80, (pchar*)Fire_Pledge_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[519], &basic_proc, &null_mcb},
	{_("Grass Pledge"), 100, 80, (pchar*)Grass_Pledge_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[520], &basic_proc, &null_mcb},
	{_("Volt Switch"), 100, 70, (pchar*)Volt_Switch_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[521], &basic_proc, &null_mcb},
	{_("Struggle Bug"), 100, 50, (pchar*)Struggle_Bug_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[522], &basic_proc, &null_mcb},
	{_("Bulldoze"), 100, 60, (pchar*)Bulldoze_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[523], &basic_proc, &null_mcb},
	{_("Frost Breath"), 90, 60, (pchar*)Frost_Breath_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[524], &basic_proc, &null_mcb},
	{_("Dragon Tail"), 90, 60, (pchar*)Dragon_Tail_desc, 10, -6, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[525], &basic_proc, &null_mcb},
	{_("Work Up"), 101, 0, (pchar*)Work_Up_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[526], &basic_proc, &null_mcb},
	{_("Electroweb"), 95, 55, (pchar*)Electroweb_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[527], &basic_proc, &null_mcb},
	{_("Wild Charge"), 100, 90, (pchar*)Wild_Charge_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[528], &basic_proc, &null_mcb},
	{_("Drill Run"), 95, 80, (pchar*)Drill_Run_desc, 10, 0, 2, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[529], &basic_proc, &null_mcb},
	{_("Dual Chop"), 90, 40, (pchar*)Dual_Chop_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[530], &basic_doublehit_proc, &null_mcb},
	{_("Heart Stamp"), 100, 60, (pchar*)Heart_Stamp_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[531], &basic_proc, &null_mcb},
	{_("Horn Leech"), 100, 75, (pchar*)Horn_Leech_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[532], &basic_proc, &null_mcb},
	{_("Sacred Sword"), 100, 90, (pchar*)Sacred_Sword_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[533], &basic_proc, &null_mcb},
	{_("Razor Shell"), 95, 75, (pchar*)Razor_Shell_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[534], &basic_proc, &null_mcb},
	{_("Heat Crash"), 100, 0, (pchar*)Heat_Crash_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[535], &basic_proc, &null_mcb},
	{_("Leaf Tornado"), 90, 65, (pchar*)Leaf_Tornado_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[536], &basic_proc, &null_mcb},
	{_("Steamroller"), 100, 65, (pchar*)Steamroller_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[537], &basic_proc, &null_mcb},
	{_("Cotton Guard"), 101, 0, (pchar*)Cotton_Guard_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[538], &basic_proc, &null_mcb},
	{_("Night Daze"), 95, 85, (pchar*)Night_Daze_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[539], &basic_proc, &null_mcb},
	{_("Psystrike"), 100, 100, (pchar*)Psystrike_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[540], &basic_proc, &null_mcb},
	{_("Tail Slap"), 85, 25, (pchar*)Tail_Slap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[541], &basic_proc, &null_mcb},
	{_("Hurricane"), 70, 110, (pchar*)Hurricane_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[542], &basic_proc, &null_mcb},
	{_("Head Charge"), 100, 120, (pchar*)Head_Charge_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[543], &basic_proc, &null_mcb},
	{_("Gear Grind"), 85, 50, (pchar*)Gear_Grind_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[544], &basic_doublehit_proc, &null_mcb},
	{_("Searing Shot"), 100, 100, (pchar*)Searing_Shot_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[545], &basic_proc, &null_mcb},
	{_("Techno Blast"), 100, 120, (pchar*)Techno_Blast_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[546], &basic_proc, &null_mcb},
	{_("Relic Song"), 100, 75, (pchar*)Relic_Song_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[547], &basic_proc, &null_mcb},
	{_("Secret Sword"), 100, 85, (pchar*)Secret_Sword_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[548], &basic_proc, &null_mcb},
	{_("Glaciate"), 95, 65, (pchar*)Glaciate_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[549], &basic_proc, &null_mcb},
	{_("Bolt Strike"), 85, 130, (pchar*)Bolt_Strike_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[550], &basic_proc, &null_mcb},
	{_("Blue Flare"), 85, 130, (pchar*)Blue_Flare_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[551], &basic_proc, &null_mcb},
	{_("Fiery Dance"), 100, 80, (pchar*)Fiery_Dance_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[552], &basic_proc, &null_mcb},
	{_("Freeze Shock"), 90, 140, (pchar*)Freeze_Shock_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[553], &basic_proc, &null_mcb},
	{_("Ice Burn"), 90, 140, (pchar*)Ice_Burn_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[554], &basic_proc, &null_mcb},
	{_("Snarl"), 95, 55, (pchar*)Snarl_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[555], &basic_proc, &null_mcb},
	{_("Icicle Crash"), 90, 85, (pchar*)Icicle_Crash_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[556], &basic_proc, &null_mcb},
	{_("V-create"), 95, 180, (pchar*)V_create_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[557], &basic_proc, &null_mcb},
	{_("Fusion Flare"), 100, 100, (pchar*)Fusion_Flare_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[558], &basic_proc, &null_mcb},
	{_("Fusion Bolt"), 100, 100, (pchar*)Fusion_Bolt_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[559], &basic_proc, &null_mcb},
	{_("Flying Press"), 95, 100, (pchar*)Flying_Press_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[560], &basic_proc, &null_mcb},
	{_("Mat Block"), 101, 0, (pchar*)Mat_Block_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[561], &basic_proc, &null_mcb},
	{_("Belch"), 90, 120, (pchar*)Belch_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[562], &basic_proc, &null_mcb},
	{_("Rototiller"), 101, 0, (pchar*)Rototiller_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[563], &basic_proc, &null_mcb},
	{_("Sticky Web"), 101, 0, (pchar*)Sticky_Web_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[564], &basic_proc, &null_mcb},
	{_("Fell Stinger"), 100, 50, (pchar*)Fell_Stinger_desc, 25, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[565], &basic_proc, &null_mcb},
	{_("Phantom Force"), 100, 90, (pchar*)Phantom_Force_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[566], &basic_proc, &null_mcb},
	{_("Trick-or-Treat"), 100, 0, (pchar*)Trick_or_Treat_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[567], &basic_proc, &null_mcb},
	{_("Noble Roar"), 100, 0, (pchar*)Noble_Roar_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[568], &basic_proc, &null_mcb},
	{_("Ion Deluge"), 101, 0, (pchar*)Ion_Deluge_desc, 25, 1, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[569], &basic_proc, &null_mcb},
	{_("Parabolic Charge"), 100, 65, (pchar*)Parabolic_Charge_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[570], &basic_proc, &null_mcb},
	{_("Forest‘s Curse"), 100, 0, (pchar*)Forests_Curse_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[571], &basic_proc, &null_mcb},
	{_("Petal Blizzard"), 100, 90, (pchar*)Petal_Blizzard_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[572], &basic_proc, &null_mcb},
	{_("Freeze-Dry"), 100, 70, (pchar*)Freeze_Dry_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[573], &basic_proc, &null_mcb},
	{_("Disarming Voice"), 101, 40, (pchar*)Disarming_Voice_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[574], &basic_proc, &null_mcb},
	{_("Parting Shot"), 100, 0, (pchar*)Parting_Shot_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[575], &basic_proc, &null_mcb},
	{_("Topsy-Turvy"), 101, 0, (pchar*)Topsy_Turvy_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[576], &basic_proc, &null_mcb},
	{_("Draining Kiss"), 100, 50, (pchar*)Draining_Kiss_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[577], &basic_proc, &null_mcb},
	{_("Crafty Shield"), 101, 0, (pchar*)Crafty_Shield_desc, 10, 3, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[578], &basic_proc, &null_mcb},
	{_("Flower Shield"), 101, 0, (pchar*)Flower_Shield_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[579], &basic_proc, &null_mcb},
	{_("Grassy Terrain"), 101, 0, (pchar*)Grassy_Terrain_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[580], &basic_proc, &null_mcb},
	{_("Misty Terrain"), 101, 0, (pchar*)Misty_Terrain_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[581], &basic_proc, &null_mcb},
	{_("Electrify"), 101, 0, (pchar*)Electrify_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[582], &basic_proc, &null_mcb},
	{_("Play Rough"), 90, 90, (pchar*)Play_Rough_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[583], &basic_proc, &null_mcb},
	{_("Fairy Wind"), 100, 40, (pchar*)Fairy_Wind_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[584], &basic_proc, &null_mcb},
	{_("Moonblast"), 100, 95, (pchar*)Moonblast_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[585], &basic_proc, &null_mcb},
	{_("Boomburst"), 100, 140, (pchar*)Boomburst_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[586], &basic_proc, &null_mcb},
	{_("Fairy Lock"), 101, 0, (pchar*)Fairy_Lock_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[587], &basic_proc, &null_mcb},
	{_("King‘s Shield"), 101, 0, (pchar*)Kings_Shield_desc, 10, 4, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[588], &basic_proc, &null_mcb},
	{_("Play Nice"), 101, 0, (pchar*)Play_Nice_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[589], &basic_proc, &null_mcb},
	{_("Confide"), 101, 0, (pchar*)Confide_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[590], &basic_proc, &null_mcb},
	{_("Diamond Storm"), 95, 100, (pchar*)Diamond_Storm_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[591], &basic_proc, &null_mcb},
	{_("Steam Eruption"), 95, 110, (pchar*)Steam_Eruption_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[592], &basic_proc, &null_mcb},
	{_("Hyperspace Hole"), 101, 80, (pchar*)Hyperspace_Hole_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[593], &basic_proc, &null_mcb},
	{_("Water Shuriken"), 100, 15, (pchar*)Water_Shuriken_desc, 20, 1, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[594], &basic_proc, &null_mcb},
	{_("Mystical Fire"), 100, 75, (pchar*)Mystical_Fire_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[595], &basic_proc, &null_mcb},
	{_("Spiky Shield"), 101, 0, (pchar*)Spiky_Shield_desc, 10, 4, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[596], &basic_proc, &null_mcb},
	{_("Aromatic Mist"), 101, 0, (pchar*)Aromatic_Mist_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[597], &basic_proc, &null_mcb},
	{_("Eerie Impulse"), 100, 0, (pchar*)Eerie_Impulse_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[598], &basic_proc, &null_mcb},
	{_("Venom Drench"), 100, 0, (pchar*)Venom_Drench_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[599], &basic_proc, &null_mcb},
	{_("Powder"), 100, 0, (pchar*)Powder_desc, 20, 1, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[600], &basic_proc, &null_mcb},
	{_("Geomancy"), 101, 0, (pchar*)Geomancy_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[601], &basic_proc, &null_mcb},
	{_("Magnetic Flux"), 101, 0, (pchar*)Magnetic_Flux_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[602], &basic_proc, &null_mcb},
	{_("Happy Hour"), 101, 0, (pchar*)Happy_Hour_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[603], &basic_proc, &null_mcb},
	{_("Electric Terrain"), 101, 0, (pchar*)Electric_Terrain_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[604], &basic_proc, &null_mcb},
	{_("Dazzling Gleam"), 100, 80, (pchar*)Dazzling_Gleam_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[605], &basic_proc, &null_mcb},
	{_("Celebrate"), 101, 0, (pchar*)Celebrate_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[606], &basic_proc, &null_mcb},
	{_("Baby-Doll Eyes"), 100, 0, (pchar*)Baby_Doll_Eyes_desc, 30, 1, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[607], &basic_proc, &null_mcb},
	{_("Nuzzle"), 100, 20, (pchar*)Nuzzle_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[608], &basic_proc, &null_mcb},
	{_("Hold Back"), 100, 40, (pchar*)Hold_Back_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[609], &basic_proc, &null_mcb},
	{_("Infestation"), 100, 20, (pchar*)Infestation_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[610], &basic_proc, &null_mcb},
	{_("Power-Up Punch"), 100, 40, (pchar*)Power_Up_Punch_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_FIGHTING, &m_flags[611], &basic_proc, &null_mcb},
	{_("Oblivion Wing"), 100, 80, (pchar*)Oblivion_Wing_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[612], &basic_proc, &null_mcb},
	{_("Thousand Arrows"), 100, 90, (pchar*)Thousand_Arrows_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[613], &basic_proc, &null_mcb},
	{_("Thousand Waves"), 100, 90, (pchar*)Thousand_Waves_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[614], &basic_proc, &null_mcb},
	{_("Hold Hands"), 101, 0, (pchar*)Hold_Hands_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[615], &basic_proc, &null_mcb},
	{_("Land‘s Wrath"), 100, 90, (pchar*)Lands_Wrath_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[616], &basic_proc, &null_mcb},
	{_("Light of Ruin"), 90, 140, (pchar*)Light_of_Ruin_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[617], &basic_proc, &null_mcb},
	{_("Origin Pulse"), 85, 110, (pchar*)Origin_Pulse_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[618], &basic_proc, &null_mcb},
	{_("Precipice Blades"), 85, 120, (pchar*)Precipice_Blades_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[619], &basic_proc, &null_mcb},
	{_("Dragon Ascent"), 100, 120, (pchar*)Dragon_Ascent_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[620], &basic_proc, &null_mcb},
	{_("Hyperspace Fury"), 101, 100, (pchar*)Hyperspace_Fury_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[621], &basic_proc, &null_mcb},
	{_("Shore Up"), 101, 0, (pchar*)Shore_Up_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[622], &basic_proc, &null_mcb},
	{_("First Impression"), 100, 90, (pchar*)First_Impression_desc, 10, 2, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[623], &basic_proc, &null_mcb},
	{_("Baneful Bunker"), 101, 0, (pchar*)Baneful_Bunker_desc, 10, 4, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[624], &basic_proc, &null_mcb},
	{_("Spirit Shackle"), 100, 80, (pchar*)Spirit_Shackle_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[625], &basic_proc, &null_mcb},
	{_("Darkest Lariat"), 100, 85, (pchar*)Darkest_Lariat_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[626], &basic_proc, &null_mcb},
	{_("Sparkling Aria"), 100, 90, (pchar*)Sparkling_Aria_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[627], &basic_proc, &null_mcb},
	{_("Ice Hammer"), 90, 100, (pchar*)Ice_Hammer_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[628], &basic_proc, &null_mcb},
	{_("Floral Healing"), 101, 0, (pchar*)Floral_Healing_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[629], &basic_proc, &null_mcb},
	{_("High Horsepower"), 95, 95, (pchar*)High_Horsepower_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[630], &basic_proc, &null_mcb},
	{_("Strength Sap"), 100, 0, (pchar*)Strength_Sap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[631], &basic_proc, &null_mcb},
	{_("Solar Blade"), 100, 125, (pchar*)Solar_Blade_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[632], &basic_proc, &null_mcb},
	{_("Leafage"), 100, 40, (pchar*)Leafage_desc, 40, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[633], &basic_proc, &null_mcb},
	{_("Spotlight"), 101, 0, (pchar*)Spotlight_desc, 15, 3, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[634], &basic_proc, &null_mcb},
	{_("Toxic Thread"), 100, 0, (pchar*)Toxic_Thread_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[635], &basic_proc, &null_mcb},
	{_("Laser Focus"), 101, 0, (pchar*)Laser_Focus_desc, 30, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[636], &basic_proc, &null_mcb},
	{_("Gear Up"), 101, 0, (pchar*)Gear_Up_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[637], &basic_proc, &null_mcb},
	{_("Throat Chop"), 100, 80, (pchar*)Throat_Chop_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[638], &basic_proc, &null_mcb},
	{_("Pollen Puff"), 100, 90, (pchar*)Pollen_Puff_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[639], &basic_proc, &null_mcb},
	{_("Anchor Shot"), 100, 80, (pchar*)Anchor_Shot_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[640], &basic_proc, &null_mcb},
	{_("Psychic Terrain"), 101, 0, (pchar*)Psychic_Terrain_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[641], &basic_proc, &null_mcb},
	{_("Lunge"), 100, 80, (pchar*)Lunge_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_BUG, &m_flags[642], &basic_proc, &null_mcb},
	{_("Fire Lash"), 100, 80, (pchar*)Fire_Lash_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[643], &basic_proc, &null_mcb},
	{_("Power Trip"), 100, 20, (pchar*)Power_Trip_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[644], &basic_proc, &null_mcb},
	{_("Burn Up"), 100, 130, (pchar*)Burn_Up_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[645], &basic_proc, &null_mcb},
	{_("Speed Swap"), 101, 0, (pchar*)Speed_Swap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[646], &basic_proc, &null_mcb},
	{_("Smart Strike"), 101, 70, (pchar*)Smart_Strike_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[647], &basic_proc, &null_mcb},
	{_("Purify"), 101, 0, (pchar*)Purify_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_POISON, &m_flags[648], &basic_proc, &null_mcb},
	{_("Revelation Dance"), 100, 90, (pchar*)Revelation_Dance_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[649], &basic_proc, &null_mcb},
	{_("Core Enforcer"), 100, 100, (pchar*)Core_Enforcer_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[650], &basic_proc, &null_mcb},
	{_("Trop Kick"), 100, 70, (pchar*)Trop_Kick_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_GRASS, &m_flags[651], &basic_proc, &null_mcb},
	{_("Instruct"), 101, 0, (pchar*)Instruct_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[652], &basic_proc, &null_mcb},
	{_("Beak Blast"), 100, 100, (pchar*)Beak_Blast_desc, 15, -3, 1, MOVE_PHYSICAL, MTYPE_FLYING, &m_flags[653], &basic_proc, &null_mcb},
	{_("Clanging Scales"), 100, 110, (pchar*)Clanging_Scales_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[654], &basic_proc, &null_mcb},
	{_("Dragon Hammer"), 100, 90, (pchar*)Dragon_Hammer_desc, 15, 0, 1, MOVE_PHYSICAL, MTYPE_DRAGON, &m_flags[655], &basic_proc, &null_mcb},
	{_("Brutal Swing"), 100, 60, (pchar*)Brutal_Swing_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_DARK, &m_flags[656], &basic_proc, &null_mcb},
	{_("Aurora Veil"), 101, 0, (pchar*)Aurora_Veil_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_ICE, &m_flags[657], &basic_proc, &null_mcb},
	{_("Shell Trap"), 100, 150, (pchar*)Shell_Trap_desc, 5, -3, 1, MOVE_PHYSICAL, MTYPE_FIRE, &m_flags[658], &basic_proc, &null_mcb},
	{_("Fleur Cannon"), 90, 130, (pchar*)Fleur_Cannon_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[659], &basic_proc, &null_mcb},
	{_("Psychic Fangs"), 100, 85, (pchar*)Psychic_Fangs_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[660], &basic_proc, &null_mcb},
	{_("Stomping Tantrum"), 100, 75, (pchar*)Stomping_Tantrum_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GROUND, &m_flags[661], &basic_proc, &null_mcb},
	{_("Shadow Bone"), 100, 85, (pchar*)Shadow_Bone_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[662], &basic_proc, &null_mcb},
	{_("Accelerock"), 100, 40, (pchar*)Accelerock_desc, 20, 1, 1, MOVE_PHYSICAL, MTYPE_ROCK, &m_flags[663], &basic_proc, &null_mcb},
	{_("Liquidation"), 100, 85, (pchar*)Liquidation_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_WATER, &m_flags[664], &basic_proc, &null_mcb},
	{_("Prismatic Laser"), 100, 160, (pchar*)Prismatic_Laser_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_PSYCHIC, &m_flags[665], &basic_proc, &null_mcb},
	{_("Spectral Thief"), 100, 90, (pchar*)Spectral_Thief_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[666], &basic_proc, &null_mcb},
	{_("Sunsteel Strike"), 100, 100, (pchar*)Sunsteel_Strike_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_STEEL, &m_flags[667], &basic_proc, &null_mcb},
	{_("Moongeist Beam"), 100, 100, (pchar*)Moongeist_Beam_desc, 5, 0, 1, MOVE_PHYSICAL, MTYPE_GHOST, &m_flags[668], &basic_proc, &null_mcb},
	{_("Tearful Look"), 101, 0, (pchar*)Tearful_Look_desc, 20, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[669], &basic_proc, &null_mcb},
	{_("Zing Zap"), 100, 80, (pchar*)Zing_Zap_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_ELECTRIC, &m_flags[670], &basic_proc, &null_mcb},
	{_("Nature‘s Madness"), 90, 0, (pchar*)Natures_Madness_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_FAIRY, &m_flags[671], &basic_proc, &null_mcb},
	{_("Multi-Attack"), 100, 90, (pchar*)Multi_Attack_desc, 10, 0, 1, MOVE_PHYSICAL, MTYPE_NORMAL, &m_flags[672], &basic_proc, &null_mcb},
};

/*
struct fling_dmg {
    enum Items id;
    u8 power;
};


struct fling_dmg fling_power_table[338] = {
	{ITEM_CHERI_BERRY, 0x0A},
	{ITEM_CHESTO_BERRY, 0x0A},
	{ITEM_PECHA_BERRY, 0x0A},
	{ITEM_RAWST_BERRY, 0x0A},
	{ITEM_ASPEAR_BERRY, 0x0A},
	{ITEM_LEPPA_BERRY, 0x0A},
	{ITEM_ORAN_BERRY, 0x0A},
	{ITEM_PERSIM_BERRY, 0x0A},
	{ITEM_LUM_BERRY, 0x0A},
	{ITEM_SITRUS_BERRY, 0x0A},
	{ITEM_FIGY_BERRY, 0x0A},
	{ITEM_WIKI_BERRY, 0x0A},
	{ITEM_MAGO_BERRY, 0x0A},
	{ITEM_AGUAV_BERRY, 0x0A},
	{ITEM_IAPAPA_BERRY, 0x0A},
	{ITEM_RAZZ_BERRY, 0x0A},
	{ITEM_BLUK_BERRY, 0x0A},
	{ITEM_NANAB_BERRY, 0x0A},
	{ITEM_WEPEAR_BERRY, 0x0A},
	{ITEM_PINAP_BERRY, 0x0A},
	{ITEM_POMEG_BERRY, 0x0A},
	{ITEM_KELPSY_BERRY, 0x0A},
	{ITEM_QUALOT_BERRY, 0x0A},
	{ITEM_HONDEW_BERRY, 0x0A},
	{ITEM_GREPA_BERRY, 0x0A},
	{ITEM_TAMATO_BERRY, 0x0A},
	{ITEM_CORNN_BERRY, 0x0A},
	{ITEM_MAGOST_BERRY, 0x0A},
	{ITEM_RABUTA_BERRY, 0x0A},
	{ITEM_NOMEL_BERRY, 0x0A},
	{ITEM_SPELON_BERRY, 0x0A},
	{ITEM_PAMTRE_BERRY, 0x0A},
	{ITEM_WATMEL_BERRY, 0x0A},
	{ITEM_DURIN_BERRY, 0x0A},
	{ITEM_BELUE_BERRY, 0x0A},
	{ITEM_OCCA_BERRY, 0x0A},
	{ITEM_PASSHO_BERRY, 0x0A},
	{ITEM_WACAN_BERRY, 0x0A},
	{ITEM_RINDO_BERRY, 0x0A},
	{ITEM_YACHE_BERRY, 0x0A},
	{ITEM_CHOPLE_BERRY, 0x0A},
	{ITEM_KEBIA_BERRY, 0x0A},
	{ITEM_SHUCA_BERRY, 0x0A},
	{ITEM_COBA_BERRY, 0x0A},
	{ITEM_PAYAPA_BERRY, 0x0A},
	{ITEM_TANGA_BERRY, 0x0A},
	{ITEM_CHARTI_BERRY, 0x0A},
	{ITEM_KASIB_BERRY, 0x0A},
	{ITEM_HABAN_BERRY, 0x0A},
	{ITEM_COLBUR_BERRY, 0x0A},
	{ITEM_BABIRI_BERRY, 0x0A},
	{ITEM_CHILAN_BERRY, 0x0A},
	{ITEM_LIECHI_BERRY, 0x0A},
	{ITEM_GANLON_BERRY, 0x0A},
	{ITEM_SALAC_BERRY, 0x0A},
	{ITEM_PETAYA_BERRY, 0x0A},
	{ITEM_APICOT_BERRY, 0x0A},
	{ITEM_LANSAT_BERRY, 0x0A},
	{ITEM_STARF_BERRY, 0x0A},
	{ITEM_ENIGMA_BERRY, 0x0A},
	{ITEM_MICLE_BERRY, 0x0A},
	{ITEM_CUSTAP_BERRY, 0x0A},
	{ITEM_JABOCA_BERRY, 0x0A},
	{ITEM_ROWAP_BERRY, 0x0A},
	{ITEM_SEA_INCENSE, 0x0A},
	{ITEM_LAX_INCENSE, 0x0A},
	{ITEM_ODD_INCENSE, 0x0A},
	{ITEM_ROCK_INCENSE, 0x0A},
	{ITEM_FULL_INCENSE, 0x0A},
	{ITEM_WAVE_INCENSE, 0x0A},
	{ITEM_ROSE_INCENSE, 0x0A},
	{ITEM_LUCK_INCENSE, 0x0A},
	{ITEM_PURE_INCENSE, 0x0A},
	{ITEM_RED_SCARF, 0x0A},
	{ITEM_BLUE_SCARF, 0x0A},
	{ITEM_PINK_SCARF, 0x0A},
	{ITEM_GREEN_SCARF, 0x0A},
	{ITEM_YELLOW_SCARF, 0x0A},
	{ITEM_AIR_BALLOON, 0x0A},
	{ITEM_BIG_ROOT, 0x0A},
	{ITEM_BRIGHT_POWDER, 0x0A},
	{ITEM_CHOICE_BAND, 0x0A},
	{ITEM_CHOICE_SCARF, 0x0A},
	{ITEM_CHOICE_SPECS, 0x0A},
	{ITEM_DESTINY_KNOT, 0x0A},
	{ITEM_EXPERT_BELT, 0x0A},
	{ITEM_FOCUS_SASH, 0x0A},
	{ITEM_FOCUS_BAND, 0x0A},
	{ITEM_LAGGING_TAIL, 0x0A},
	{ITEM_LEFTOVERS, 0x0A},
	{ITEM_MENTAL_HERB, 0x0A},
	{ITEM_POWER_HERB, 0x0A},
	{ITEM_METAL_POWDER, 0x0A},
	{ITEM_MUSCLE_BAND, 0x0A},
	{ITEM_QUICK_POWDER, 0x0A},
	{ITEM_REAPER_CLOTH, 0x0A},
	{ITEM_RED_CARD, 0x0A},
	{ITEM_RING_TARGET, 0x0A},
	{ITEM_SILK_SCARF, 0x0A},
	{ITEM_SILVER_POWDER, 0x0A},
	{ITEM_SMOOTH_ROCK, 0x0A},
	{ITEM_SOFT_SAND, 0x0A},
	{ITEM_SOOTHE_BELL, 0x0A},
	{ITEM_WHITE_HERB, 0x0A},
	{ITEM_WIDE_LENS, 0x0A},
	{ITEM_WISE_GLASSES, 0x0A},
	{ITEM_ZOOM_LENS, 0x0A},
	{ITEM_HEALTH_WING, 0x14},
	{ITEM_MUSCLE_WING, 0x14},
	{ITEM_RESIST_WING, 0x14},
	{ITEM_GENIUS_WING, 0x14},
	{ITEM_CLEVER_WING, 0x14},
	{ITEM_SWIFT_WING, 0x14},
	{ITEM_PRETTY_WING, 0x14},
	{ITEM_ANTIDOTE, 0x1E},
	{ITEM_BURN_HEAL, 0x1E},
	{ITEM_ICE_HEAL, 0x1E},
	{ITEM_AWAKENING, 0x1E},
	{ITEM_PARALYZE_HEAL, 0x1E},
	{ITEM_FULL_RESTORE, 0x1E},
	{ITEM_FULL_HEAL, 0x1E},
	{ITEM_LAVA_COOKIE, 0x1E},
	{ITEM_OLD_GATEAU, 0x1E},
	{ITEM_CASTELIACONE, 0x1E},
	{ITEM_LUMIOSE_GALETTE, 0x1E},
	{ITEM_SHALOUR_SABLE, 0x1E},
	{ITEM_POTION, 0x1E},
	{ITEM_MAX_POTION, 0x1E},
	{ITEM_HYPER_POTION, 0x1E},
	{ITEM_SUPER_POTION, 0x1E},
	{ITEM_SECRETPOTION, 0x1E},
	{ITEM_ENERGY_POWDER, 0x1E},
	{ITEM_ENERGY_ROOT, 0x1E},
	{ITEM_HEAL_POWDER, 0x1E},
	{ITEM_REVIVAL_HERB, 0x1E},
	{ITEM_REVIVE, 0x1E},
	{ITEM_MAX_REVIVE, 0x1E},
	{ITEM_ETHER, 0x1E},
	{ITEM_MAX_ETHER, 0x1E},
	{ITEM_ELIXIR, 0x1E},
	{ITEM_MAX_ELIXIR, 0x1E},
	{ITEM_SUPER_REPEL, 0x1E},
	{ITEM_MAX_REPEL, 0x1E},
	{ITEM_REPEL, 0x1E},
	{ITEM_HP_UP, 0x1E},
	{ITEM_PROTEIN, 0x1E},
	{ITEM_IRON, 0x1E},
	{ITEM_CARBOS, 0x1E},
	{ITEM_CALCIUM, 0x1E},
	{ITEM_RARE_CANDY, 0x1E},
	{ITEM_PP_UP, 0x1E},
	{ITEM_ZINC, 0x1E},
	{ITEM_PP_MAX, 0x1E},
	{ITEM_RED_SHARD, 0x1E},
	{ITEM_BLUE_SHARD, 0x1E},
	{ITEM_YELLOW_SHARD, 0x1E},
	{ITEM_GREEN_SHARD, 0x1E},
	{ITEM_RICH_MULCH, 0x1E},
	{ITEM_SURPRISE_MULCH, 0x1E},
	{ITEM_BOOST_MULCH, 0x1E},
	{ITEM_AMAZE_MULCH, 0x1E},
	{ITEM_GROWTH_MULCH, 0x1E},
	{ITEM_DAMP_MULCH, 0x1E},
	{ITEM_STABLE_MULCH, 0x1E},
	{ITEM_GOOEY_MULCH, 0x1E},
	{ITEM_GUARD_SPEC, 0x1E},
	{ITEM_DIRE_HIT, 0x1E},
	{ITEM_X_ATTACK, 0x1E},
	{ITEM_X_DEFENSE, 0x1E},
	{ITEM_X_SPEED, 0x1E},
	{ITEM_X_ACCURACY, 0x1E},
	{ITEM_X_SP_ATK, 0x1E},
	{ITEM_X_SP_DEF, 0x1E},
	{ITEM_DIRE_HIT_2 0x250, 0x1E},
	{ITEM_X_SPEED_2 0x251, 0x1E},
	{ITEM_X_SPECIAL_2 0x252, 0x1E},
	{ITEM_X_SP_DEF_2 0x253, 0x1E},
	{ITEM_X_DEFEND_2 0x254, 0x1E},
	{ITEM_X_ATTACK_2 0x101, 0x1E},
	{ITEM_X_ACCURACY_2 0x256, 0x1E},
	{ITEM_X_SPEED_3 0x257, 0x1E},
	{ITEM_X_SPECIAL_3 0x258, 0x1E},
	{ITEM_X_SP_DEF_3 0x259, 0x1E},
	{ITEM_X_DEFEND_3 0x25A, 0x1E},
	{ITEM_X_ATTACK_3 0x25B, 0x1E},
	{ITEM_X_ACCURACY_3 0x25C, 0x1E},
	{ITEM_X_SPEED_6 0x25D, 0x1E},
	{ITEM_X_SPECIAL_6 0x25E, 0x1E},
	{ITEM_X_SP_DEF_6 0x25F, 0x1E},
	{ITEM_X_DEFEND_6 0x260, 0x1E},
	{ITEM_X_ATTACK_6 0x261, 0x1E},
	{ITEM_X_ACCURACY_6 0x262, 0x1E},
	{ITEM_ABILITY_URGE, 0x1E},
	{ITEM_ITEM_DROP, 0x1E},
	{ITEM_ITEM_URGE, 0x1E},
	{ITEM_RESET_URGE, 0x1E},
	{ITEM_DIRE_HIT_3 0x267, 0x1E},
	{ITEM_BLUE_FLUTE, 0x1E},
	{ITEM_YELLOW_FLUTE, 0x1E},
	{ITEM_RED_FLUTE, 0x1E},
	{ITEM_BLACK_FLUTE, 0x1E},
	{ITEM_WHITE_FLUTE, 0x1E},
	{ITEM_ABSORB_BULB, 0x1E},
	{ITEM_AMULET_COIN, 0x1E},
	{ITEM_BALM_MUSHROOM, 0x1E},
	{ITEM_TINY_MUSHROOM, 0x1E},
	{ITEM_BIG_MUSHROOM, 0x1E},
	{ITEM_BIG_NUGGET, 0x1E},
	{ITEM_PEARL, 0x1E},
	{ITEM_BIG_PEARL, 0x1E},
	{ITEM_NUGGET, 0x1E},
	{ITEM_CELL_BATTERY, 0x1E},
	{ITEM_CHARCOAL, 0x1E},
	{ITEM_CLEANSE_TAG, 0x1E},
	{ITEM_COMET_SHARD, 0x1E},
	{ITEM_DEEP_SEA_SCALE, 0x1E},
	{ITEM_DRAGON_SCALE, 0x1E},
	{ITEM_EJECT_BUTTON, 0x1E},
	{ITEM_ESCAPE_ROPE, 0x1E},
	{ITEM_EVERSTONE, 0x1E},
	{ITEM_EXP_SHARE, 0x1E},
	{ITEM_SUN_STONE, 0x1E},
	{ITEM_MOON_STONE, 0x1E},
	{ITEM_FIRE_STONE, 0x1E},
	{ITEM_THUNDER_STONE, 0x1E},
	{ITEM_WATER_STONE, 0x1E},
	{ITEM_LEAF_STONE, 0x1E},
	{ITEM_TOXIC_ORB, 0x1E},
	{ITEM_FLAME_ORB, 0x1E},
	{ITEM_FLOAT_STONE, 0x1E},
	{ITEM_FLUFFY_TAIL, 0x1E},
	{ITEM_HEART_SCALE, 0x1E},
	{ITEM_HONEY, 0x1E},
	{ITEM_KINGS_ROCK, 0x1E},
	{ITEM_LIFE_ORB, 0x1E},
	{ITEM_LIGHT_BALL, 0x1E},
	{ITEM_LIGHT_CLAY, 0x1E},
	{ITEM_LUCKY_EGG, 0x1E},
	{ITEM_MAGNET, 0x1E},
	{ITEM_METAL_COAT, 0x1E},
	{ITEM_METRONOME_item, 0x1E},
	{ITEM_MIRACLE_SEED, 0x1E},
	{ITEM_MYSTIC_WATER, 0x1E},
	{ITEM_NEVER_MELT_ICE, 0x1E},
	{ITEM_PASS_ORB, 0x1E},
	{ITEM_PEARL_STRING, 0x1E},
	{ITEM_POKE_DOLL, 0x1E},
	{ITEM_PRISM_SCALE, 0x1E},
	{ITEM_RAZOR_FANG, 0x1E},
	{ITEM_RELIC_COPPER, 0x1E},
	{ITEM_RELIC_SILVER, 0x1E},
	{ITEM_RELIC_GOLD, 0x1E},
	{ITEM_RELIC_VASE, 0x1E},
	{ITEM_RELIC_STATUE, 0x1E},
	{ITEM_RELIC_CROWN, 0x1E},
	{ITEM_SACRED_ASH, 0x1E},
	{ITEM_SCOPE_LENS, 0x1E},
	{ITEM_SHELL_BELL, 0x1E},
	{ITEM_SHOAL_SALT, 0x1E},
	{ITEM_SHOAL_SHELL, 0x1E},
	{ITEM_SMOKE_BALL, 0x1E},
	{ITEM_SOUL_DEW, 0x1E},
	{ITEM_SPELL_TAG, 0x1E},
	{ITEM_STAR_PIECE, 0x1E},
	{ITEM_STARDUST, 0x1E},
	{ITEM_SWEET_HEART, 0x1E},
	{ITEM_TWISTED_SPOON, 0x1E},
	{ITEM_UP_GRADE, 0x1E},
	{ITEM_EVIOLITE, 0x28},
	{ITEM_LUCKY_PUNCH, 0x28},
	{ITEM_ICY_ROCK, 0x28},
	{ITEM_DUBIOUS_DISC, 0x32},
	{ITEM_SHARP_BEAK, 0x32},
	{ITEM_ADAMANT_ORB, 0x3C},
	{ITEM_DAMP_ROCK, 0x3C},
	{ITEM_GRISEOUS_ORB, 0x3C},
	{ITEM_HEAT_ROCK, 0x3C},
	{ITEM_LUSTROUS_ORB, 0x3C},
	{ITEM_MACHO_BRACE, 0x3C},
	{ITEM_ROCKY_HELMET, 0x3C},
	{ITEM_STICK, 0x3C},
	{ITEM_DOUSE_DRIVE, 0x46},
	{ITEM_SHOCK_DRIVE, 0x46},
	{ITEM_BURN_DRIVE, 0x46},
	{ITEM_CHILL_DRIVE, 0x46},
	{ITEM_DRAGON_FANG, 0x46},
	{ITEM_POISON_BARB, 0x46},
	{ITEM_POWER_BRACER, 0x46},
	{ITEM_POWER_BELT, 0x46},
	{ITEM_POWER_LENS, 0x46},
	{ITEM_POWER_BAND, 0x46},
	{ITEM_POWER_ANKLET, 0x46},
	{ITEM_POWER_WEIGHT, 0x46},
	{ITEM_ASSAULT_VEST, 0x50},
	{ITEM_DUSK_STONE, 0x50},
	{ITEM_DAWN_STONE, 0x50},
	{ITEM_ELECTIRIZER, 0x50},
	{ITEM_MAGMARIZER, 0x50},
	{ITEM_ODD_KEYSTONE, 0x50},
	{ITEM_OVAL_STONE, 0x50},
	{ITEM_PROTECTOR, 0x50},
	{ITEM_QUICK_CLAW, 0x50},
	{ITEM_RAZOR_CLAW, 0x50},
	{ITEM_SHINY_STONE, 0x50},
	{ITEM_STICKY_BARB, 0x50},
	{ITEM_FLAME_PLATE, 0x5A},
	{ITEM_SPLASH_PLATE, 0x5A},
	{ITEM_ZAP_PLATE, 0x5A},
	{ITEM_MEADOW_PLATE, 0x5A},
	{ITEM_ICICLE_PLATE, 0x5A},
	{ITEM_FIST_PLATE, 0x5A},
	{ITEM_TOXIC_PLATE, 0x5A},
	{ITEM_EARTH_PLATE, 0x5A},
	{ITEM_SKY_PLATE, 0x5A},
	{ITEM_MIND_PLATE, 0x5A},
	{ITEM_INSECT_PLATE, 0x5A},
	{ITEM_STONE_PLATE, 0x5A},
	{ITEM_SPOOKY_PLATE, 0x5A},
	{ITEM_DRACO_PLATE, 0x5A},
	{ITEM_DREAD_PLATE, 0x5A},
	{ITEM_IRON_PLATE, 0x5A},
	{ITEM_PIXIE_PLATE, 0x5A},
	{ITEM_DEEP_SEA_TOOTH, 0x5A},
	{ITEM_GRIP_CLAW, 0x5A},
	{ITEM_THICK_CLUB, 0x5A},
	{ITEM_COVER_FOSSIL, 0x64},
	{ITEM_PLUME_FOSSIL, 0x65},
	{ITEM_JAW_FOSSIL, 0x66},
	{ITEM_SAIL_FOSSIL, 0x67},
	{ITEM_ROOT_FOSSIL, 0x68},
	{ITEM_CLAW_FOSSIL, 0x69},
	{ITEM_HELIX_FOSSIL, 0x70},
	{ITEM_DOME_FOSSIL, 0x71},
	{ITEM_OLD_AMBER, 0x72},
	{ITEM_ARMOR_FOSSIL, 0x73},
	{ITEM_SKULL_FOSSIL, 0x64},
	{ITEM_HARD_STONE, 0x64},
	{ITEM_RARE_BONE, 0x64},
	{ITEM_IRON_BALL, 0x82},
};
*/

