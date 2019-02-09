#include <pokeagb/pokeagb.h>

void dp01_build_cmdbuf_x10_TODO(u8, u32);
void b_active_side_mark_buffer_for_execution(u8);
void bag_add_item(u16 item, u8 amount);
extern void dprintf(const char * str, ...);

#define GHOST_SPECIES 0xFC

void TurnFaintedPokemonIntoGhost()
{
    // debugging
    for (u8 i = 0; i < gPartyCount; i++) {
        if ((party_player[i].hp == 0) && (party_player[i].box.unused == 0)) {
            // roll to species shift pokemon 10% chance
            if (rand() % 10 == 0) {
                u16 species = GHOST_SPECIES;
                pokemon_setattr(&party_player[i], REQUEST_SPECIES, &species);
                recalculate_stats(&party_player[i]);
            }
            party_player[i].box.unused = 1;
        } else {
            if (party_player[i].hp == 0)
                party_player[i].box.unused = 0;
        }
    }
}


void DeletePokemon(u8 i)
{
    if (i < 5) {
        memcpy(&party_player[i], &party_player[i + 1], (5 - i) * 100);
    }
    memset(&party_player[5], 0, 100);
}


void DeleteGhostsInOverworld()
{
    u8 deleted = 0;
    for (u8 i = 0; i < gPartyCount; i++) {
        if (pokemon_getattr(&party_player[i], REQUEST_SPECIES, NULL) == GHOST_SPECIES) {
            u16 item = pokemon_getattr(&party_player[i], REQUEST_HELD_ITEM, NULL);
            if (item) {
                if (get_item_quantity(item)) {
                    bag_add_item(item, 1);
                }
            }
            DeletePokemon(i);
            deleted++;
        }
    }
    gPartyCount -= deleted;
}


u8 SafariZoneAndScriptEnableHook()
{
    if (gPartyCount > 0) {
        FlagSet(0x828);
    } else {
        FlagClear(0x828);
    }
    DeleteGhostsInOverworld();
    return script_env_2.enabled;
}



void b_std_message(u32 active_side, u32 b)
{
    u8* b_active_side = (u8*)0x02023BC4;
    *b_active_side = b;
    if (gPartyCount)
        TurnFaintedPokemonIntoGhost();
    dp01_build_cmdbuf_x10_TODO(0, active_side);
    b_active_side_mark_buffer_for_execution(*b_active_side);
}
