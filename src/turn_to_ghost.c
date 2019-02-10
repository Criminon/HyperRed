#include <pokeagb/pokeagb.h>

void dp01_build_cmdbuf_x10_TODO(u8, u32);
void b_active_side_mark_buffer_for_execution(u8);
void bag_add_item(u16 item, u8 amount);
extern void dprintf(const char * str, ...);

#define GHOST_SPECIES 0xFC
#define GHOST_EEVEE 0xFD
#define SPECIES_EEVEE 0x85

static u32* gRollPrevention = (u32*)0x0203E574;


bool PIDInPrevention(u32 PID)
{
    if (!PID) return true;
    for (u8 i = 0; i < 6; i++) {
        if (gRollPrevention[i] == PID) {
            return true;
        }
    }
    return false;
}


void PIDAddPrevention(u32 PID)
{
    for (u8 i = 0; i < 6; i++) {
        if (gRollPrevention[i] == 0) {
            gRollPrevention[i] = PID;
            return;
        }
    }
}


void TurnFaintedPokemonIntoGhost()
{
    // debugging
    for (u8 i = 0; i < gPartyCount; i++) {
        if ((party_player[i].hp == 0) && (!PIDInPrevention(party_player[i].box.pid))) {
            // roll to species shift pokemon 10% chance
            PIDAddPrevention(party_player[i].box.pid);
            if (rand() % 6 <= 1) {
                u16 species = GHOST_SPECIES;
                pokemon_setattr(&party_player[i], REQUEST_SPECIES, &species);
                recalculate_stats(&party_player[i]);
            }
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
    bool eevee_in_party = false;
    bool evolve_eevee = false;
    u8 eevee_slot = 0;
    for (u8 i = 0; i < gPartyCount; i++) {
        u16 species = pokemon_getattr(&party_player[i], REQUEST_SPECIES, NULL);
        if (species == GHOST_SPECIES) {
            u16 item = pokemon_getattr(&party_player[i], REQUEST_HELD_ITEM, NULL);
            if (item) {
                bag_add_item(item, 1);
            }
            DeletePokemon(i);
            deleted++;
            i--;
            evolve_eevee = true;
        } else if (species == SPECIES_EEVEE) {
            eevee_slot = i;
            eevee_in_party = true;
        }
    }
    gPartyCount -= deleted;
    memset(gRollPrevention, 0, 4 * 6);
    // add fainted mons to prevention
    for (u8 i = 0; i < gPartyCount; i++) {
        if (party_player[i].hp == 0) {
            PIDAddPrevention(party_player[i].box.pid);
        }
    }
    if (evolve_eevee && eevee_in_party) {
        dprintf("eevee evolution trigger conditions reached\n");
        u8 happiness = pokemon_getattr(&party_player[eevee_slot], REQUEST_HAPPINESS, NULL);
        if (happiness >= 150) {
            var_8004 = SPECIES_EEVEE;
            var_8005 = GHOST_EEVEE;
            script_env_init_script((void*)0x8751C16);

        } else {
            dprintf("current happiness is %d, expected 150 for evolution.\n", happiness);
            eevee_in_party = false;
        }

    }
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
