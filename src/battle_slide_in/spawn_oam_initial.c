#include <pokeagb/pokeagb.h>
#include "battle_obj_sliding.h"
#include "../battle_data/pkmn_bank.h"

// back sprites
#include "../../generated/images/backsprites/female_player.h"
#include "../../generated/images/backsprites/male_player.h"
#include "../../generated/images/backsprites/may.h"
#include "../../generated/images/backsprites/brendon.h"
#include "../../generated/images/backsprites/oldman.h"
#include "../../generated/images/backsprites/poke_dude.h"

// unique battle tags
#define OPP1_BTAG 0x100
#define PLAYER_BTAG 0x300

// initial positions before starting to apply sliding
#define PLAYER_X_POS_SLIDE -188
#define OPP1_X_POS_SLIDE -80

const struct OamData opp_oam = {
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


static const struct Frame (**nullframe)[] = (const struct Frame (**)[])0x8231CF0;
static const struct RotscaleFrame (**nullrsf)[] = (const struct RotscaleFrame (**)[])0x8231CFC;


void oac_nullsub(struct Object* obj)
{
    return;
}

void* get_pal_pkmn(struct Pokemon* p, u16 species)
{
    // check shiny
    if (pokemon_getattr(p, REQUEST_ABILITY_BIT, NULL)) {
        return (void*)pokemon_palette_shiny[species].data;
    } else {
        return (void*)pokemon_palette_normal[species].data;
    }
}

u8 spawn_pkmn_obj_slot(u8 slot, u16 tag)
{
    struct Pokemon* pkmn = (struct Pokemon*)0x202402C;

    u16 species = pokemon_getattr(&pkmn[slot], REQUEST_SPECIES, NULL);
    void* pkmn_pal = get_pal_pkmn(&pkmn[slot], species);
    void* pkmn_gfx = (void*)pokemon_graphics_front[species].data;

    struct SpritePalette pkmn_sprite_pal = {pkmn_pal, tag};
    struct SpriteTiles pkmn_sprite_gfx = {pkmn_gfx, 2048, tag};
    struct Template pkmn_temp = {tag, tag, &opp_oam, nullframe, &pkmn_sprite_gfx, nullrsf, (ObjectCallback)oac_nullsub};

    gpu_tile_obj_decompress_alloc_tag_and_upload(&pkmn_sprite_gfx);
    gpu_pal_decompress_alloc_tag_and_upload(&pkmn_sprite_pal);
    return template_instanciate_forward_search(&pkmn_temp, OPP1_X_POS_SLIDE, 54, 0);
}

u8 spawn_pkmn_backsprite_obj_slot(u8 slot, u16 tag)
{
    struct Pokemon* pkmn = (struct Pokemon*)0x202402C;

    u16 species = pokemon_getattr(&pkmn[slot], REQUEST_SPECIES, NULL);
    void* pkmn_pal = get_pal_pkmn(&pkmn[slot], species);
    void* pkmn_gfx = (void*)pokemon_graphics_back[species].data;

    struct SpritePalette pkmn_sprite_pal = {pkmn_pal, tag};
    struct SpriteTiles pkmn_sprite_gfx = {pkmn_gfx, 2048, tag};
    struct Template pkmn_temp = {tag, tag, &opp_oam, nullframe, &pkmn_sprite_gfx, nullrsf, (ObjectCallback)oac_nullsub};

    gpu_tile_obj_decompress_alloc_tag_and_upload(&pkmn_sprite_gfx);
    gpu_pal_decompress_alloc_tag_and_upload(&pkmn_sprite_pal);
    u8 species_y = pokemon_player_xy_table[species] >> 8;
    return template_instanciate_forward_search(&pkmn_temp, 64, 80 + species_y, 0);
}

u8 spawn_backsprite_npc(u8 sprite_id, u16 tag)
{
    void* player_pal;
    void* player_gfx;

    // use graphic based on sprite id override, otherwise use gender
    if (sprite_id < 0xFF) {
        switch (sprite_id) {
            case 0:
                player_pal = (void*)female_playerPal;
                player_gfx = (void*)female_playerTiles;
                break;
            case 1:
                player_pal = (void*)male_playerPal;
                player_gfx = (void*)male_playerTiles;
                break;
            case 2:
                player_pal = (void*)mayPal;
                player_gfx = (void*)mayTiles;
                break;
            case 3:
                player_pal = (void*)brendonPal;
                player_gfx = (void*)brendonTiles;
                break;
            case 4:
                player_pal = (void*)oldmanPal;
                player_gfx = (void*)oldmanTiles;
                break;
            default:
                player_pal = (void*)poke_dudePal;
                player_gfx = (void*)poke_dudeTiles;
                break;
        };
    } else {
        // gender based player character
        if (walkrun_state.gender) {
            player_pal = (void*)female_playerPal;
            player_gfx = (void*)female_playerTiles;
        } else {
            player_pal = (void*)male_playerPal;
            player_gfx = (void*)male_playerTiles;
        }
    }
    struct SpritePalette player_sprite_pal = {player_pal, tag};
    struct SpriteTiles player_sprite_gfx = {player_gfx, 2048, tag};
    struct Template player_temp = {tag, tag, &opp_oam, nullframe, &player_sprite_gfx, nullrsf, (ObjectCallback)oac_nullsub};

    gpu_tile_obj_decompress_alloc_tag_and_upload(&player_sprite_gfx);
    gpu_pal_decompress_alloc_tag_and_upload(&player_sprite_pal);
    u8 objid = template_instanciate_forward_search(&player_temp, PLAYER_X_POS_SLIDE, 81, 0);
    objects[objid].final_oam.obj_mode = 1;
    return objid;
}

void wild_battle_slidein()
{
    // wild mon first
    u8 objid = spawn_pkmn_obj_slot(0, OPP1_BTAG);
    p_bank[2]->objid = objid;

    // gender based player character
        if (walkrun_state.gender) {
            objid = spawn_backsprite_npc(0, PLAYER_BTAG);
        } else {
            objid = spawn_backsprite_npc(1, PLAYER_BTAG);
        }
    
    bs_env_windows->player_trainer_objid = objid;
}







