.align 2
.thumb
.global EvolvePokemon
EvolvePokemon:
    push {r4, lr}
        ldr r0, =0x300537C
        ldr r1, =0x80568E1
        str r1, [r0]
        ldr r0, =0x020370C0
        ldrh r1, [r0, #2]
        mov r2, #1
        ldrh r3, [r0, #0x10]
        ldr r4, =0x80cdda9
        bl bx_r4
    pop {r4, pc}

bx_r4:
    bx r4

.pool

.align 2
.thumb
.global FindPokemonSlots

FindPokemonSlots:
    push {r4, lr}
    mov r4, #0
    loop:
    ldr r0, =0x02024284
    mov r1, #0x64
    mul r1, r4
    add r0, r0, r1
    mov r1, #0xb
    ldr r2, =0x803FBE9
    bl bx_r2
    ldr r1, =0x20370C0
    ldrh r2, [r1]
    cmp r0, r2
    beq have_pre
    add r4, #1
    cmp r4, #6
    bne loop

no_pokemon:
    mov r4, #0xFF
    b back

increment:
    add r4, #1
    cmp r4, #6
    beq no_pokemon
    b loop

have_pre:
    ldr r0, =0x2024284
    mov r1, #0x64
    mul r1, r4
    add r0, r0, r1
    mov r1, #0x2d
    ldr r2, =0x803FBE9
    bl bx_r2
    ldr r1, =0x20370C0
    cmp r0, #1
    beq increment

back:
    strh r4, [r1, #0x10]
    pop {r4, pc}

bx_r2:
    bx r2

.pool
