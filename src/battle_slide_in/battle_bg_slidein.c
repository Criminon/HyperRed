#include <pokeagb/pokeagb.h>
#include "battle_obj_sliding.h"
#include "../battle_data/pkmn_bank.h"
#include "../battle_state.h"
#include "../generated/images/battle_terrains/grass/grass_bg.h"
#include "../../generated/images/battle_terrains/grass/grass_entry.h"
#include "../battle_text/battle_textbox_gfx.h"

extern void c2_battle(void);
extern void allys_move_into_scene(void);
extern void opponents_move_into_scene(void);
extern void obj_mode_normal_set(u8 id);
extern void spawn_hpboxes_wild(void);
extern void pick_obj_creator(void);
extern void vblank_cb_merge_tbox(void);
extern void init_battle(void);

void hblank_battle_bgsslide_win_open(void)
{
    // screen opening from middle, outwards
    if ((REG_VCOUNT > bs_env_windows->winbot) || (REG_VCOUNT < bs_env_windows->wintop)) {
        // disable all BG layers and OAMs
        REG_DISPCNT = 0x6060;
    } else {
        // enable win0 and win 1
        REG_DISPCNT = 0x7B60;
    }

    // bg movement
    if (REG_VCOUNT > 79) {
        // move BG3 left
        REG_BG3HOFS = bs_env_windows->top_side;
    } else {
        // move BG3 right
        REG_BG3HOFS = bs_env_windows->bot_side;
    }

}

void hblank_battle_bgslide(void)
{
    // bg movement
    if (REG_VCOUNT > 79) {
        // move BG3 left
        REG_BG3HOFS = bs_env_windows->top_side;
    } else {
        // move BG3 right
        REG_BG3HOFS = bs_env_windows->bot_side;
    }
}


void battle_slidein(void)
{
    switch (super.multi_purpose_state_tracker) {
        case 0:
            // set callbacks and vblank interrupt
            vblank_handler_set((SuperCallback)vblank_cb_merge_tbox);
            set_callback2((SuperCallback)c2_battle);
            REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ | WIN_BLD,
            WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ | WIN_BLD);
            super.multi_purpose_state_tracker++;
            break;
        case 1:
            // reset and configure BGs
        	bgid_mod_x_offset(0, 0, 0);
            bgid_mod_y_offset(0, 0, 0);
            bgid_mod_x_offset(1, 0, 0);
            bgid_mod_y_offset(1, 0, 0);
            bgid_mod_x_offset(2, 0, 0);
            bgid_mod_y_offset(2, 0, 0);
            bgid_mod_x_offset(3, 0, 0);
            bgid_mod_y_offset(3, 0, 0);
            gpu_tile_bg_drop_all_sets(0);
            struct BgConfig bg0_config = {
                                        .padding = 0,
                                        .b_padding = 0,
                                        .priority = 0,
                                        .palette = 0,
                                        .size = 0,
                                        .map_base = 31,
                                        .character_base = 3,
                                        .bgid = 0
            };
            struct BgConfig bg1_config = {
                                        .padding = 0,
                                        .b_padding = 0,
                                        .priority = 1,
                                        .palette = 0,
                                        .size = 0,
                                        .map_base = 30,
                                        .character_base = 2,
                                        .bgid = 1
            };
            struct BgConfig bg2_config = {
                                        .padding = 0,
                                        .b_padding = 0,
                                        .priority = 2,
                                        .palette = 0,
                                        .size = 0,
                                        .map_base = 29,
                                        .character_base = 1,
                                        .bgid = 2
            };
            struct BgConfig bg3_config = {
                                        .padding = 0,
                                        .b_padding = 0,
                                        .priority = 3,
                                        .palette = 0,
                                        .size = 1,
                                        .map_base = 28,
                                        .character_base = 0,
                                        .bgid = 3
            };
            struct BgConfig bg_config_data[4] = {bg0_config, bg1_config, bg2_config, bg3_config};
            bg_vram_setup(0, (struct BgConfig *)&bg_config_data, 4);

            // init textbox
            rbox_init_battlebox((struct Textbox*)0x8248330);
            remo_reset_acknowledgement_flags();
            battlebox_mark_usable();
            super.multi_purpose_state_tracker++;
            break;
        case 2:
        {
            // copy image BG background
            void* char_base = (void *)0x6000000;
            void* map_base = (void *)0x600E000;
            lz77UnCompVram((void *)grass_bgTiles, char_base);
            lz77UnCompVram((void *)grass_bgMap, map_base);

            // copy image BG entry image
            char_base = (void *)0x6008000;
            map_base = (void *)0x600F000;
            lz77UnCompVram((void *)grass_entryTiles, char_base);
            lz77UnCompVram((void *)grass_entryMap, map_base);

            // copy textbox image
            char_base = (void *)0x600C000;
            map_base = (void *)0x600F800;
            lz77UnCompVram((void *)bboxTiles, char_base);
            memcpy(map_base, battle_textboxMap, sizeof(battle_textboxMap));

            // write palettes
            gpu_pal_apply_compressed((void *)grass_bgPal, 0, 64);
            gpu_pal_apply((void*)grass_entryPal, 16 * 4, 32);
            gpu_pal_apply((void*)bboxPal, 16 * 5, 32);

            super.multi_purpose_state_tracker++;
            break;
        }
        case 3:
        {
            // load battle participants
            pick_obj_creator();
            super.multi_purpose_state_tracker++;
            break;
        }
        case 4:
            // show bgs for background and entry image
            gpu_sync_bg_show(3);
            gpu_sync_bg_show(1);
            gpu_sync_bg_show(0);
            bgid_mark_for_sync(3);
            bgid_mark_for_sync(1);
            bgid_mark_for_sync(0);
            // enable wraparound for BG3 and BG1
            REG_BG3CNT |= 0x2000;
            REG_BG1CNT |= 0x2000;

            // activate hblank interrupt
            interrupts_enable(2);
            hblank_handler_set((SuperCallback)hblank_battle_bgsslide_win_open);
            u8 **bg0_map = (u8**)0x030008EC;
            u8 *dst = (u8 *)(*bg0_map);
            memset(dst, 0, 2048);
            super.multi_purpose_state_tracker++;
            break;
        case 5:
            // set initial position for BG bottom and top half
            bs_env_windows->top_side = -260;
            bs_env_windows->bot_side = -254;

            // set initial position for center of open effect (160 / 2 = 80 = center)
            bs_env_windows->wintop = 80;
            bs_env_windows->winbot = 80;
            super.multi_purpose_state_tracker++;
            break;
        case 6:
            // there is a window in which the grass and BG are moving
            bgid_mod_x_offset(1, 3 << 8, 1);
            bs_env_windows->wintop -= 1;
            bs_env_windows->winbot += 1;
            if (bs_env_windows->wintop < 20)
                super.multi_purpose_state_tracker++;
            break;
        case 7:
        {
            bs_env_windows->bot_side -= 3;
            bs_env_windows->top_side += 3;
            bs_env_windows->wintop -= 1;
            bs_env_windows->winbot += 1;
            bgid_mod_x_offset(1, 4 << 8, 1);
            bgid_mod_y_offset(1, 1 << 7, 2);

            allys_move_into_scene();
            opponents_move_into_scene();

            if (bs_env_windows->wintop <= 0) {
                hblank_handler_set((SuperCallback)hblank_battle_bgslide);
                REG_DISPCNT = 0x7B60;

                // start sliding in HP bars and writing encounter text into textbox.

            }

            if (bs_env_windows->top_side > -3)
                super.multi_purpose_state_tracker++;
            break;
        }
        case 8:
        {
            
            //REG_BLDCNT = 0;
            extern void task_lightup_obj(u8);
            u8 t_id = task_add(task_lightup_obj, 0x1);
            tasks[t_id].priv[0] = 0x7;
            gpu_sync_bg_hide(1);
            

            // spawn HP boxes
            spawn_hpboxes_wild();
            super.multi_purpose_state_tracker = 0;
            set_callback1((SuperCallback)init_battle);
        }
        case 10:
            break;
    };
}


void task_lightup_obj(u8 t_id)
{
    if (tasks[t_id].priv[0]) {
        if (tasks[t_id].priv[1] % 2)
            tasks[t_id].priv[0]--;
        tasks[t_id].priv[1]++;
        REG_BLDY = tasks[t_id].priv[0];
    } else {
        // objects opponent side light up original palette
        REG_BLDCNT = 0;
        
        // player remove blending
        obj_mode_normal_set(bs_env_windows->player_trainer_objid);
        task_del(t_id);
    }
}
