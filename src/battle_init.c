#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_slide_in/battle_obj_sliding.h"
#include "battle_state.h"
#include "battle_text/battle_textbox_gfx.h"

extern void pick_encounter_message(enum BattleFlag);
extern void setup(void);
extern void battle_slidein(void);
extern void player_throwball_and_moveout_scene(struct Object*);
extern void player_hpbar_slidin_slow(u8 t_id);
extern void vblank_cb_no_merge(void);
extern void vblank_cb_merge_move_select(void);
extern void battle_loop(void);
extern void init_selection_cursor(u8 mode, u8 bank);
extern void load_icons_moves(u8 bank);
extern void set_active_movement(u8 task_id);
extern void update_cursor_move_select(u8 task_id);
extern void show_move_data(void);
extern void option_selection(void);
extern u8 get_ability(struct Pokemon* p);

void init_battle_elements()
{
    // allocate battle specific resources
    p_bank = (struct pkmn_bank(*)[4])malloc_and_clear(sizeof(struct pkmn_bank[4]));
    bs_env_windows = (struct bs_elements_positions*)malloc_and_clear(sizeof(struct bs_elements_positions));
    battle_master = (struct battle_main*)malloc_and_clear(sizeof(struct battle_main));
    setup();
    help_system_disable__sp198();
    super.multi_purpose_state_tracker = 0;
    set_callback1((SuperCallback)battle_slidein);
    battle_type_flags = BATTLE_FLAG_WILD;
}

void update_pbank(u8 bank, struct update_flags* flags)
{
    // base stats
    u16 species = pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_SPECIES, NULL);
    p_bank[bank]->b_data.species = species;
    p_bank[bank]->b_data.gender = pokemon_get_gender(p_bank[bank]->this_pkmn);
    p_bank[bank]->b_data.current_hp = pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_CURRENT_HP, NULL);;
    p_bank[bank]->b_data.total_hp = pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_TOTAL_HP, NULL);;
    p_bank[bank]->b_data.ability = get_ability(p_bank[bank]->this_pkmn);
    p_bank[bank]->b_data.item = pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_HELD_ITEM, NULL);
    p_bank[bank]->b_data.level = pokemon_getattr(p_bank[bank]->this_pkmn, REQUEST_LEVEL, NULL);
    p_bank[bank]->b_data.poke_ball = 0;
    p_bank[bank]->b_data.type[0] = pokemon_base_stats[species].type[0];
    p_bank[bank]->b_data.type[1] = pokemon_base_stats[species].type[1];
    p_bank[bank]->b_data.type[2] = MTYPE_NONE;
    
    if (!flags->pass_stats) {
        p_bank[bank]->b_data.attack = 0;
        p_bank[bank]->b_data.defense = 0;
        p_bank[bank]->b_data.speed = 0;
        p_bank[bank]->b_data.sp_atk = 0;
        p_bank[bank]->b_data.sp_def = 0;
        p_bank[bank]->b_data.accuracy = 0;
        p_bank[bank]->b_data.evasion = 0;
        p_bank[bank]->b_data.crit_mod = 0;
    }
    
    // user actions should always be cleared
    p_bank[bank]->b_data.is_running = 0;
    p_bank[bank]->b_data.using_item = 0;
    p_bank[bank]->b_data.is_switching = 0;
    p_bank[bank]->b_data.skip_move_select = 0;
    p_bank[bank]->b_data.first_turn = 1;
    
    if (!flags->pass_atk_history) {
        p_bank[bank]->b_data.my_target = 0xFF;
        p_bank[bank]->b_data.last_move = 0;
        p_bank[bank]->b_data.current_move = 0;
        p_bank[bank]->b_data.last_damage = 0;
        p_bank[bank]->b_data.last_attacked_by = 0xFF;
        p_bank[bank]->b_data.last_used_item = 0;
        p_bank[bank]->b_data.ate_berry = 0;
    }

    if (!flags->pass_stats) {
        p_bank[bank]->b_data.status = 0;
        p_bank[bank]->b_data.confusion_turns = 0;
        p_bank[bank]->b_data.status_turns = 0;
        p_bank[bank]->b_data.substitute_health = 0;
        p_bank[bank]->b_data.v_status = 0;
        p_bank[bank]->b_data.is_taunted = 0;
        p_bank[bank]->b_data.is_charmed = 0;
        p_bank[bank]->b_data.is_grounded = 0;
    }
    
    if (!flags->pass_disables) {
        p_bank[bank]->b_data.is_disabled = 0;
        p_bank[bank]->b_data.disabled_moves[0] = 0;
        p_bank[bank]->b_data.disabled_moves[1] = 0;
        p_bank[bank]->b_data.disabled_moves[2] = 0;
        p_bank[bank]->b_data.disabled_moves[3] = 0;
    }
    
    p_bank[bank]->b_data.illusion = 0;
    p_bank[bank]->b_data.fainted = 0;
}


/* Called right after sliding in effects have finished executing. */
void init_battle()
{
    switch (super.multi_purpose_state_tracker) {
        case 0:
            gpu_pal_apply((void*)stdpal_get(0), 16*rboxes[0x18 & 0x3F].pal_id, 32);
            pick_encounter_message(battle_type_flags);
            battle_show_message((u8*)string_buffer, 0x18);
            super.multi_purpose_state_tracker++;
            break;
        case 1:
            if (!dialogid_was_acknowledged(0x18 & 0x3F)) {
                objects[bs_env_windows->player_trainer_objid].callback = player_throwball_and_moveout_scene;
                objects[bs_env_windows->player_trainer_objid].priv[2] = PLAYER_SINGLES_BANK;
                bs_anim_status = 1;
                super.multi_purpose_state_tracker++;
            }
            break;
        case 2:
            if (bs_anim_status)
                return;
            // create and slide into place HPbox
            task_add(player_hpbar_slidin_slow, 1);
            bs_anim_status = 1;
            super.multi_purpose_state_tracker++;
            break;
        case 3:
        {
            // wait for sliding animations to finish
            if (bs_anim_status)
                return;  

            // up and down movement of the active moving Pokemon
            u8 t_id = task_add(set_active_movement, 1);
            tasks[t_id].priv[0] = PLAYER_SINGLES_BANK;
            
            // build p_bank data once animation is finished
            struct update_flags* flags = (struct update_flags*)malloc_and_clear(sizeof(struct update_flags));
            flags->pass_status = false;
            flags->pass_stats = false;
            flags->pass_atk_history = false;
            flags->pass_disables = false;
            update_pbank(PLAYER_SINGLES_BANK, flags);
            update_pbank(OPPONENT_SINGLES_BANK, flags);
            free(flags);
            super.multi_purpose_state_tracker++;
        }
        case 4:
        {
            // initialization finished, set c1 option selection
            super.multi_purpose_state_tracker = 0;
            set_callback1(option_selection);
            break;
        }
        default:
            break;
    };
}

/* Fight menu and move menu selection. Preperation to go into battle loop*/
void option_selection()
{
    switch (super.multi_purpose_state_tracker) {
        case 0:
        {
            // initialize fight menu selection
            vblank_handler_set(vblank_cb_no_merge);
            void* map_base = (void *)0x600F800;
            memcpy(map_base, battle_textbox_action_selectMap, sizeof(battle_textbox_action_selectMap));
            init_selection_cursor(1, 0);

            // next state
            bs_anim_status = 1;
            super.multi_purpose_state_tracker++;
            break;
        }
        case 1:
            // wait for input selection from fight menu
            if (bs_anim_status)
                return;
            // interpret selection
            switch (battle_master->selected_option) {
                case OPTION_FIGHT:
                    super.multi_purpose_state_tracker = (battle_master->fight_menu_content_spawned) ? 7 : 2;
                    break;
                case OPTION_POKEMON:
                    super.multi_purpose_state_tracker = 3;
                    break;
                case OPTION_BAG:
                    super.multi_purpose_state_tracker = 4;
                    break;
                case OPTION_RUN:
                    super.multi_purpose_state_tracker = 5;
                    break;
                    
            };
            break;
        case 2:
            /* FIGHT selected from fight menu */
            
            // update tilemap
            vblank_handler_set(vblank_cb_merge_move_select);
            void* map_base = (void *)0x600F800;
            memcpy(map_base, battle_textbox_move_selectMap, sizeof(battle_textbox_action_selectMap));
            
            // init cursor
            init_selection_cursor(0, 0);
            
            // init move types
            load_icons_moves(PLAYER_SINGLES_BANK);
            // set into pause state
            bs_anim_status = 1;
            super.multi_purpose_state_tracker = 6;
            break;
        case 3:
            // POKEMON selection from fight menu
            break;
        case 4:
            // BAG selected from fight menu
            break;
        case 5:
            // RUN selected from fight menu
           // right now it just exits. Needs to be cleaned up - memory leaks exist.
            exit_to_overworld_2_switch();
            set_callback1(c1_overworld);
            
            break;
        case 6:
            break;
        case 7:
            {
            vblank_handler_set(vblank_cb_merge_move_select);
            void* map_base = (void *)0x600F800;
            memcpy(map_base, battle_textbox_move_selectMap, sizeof(battle_textbox_action_selectMap));
            //init_selection_cursor(1, 0);
            show_move_data();
            tasks[task_add(update_cursor_move_select, 1)].priv[0] = 0;
            bs_anim_status = 1;
            super.multi_purpose_state_tracker = 6;
            break;
            }
        case 8:
        {
            set_callback1(battle_loop);
            void* map_base = (void *)0x600F800;
            memcpy(map_base, battle_textboxMap, sizeof(battle_textboxMap));
            super.multi_purpose_state_tracker = 0;
            break;
        }
    }; 
}













