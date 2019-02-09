        .gba
        .thumb
        .open "roms/BPRE0.gba","build/multi.gba", 0x08000000

        .include "armips_macros/macros.s"
        .include "patches/patch_ghost.s"


        .org 0x08801400
        .importobj "build/linked.o"
        .close
