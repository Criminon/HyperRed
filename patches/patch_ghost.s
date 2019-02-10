.org 0x080173AC
    ldr r3, =(b_std_message|1)
    bx r3
.pool

.org 0x08069958
    ldr r0, =(SafariZoneAndScriptEnableHook|1)
    bx r0
.pool


.org 0x8751C18
    .word FindPokemonSlots + 1
.pool

.org 0x8751C1D
    .word EvolvePokemon + 1
.pool

.org 0x8751C21
    .byte 0x27
    .byte 0x2
.pool
