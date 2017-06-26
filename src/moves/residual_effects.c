#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_state.h"
#include "moves/moves.h"
#include "../battle_text/battle_pick_message.h"

extern void pick_battle_message(u16 move_id, u8 user_bank, enum BattleFlag battle_type, enum battle_string_ids id, u16 effect_id);

/* 
 * Residual functions are executed in priority order. A residual function, upon completion,
 * must again call exec_residual_effect so all residual effects are resolved.
 *
 */
/* void add_residual_effect(ResidualEffectCallback effect, u8 bank, u8 t_bank, u8 priority)
{
    u8 i;
    for (i = 0; i < 20; i++) {
        ResidualEffectCallback func = battle_master->residual[i].func;
        if ((func == NULL) || (func == effect)) {
            battle_master->residual[i].func = effect;
            battle_master->residual[i].src_bank = bank;
            battle_master->residual[i].target_bank = t_bank;
            battle_master->residual[i].priority = priority;
            return;
        }
    }
}


void del_residual_effect(ResidualEffectCallback effect, u8 bank)
{
    u8 i;
    for (i = 0; i < 20; i++) {
        ResidualEffectCallback func = battle_master->residual[i].func;
        if (func == effect) {
            battle_master->residual[i].func = NULL;
            return;
        }
    }
}


void exec_residual_effect(u8 bank, u8 priority_override, u8 index)
{
    u8 i, priority;
    for (priority = priority_override; priority < 15; priority++) {
        for (i = index; i < 20; i++) {
            if ((battle_master->residual[i].func) && (battle_master->residual[i].priority == priority)) {
                u8 t_id = task_add(battle_master->residual[i].func, 0x1);
                tasks[t_id].priv[0] = bank;
                tasks[t_id].priv[1] = priority;
                tasks[t_id].priv[2] = i + 1;
                super.multi_purpose_state_tracker = 0x99;
            }
        }
    }
}



void curse_residual_effect(u8 task_id)
{
    extern void hpbar_apply_dmg(u8 task_id);
    struct Task* t = &tasks[task_id];
    u8 bank = t->priv[0];
    switch (t->priv[3]) {
        case 0:
            pick_battle_message(MOVE_CURSE, bank, battle_type_flags, STRING_CURSE_RESIDUAL, MOVE_CURSE);
            battle_show_message((u8*)string_buffer, 0x18);
            t->priv[3]++;
            break;
        case 1:
           if (!dialogid_was_acknowledged(0x18 & 0x3F)) {
                t->priv[3]++;
            }
            break;
        case 2:
            {
                struct Pokemon* p = p_bank[bank]->this_pkmn;
                u16 dmg = pokemon_getattr(p, REQUEST_TOTAL_HP, NULL) / 4;
                u16 current_hp = pokemon_getattr(p, REQUEST_CURRENT_HP, NULL);
                u8 t_id = task_add(hpbar_apply_dmg, 0x1);
                tasks[t_id].priv[0] = bank;
                if (current_hp < dmg) {
                    tasks[t_id].priv[1] = current_hp;
                } else {
                    tasks[t_id].priv[1] = dmg;
                }
                t->priv[3]++;
                break;
            }
        case 3:
            {
                if (task_is_running(hpbar_apply_dmg)) {
                    return;
                }
                task_del(task_id);
                exec_residual_effect(tasks[task_id].priv[0], tasks[task_id].priv[1], tasks[task_id].priv[2]);
            }
            break;
    };     
}

 */




