     .gba
        .thumb
        .open "roms/BPRE0.gba","build/multi.gba", 0x08000000

       // .include "patches/bx_setup.s"

        .org 0x09000000
        .importobj "build/linked.o"
        .close