#include <pokeagb/pokeagb.h>
#include "../battle_data/pkmn_bank.h"
#include "battle_obj_sliding.h"

// back sprites
#include "../../generated/images/backsprites/female_player.h"
#include "../../generated/images/backsprites/male_player.h"
#include "../../generated/images/backsprites/may.h"
#include "../../generated/images/backsprites/brendon.h"
#include "../../generated/images/backsprites/oldman.h"
#include "../../generated/images/backsprites/poke_dude.h"

extern void make_spinning_pokeball(s16 x, s16 y, u8 bank);

void allys_move_into_scene(void)
{
    // player move into scene
    if (bs_env_windows->player_trainer_objid != 0x3F)
        objects[bs_env_windows->player_trainer_objid].pos1.x -= 3;
}


void opponents_move_into_scene(void)
{
   // opponent move into scene
    if (p_bank[OPPONENT_SINGLES_BANK]->objid != 0x3F)
        objects[p_bank[OPPONENT_SINGLES_BANK]->objid].pos1.x += 3;
}

void obj_mode_normal_set(u8 objid)
{
    if (objid == 0x3F)
        return;
    objects[objid].final_oam.obj_mode = 0;
}

void player_set_frame(void* dst, u8 sprite_id, u8 frame)
{
    void* player_gfx;

    // use graphic based on sprite id override, otherwise use gender
    if (sprite_id < 0xFF) {
        switch (sprite_id) {
            case 0:
                player_gfx = (void*)female_playerTiles;
                break;
            case 1:
                player_gfx = (void*)male_playerTiles;
                break;
            case 2:
                player_gfx = (void*)mayTiles;
                break;
            case 3:
                player_gfx = (void*)brendonTiles;
                break;
            case 4:
                player_gfx = (void*)oldmanTiles;
                break;
            default:
                player_gfx = (void*)poke_dudeTiles;
                break;
        };
    } else {
        // gender based player character
        if (walkrun_state.gender) {
            player_gfx = (void*)female_playerTiles;
        } else {
            player_gfx = (void*)male_playerTiles;
        }
    }
    void* buff = (void*)malloc(2048 * 5); // frame count
    lz77UnCompVram((void *)player_gfx, buff);
    player_gfx = (buff + (32 * 8 * 8 * frame));
    memcpy(dst, player_gfx, 32 * 8 * 8);
    free(buff);
    return;    
}

void player_throwball_and_moveout_scene(struct Object* obj)
{
    void* dst = (void*)((obj->final_oam.tile_num * 32) + 0x6010000);
    switch (obj->priv[0]) {
        case 0:
            player_set_frame(dst, 0xFF, 1);
            obj->priv[0]++;
            break;
        case 1:
            if (obj->pos1.x < -459) {
                player_set_frame(dst, 0xFF, 2);
                obj->priv[0]++;
            } else {
                obj->pos1.x--;
            }
            break;
        case 2:
            if (obj->pos1.x < -485) {
                player_set_frame(dst, 0xFF, 3);
                obj->priv[0]++;
                
            } else {
                obj->pos1.x -= 2;
            }
            break;
        case 3:
            if (obj->pos1.x < -505) {
                player_set_frame(dst, 0xFF, 4);
                obj->priv[0]++;
                make_spinning_pokeball(64, 64, obj->priv[2]);
            } else {
                obj->pos1.x -= 2;
            }
            break;
        case 4:
            if (obj->pos1.x < -530) {
                obj_free(obj);
            } else {
                obj->pos1.x -= 2;
            }
            break;
    };
}




