#include <pokeagb/pokeagb.h>
#include "../battle_data/pkmn_bank.h"
#include "../battle_state.h"
#include "../moves/moves.h"
#include "battle_abilities.h"


typedef u16 (*StatCallback)(u8, u16);

/* 
 * Ability stat modifier callback execution
 */

 s8 ability_priority_mod(u8 bank, u16 move_id) {
    u8 ability = p_bank[bank]->b_data.ability;
    
    // ability doesn't exist in table
    if (ability > ABILITIES_MAX)
        return 0;
        
    // check callback exists for ability
    if (abilities_table[ability]->on_priority_mod) {
        // exec callback from ability
        return abilities_table[ability]->on_priority_mod(bank, move_id);
    }
    // callback doesn't exit, priority is modded by 0
    return 0;
}

u16 ability_attack_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_attack) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_attack(bank, stat);
    }
    return 0;
}

u16 ability_defense_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_defense) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_defense(bank, stat);
    }
    return 0;
}

u16 ability_speed_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_speed) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_speed(bank, stat);
    }
    return 0;
}

u16 ability_sp_defense_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_sp_defense) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_sp_defense(bank, stat);
    }
    return 0;
}

u16 ability_sp_attack_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_sp_attack) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_sp_attack(bank, stat);
    }
    return 0;
}

u16 ability_critchance_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_critchance) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_critchance(bank, stat);
    }
    return 0;
}

u16 ability_accuracy_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_accuracy) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_evasion(bank, stat);
    }
    return 0;
}

u16 ability_evasion_mod(u8 bank, u16 stat) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return 0;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_evasion) {
        return abilities_table[p_bank[bank]->b_data.ability]->on_evasion(bank, stat);
    }
    return 0;
}

void ability_on_before_switch(u8 bank) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_before_switch) {
        abilities_table[p_bank[bank]->b_data.ability]->on_before_switch(bank);
    }
}

void ability_on_switch(u8 bank) {
    if (p_bank[bank]->b_data.ability > ABILITIES_MAX)
        return;
    if (abilities_table[p_bank[bank]->b_data.ability]->on_switch) {
        abilities_table[p_bank[bank]->b_data.ability]->on_switch(bank);
    }
}

void ability_on_modify_move(u8 attacker, u8 defender, u16 move) {
    if (p_bank[attacker]->b_data.ability > ABILITIES_MAX)
        return;
    if (abilities_table[p_bank[attacker]->b_data.ability]->on_modify_move) {
        abilities_table[p_bank[attacker]->b_data.ability]->on_modify_move(attacker, defender, move);
    }
}

u8 ability_on_tryhit(u8 attacker, u8 defender, u16 move) {
    if (p_bank[attacker]->b_data.ability > ABILITIES_MAX)
        return true;
    if (abilities_table[p_bank[attacker]->b_data.ability]->on_tryhit) {
        return abilities_table[p_bank[attacker]->b_data.ability]->on_tryhit(attacker, defender, move);
    }
}

