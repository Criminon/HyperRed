#include <pokeagb/pokeagb.h>
#include "../battle_slide_in/battle_obj_sliding.h"
#include "../battle_data/pkmn_bank.h"
#include "../battle_state.h"

// HP box and bar resources
#include "../../generated/images/hpbox/empty_bar.h"
#include "../../generated/images/hpbox/hpbar_pieces.h"
#include "../../generated/images/hpbox/hpbox_player_singles.h"
#include "../../generated/images/hpbox/hpbox_opponent_singles.h"


const struct OamData hpbox_oam = {
                                .y = 0,
                                .affine_mode = 0,
                                .obj_mode = 0,
                                .mosaic = 0,
                                .bpp = 0,
                                .shape = 0,
                                .x = 0,
                                .matrix_num = 0,
                                .size = 3, //64x64
                                .tile_num = 0,
                                .priority = 3, // above BG background, below entry layer
                                .palette_num = 0,
                                .affine_param = 0
};


const struct OamData hpbar_oam = {
                                .y = 0,
                                .affine_mode = 0,
                                .obj_mode = 0,
                                .mosaic = 0,
                                .bpp = 0,
                                .shape = 1,
                                .x = 0,
                                .matrix_num = 0,
                                .size = 3, //64x32
                                .tile_num = 0,
                                .priority = 2, // above BG background, below entry layer
                                .palette_num = 0,
                                .affine_param = 0
};


static const struct Frame (**nullframe)[] = (const struct Frame (**)[])0x8231CF0;
static const struct RotscaleFrame (**nullrsf)[] = (const struct RotscaleFrame (**)[])0x8231CFC;

extern void oac_nullsub(struct Object*);

void refresh_hp(struct Pokemon* pkmn, u8 objid)
{
    /* calculate first how many pixels are needed to model current HP and color */
    u16 current_hp = pokemon_getattr(pkmn, REQUEST_CURRENT_HP, NULL) * 100;
    u16 total_hp = pokemon_getattr(pkmn, REQUEST_TOTAL_HP, NULL);
    // error term is 1 pixel per 50%
    u16 percentage = (current_hp / total_hp);
    u16 pixels_to_write = (((current_hp / total_hp) / 2) - (percentage / 50));
    u16 color;
    if (percentage < 25) {
        color = 2 * 256; // red
    } else if (percentage < 50) {
        color = 1 * 256; // yellow
    } else {
        color = 0 * 256; // green
    }

    /* Build the HP Bar graphic */
    void* vram_addr =  (void*)((0x6010000)+ (objects[objid].final_oam.tile_num * 32));
    memcpy(vram_addr, hpbar_piecesTiles + 1024, 32 * 2); // copy the "HP:" part
    vram_addr += 64;
    u8 i, j;
    u8 tiles_filled = 0;
    for (i = 0; i < 8; i++) {
        u8 pieces_to_draw = pixels_to_write / (NON_ZERO_SUB(8, i));
        for (j = 0; j < pieces_to_draw; j++) {
            memcpy(vram_addr, (hpbar_piecesTiles + color + (i * 32)) , 32);
            vram_addr += 32; // next tile
            pixels_to_write -= NON_ZERO_SUB(8, i);
            tiles_filled++;
        }
    }
    while (6 - tiles_filled) {
        tiles_filled++;
        memcpy(vram_addr, (hpbar_piecesTiles + 1760) , 32);
        vram_addr += 32; // next tile
    }
}

u8 hpbar_build_full(struct Pokemon* pkmn, s16 x, s16 y, u16 tag)
{
    /* commit the empty bar to memory */
    struct SpritePalette hpbar_sprite_pal = {(void*)hpbar_piecesPal, tag};
    struct SpriteTiles hpbar_sprite_gfx = {(void*)empty_barTiles, 1024, tag};
    struct Template hpbar_temp = {tag, tag, &hpbar_oam, nullframe, &hpbar_sprite_gfx, nullrsf, (ObjectCallback)oac_nullsub};
    gpu_tile_obj_decompress_alloc_tag_and_upload(&hpbar_sprite_gfx);
    gpu_pal_decompress_alloc_tag_and_upload(&hpbar_sprite_pal);
    u8 objid_main = template_instanciate_forward_search(&hpbar_temp, x, y, 0);

    // update hp
    refresh_hp(pkmn, objid_main);
    return objid_main;
}

void draw_hp(struct Pokemon* pkmn, u8 tile_id, u8 objid)
{
    pchar hp_prefix[] = _("{HIGHLIGHT 0}{COLOR 3}{SHADOW 5}");
    pchar hp_slash[] = _("/ ");
    pstrcpy(string_buffer, &hp_prefix[0]);
    pchar hp_buff[3];

    u16 current_hp = pokemon_getattr(pkmn, REQUEST_CURRENT_HP, NULL);
    u16 total_hp = pokemon_getattr(pkmn, REQUEST_TOTAL_HP, NULL);
    u8 tile_length = total_hp > 99 ? 3 : 2;

    if (current_hp < 10) {
        // single digit, space pad 2 digits
        tile_length += 1;
    } else if (current_hp < 100) {
        // two digits, space pad 1 digit
        tile_length += 2;
    } else {
        // the digits, space pad 0 digits
        tile_length += 3;
        tile_id -= 1;
    }

    /* format as XXX/YYY */
    fmt_int_10(&hp_buff[0], current_hp, 0, 3);
    pstrcat(string_buffer, hp_buff);
    pstrcat(string_buffer, hp_slash);
    fmt_int_10(&hp_buff[0], total_hp, 0, 3);
    pstrcat(string_buffer, hp_buff);

    u8 rboxid_buffer;
    void* vram_addr = (void*)((objects[objid].final_oam.tile_num * 32) + (tile_id * 32)+ 0x6010000);
    u32 pixels = write_to_rbox(&string_buffer[0], 1, 4, &rboxid_buffer);
    rbox_to_vram(vram_addr, (void*)(pixels), tile_length);
    return;
}

void draw_level(struct Pokemon* pkmn, u8 tile_id, u8 objid)
{
    pchar level_prefix[] = _("{HIGHLIGHT TRANSPARENT}{COLOR 3}{SHADOW 5}{LV}");
    pstrcpy(string_buffer, &level_prefix[0]);
    pchar level_buff[3];

    fmt_int_10(&level_buff[0], pokemon_getattr(pkmn, REQUEST_LEVEL, NULL), 0, 3);
    pstrcat(string_buffer, level_buff);

    u8 rboxid_buffer;
    void* vram_addr = (void*)((objects[objid].final_oam.tile_num * 32) + (tile_id * 32)+ 0x6010000);
    u32 pixels = write_to_rbox(&string_buffer[0], 1, 3, &rboxid_buffer);
    rbox_to_vram(vram_addr, (void*)(pixels), 3);
    return;
}

void draw_name(struct Pokemon* pkmn, u8 tile_id, u8 tile_id2, u8 objid, enum HPFontMode mode)
 {

    /* Constant character additions to regular name string*/
    pchar name_prefix[] = _("{HIGHLIGHT TRANSPARENT}{COLOR 3}{SHADOW 5}");
    pchar gender_m[] = _("{COLOR 8}{SHADOW 5}♂");
    pchar gender_f[] = _("{COLOR 7}{SHADOW 5}♀");

    /* Copy name and prefix into buffer */
    pstrcpy(string_buffer, &name_prefix[0]);
    memcpy(&string_buffer[sizeof(name_prefix) - 1], &pkmn->base.nick[0], 10);
    // set last char to 0xFF, 10 character names aren't 0xFF terminated
    string_buffer[sizeof(name_prefix) + 9] = 0xFF;

    /* Append gender symbol to string */
    switch (pokemon_get_gender(pkmn)) {
        case 0:
            // male
            pstrcat(string_buffer, gender_m);
            break;
        case 0xFE:
            // female
            pstrcat(string_buffer, gender_f);
            break;
        case 0xFF:
            // none
            break;
    };

    /* create and write to Rbox for later object syncing */
    u8 rboxid_buffer;
    void* vram_addr;
    u32 pixels = write_to_rbox(&string_buffer[0], 1, 3, &rboxid_buffer);

    /* Sync Rbox into object */
    if (mode == HPFONT_PLAYER_SINGLE) {
        // first part of Hp box for player can handle only 3 tiles, second can hold 4
        vram_addr = (void*)((objects[objid].final_oam.tile_num * 32) + (tile_id * 32)+ 0x6010000);
        rbox_to_vram(vram_addr, (void*)pixels, 3);
        vram_addr += (32 * tile_id2);
        rbox_to_vram(vram_addr, (void*)(pixels + (32 * 3)), 4);
    } else if (mode == HPFONT_OPP_SINGLE) {
        // opponent bar can hold the entire string in first obj
        vram_addr = (void*)((objects[objid].final_oam.tile_num * 32) + (tile_id * 32)+ 0x6010000);
        rbox_to_vram(vram_addr, (void*)(pixels), 7);
    }
    // once written on Object, we can free this
    rboxid_clean(rboxid_buffer, 0);
    rboxid_free(rboxid_buffer);
}


u8 spawn_hpbox_opponent(u16 tag, s16 x, s16 y)
{
    struct SpritePalette hpbox_sprite_pal = {(void*)hpbox_opponent_singlesPal, tag};
    struct SpriteTiles hpbox_sprite_gfx = {(void*)hpbox_opponent_singlesTiles, 4096, tag};
    struct Template hpbox_temp = {tag, tag, &hpbox_oam, nullframe, &hpbox_sprite_gfx, nullrsf, (ObjectCallback)oac_nullsub};

    gpu_tile_obj_decompress_alloc_tag_and_upload(&hpbox_sprite_gfx);
    gpu_pal_decompress_alloc_tag_and_upload(&hpbox_sprite_pal);
    u8 objid_main = template_instanciate_forward_search(&hpbox_temp, x, y, 0);
    u8 objid = template_instanciate_forward_search(&hpbox_temp, x + 64, y, 0);
    objects[objid].final_oam.tile_num += 64;
    draw_name(&party_opponent[0], NAME_OS_OFFSET1, NAME_OS_OFFSET2, objid_main, HPFONT_OPP_SINGLE);
    p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[0] = objid_main;
    p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[1] = objid;

    /* draw level onto the HP bar */
    draw_level(&party_opponent[0], LVL_OS_OFFSET, objid_main);
    p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[2] = hpbar_build_full(&party_opponent[0], HPBAR_OS_X, HPBAR_OS_Y, HPBAR_OS_TAG);
    return 0;
}

u8 spawn_hpbox_player(u16 tag, s16 x, s16 y)
{
    /* Create HP Box object for player */
    struct SpritePalette hpbox_sprite_pal = {(void*)hpbox_player_singlesPal, tag};
    struct SpriteTiles hpbox_sprite_gfx = {(void*)hpbox_player_singlesTiles, 4096, tag};
    struct Template hpbox_temp = {tag, tag, &hpbox_oam, nullframe, &hpbox_sprite_gfx, nullrsf, (ObjectCallback)oac_nullsub};

    // init structs. HP box is 2 Objects put together
    gpu_tile_obj_decompress_alloc_tag_and_upload(&hpbox_sprite_gfx);
    gpu_pal_decompress_alloc_tag_and_upload(&hpbox_sprite_pal);
    u8 objid_main = template_instanciate_forward_search(&hpbox_temp, x, y, 0);
    u8 objid = template_instanciate_forward_search(&hpbox_temp, x + 64, y, 0);
    objects[objid].final_oam.tile_num += 64;
    p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[0] = objid_main;
    p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[1] = objid;

    /* draw elements onto HP bar */
    draw_name(&party_player[0], NAME_PS_OFFSET1, NAME_PS_OFFSET2, objid_main, HPFONT_PLAYER_SINGLE);
    draw_level(&party_player[0], LVL_PS_OFFSET, objid_main);
    draw_hp(&party_player[0], HPNUM_PS_OFFSET, objid_main);
    p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[2] = hpbar_build_full(&party_player[0], HPBAR_PS_X, HPBAR_PS_Y, HPBAR_PS_TAG);
    return 0;
}

void opp_hpbar_slidin_slow(u8 t_id)
{
    tasks[t_id].priv[0] += 4;
    if (tasks[t_id].priv[0] > 128) {
        task_del(t_id);
        return;
    }

    objects[p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[0]].pos1.x += 4;
    objects[p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[1]].pos1.x += 4;
    objects[p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[2]].pos1.x += 4;
}

void player_hpbar_slidin_slow(u8 t_id)
{
    tasks[t_id].priv[0] += 4;
    if (tasks[t_id].priv[0] > 128) {
        task_del(t_id);
        bs_anim_status = 0;
        return;
    }
    objects[p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[0]].pos1.x -= 4;
    objects[p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[1]].pos1.x -= 4;
    objects[p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[2]].pos1.x -= 4;  
}

void spawn_hpboxes_wild(void)
{
    spawn_hpbox_opponent(HPBOX_TAG_OPP_SW, HPBOX_OPP_SW_X, HPBOX_OPP_SW_Y);
    objects[p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[0]].pos1.x -= 128;
    objects[p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[1]].pos1.x -= 128;
    objects[p_bank[OPPONENT_SINGLES_BANK]->objid_hpbox[2]].pos1.x -= 128;
    task_add(opp_hpbar_slidin_slow, 1);
    spawn_hpbox_player(HPBOX_TAG_PLAYER_SINGLE, HPBOX_PLAYER_SINGLE_X, HPBOX_PLAYER_SINGLE_Y);
    objects[p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[0]].pos1.x += 128;
    objects[p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[1]].pos1.x += 128;
    objects[p_bank[PLAYER_SINGLES_BANK]->objid_hpbox[2]].pos1.x += 128;
}

void hpbar_apply_dmg(u8 task_id)
{
    u8 bank = tasks[task_id].priv[0];
    if (p_bank[bank]->this_pkmn->current_hp < tasks[task_id].priv[1]) {
        p_bank[bank]->this_pkmn->current_hp -= 1;
        refresh_hp(p_bank[bank]->this_pkmn, p_bank[bank]->objid_hpbox[2]);
        if (bank == PLAYER_SINGLES_BANK)
            draw_hp(p_bank[bank]->this_pkmn, HPNUM_PS_OFFSET, p_bank[bank]->objid_hpbox[0]);
    } else {
        task_del(task_id);
    }
}

