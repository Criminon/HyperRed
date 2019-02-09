.org 0x080173AC
    ldr r3, =(b_std_message|1)
    bx r3
.pool

.org 0x08069958
    ldr r0, =(SafariZoneAndScriptEnableHook|1)
    bx r0
.pool

.org 0x0807F5CC
    .word 0x8751BB4
