// New specials

special 0xB
    .word special_purge_pkmn|1
    
special 0x3E
    .word special_add_vars|1

special 0x3F
    .word special_sub_vars|1

special 0x40
    .word special_multiply_vars|1

special 0x41
    .word special_divide_vars|1

special 0x42
    .word special_bAND_vars|1

special 0x43
    .word special_bOR_vars|1

special 0x44
    .word special_bXOR_vars|1

    