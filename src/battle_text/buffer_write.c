#include <pokeagb/pokeagb.h>
#include "../battle_data/pkmn_bank.h"
#include "../battle_data/pkmn_bank_stats.h"
#include "../moves/moves.h"
#include "battle_pick_message.h"

void buffer_write_pkmn_nick(pchar* buffer, u8 bank)
{
    memcpy(buffer, p_bank[bank]->this_pkmn->base.nick, sizeof(p_bank[bank]->this_pkmn->base.nick));
    buffer[sizeof(p_bank[bank]->this_pkmn->base.nick)] = 0xFF;

}

void buffer_write_player_name(pchar* buffer)
{
    pstrcpy(buffer, saveblock2->name);
}

void buffer_write_move_name(pchar* buffer, u16 move_id)
{
    pstrcpy(buffer, move_t[move_id].name);
}

void buffer_write_ability_name(pchar* buffer, u8 ability)
{
    pstrcpy(buffer, pokemon_ability_names[ability]);
}

void buffer_write_move_type(pchar* buffer, u16 move)
{
    pstrcpy(buffer, pokemon_type_names[MOVE_TYPE(move)]);
}

void buffer_write_stat_mod(pchar* buffer, u8 stat_id)
{
    switch (stat_id) {
        case REQUEST_ATK:
            pstrcpy(buffer, (pchar*)&str_stat_atk);
            break;
        case REQUEST_DEF:
            pstrcpy(buffer, (pchar*)&str_stat_def);
            break;
        case REQUEST_SPD:
            pstrcpy(buffer, (pchar*)&str_stat_spd);
            break;
        case REQUEST_SPATK:
            pstrcpy(buffer, (pchar*)&str_stat_spatk);
            break;
        case REQUEST_SPDEF:
            pstrcpy(buffer, (pchar*)&str_stat_spdef);
            break;
        case 51: // evasion
            pstrcpy(buffer, (pchar*)&str_stat_evn);
            break;
        case 52: // accuracy
            pstrcpy(buffer, (pchar*)&str_stat_acc);
            break;
        case 53: // crit
            pstrcpy(buffer, (pchar*)&str_stat_crit);
            break;
    };
}

void buffer_write_status_name(pchar* buffer, u8 status_id)
{
    switch (status_id) {
        case AILMENT_PARALYZE:
            pstrcpy(buffer, (pchar*)&str_status_paralyze);
            break;
        case AILMENT_BURN:
            pstrcpy(buffer, (pchar*)&str_status_burn);
            break;
        case AILMENT_POISON:
            pstrcpy(buffer, (pchar*)&str_status_poison);
            break;
        case AILMENT_SLEEP:
            pstrcpy(buffer, (pchar*)&str_status_sleep);
            break;
        case AILMENT_FREEZE:
            pstrcpy(buffer, (pchar*)&str_status_frozen);
            break;
        case AILMENT_BAD_POISON:
            pstrcpy(buffer, (pchar*)&str_status_bpoison);
            break;
        case AILMENT_CONFUSION:
            pstrcpy(buffer, (pchar*)&str_status_confuse);
            break;
    };
}


void fdecoder_battle(const pchar* buffer, u8 bank, u16 move_id, u16 move_effect_id)
{
    u16 len = pstrlen(buffer);
    pchar* result = (pchar*)malloc((len < 50) ? 100 : len * 2);
    u16 i, result_index;
    for (i = 0, result_index = 0; ((i < len) || (buffer[i] > 0xFE)); i++) {
        if (buffer[i] == 0xFD) {
            i++;
            switch (buffer[i]) {
                case 0xE:
                    // buffer Attacking Pokemon name
                    buffer_write_pkmn_nick(&(result[result_index]), bank);
                    result_index = pstrlen(result);
                    break;
                case 0xF:
                    // buffer move name
                    buffer_write_move_name(&(result[result_index]), move_id);
                    result_index = pstrlen(result);
                    break;
                case 0x10:
                    // buffer move effect name
                    buffer_write_move_name(&(result[result_index]), move_effect_id);
                    result_index = pstrlen(result);
                    break;
                case 0x11:
                    // buffer Defending Pokemon name 
                    buffer_write_pkmn_nick(&(result[result_index]), p_bank[bank]->b_data.my_target);
                    result_index = pstrlen(result);
                    break;
                case 0x12:
                    // ability Defending mon
                    {
                        u8 target_bank = p_bank[bank]->b_data.my_target;
                        buffer_write_ability_name(&result[result_index], BANK_ABILITY(target_bank));
                        result_index = pstrlen(result);
                        break;
                    }
                case 0x13:
                    // ability Attacking mon
                    {
                        buffer_write_ability_name(&result[result_index], BANK_ABILITY(bank));
                        result_index = pstrlen(result);
                        break;
                    }
                case 0x14:
                    // type of move
                    {
                        buffer_write_move_type(&result[result_index], move_id);
                        result_index = pstrlen(result);
                        break;
                    }
                case 0x15:
                    // stat name
                    {
                        buffer_write_stat_mod(&result[result_index], move_effect_id);
                        result_index = pstrlen(result);
                        break;
                    }
                case 0x16:
                    // status ailment name
                    {
                        buffer_write_status_name(&result[result_index], move_effect_id);
                        result_index = pstrlen(result);
                        break;
                    }
                default:
                    break;
            };
        } else {
            result[result_index] = buffer[i];
            result_index++;
        }
    }
    fdecoder(string_buffer, result);
    free(result);
}

