
#include "_fat.h"

asm void fat_load(int drive)
{
    asm {
        lda     3,s
        sta     _DCDRV
        pshs    u
        jsr     $c79d                           // MAKE SURE RAM FILE ALLOCATION TABLE DATA IS VALID
        puls    u
    }
}

