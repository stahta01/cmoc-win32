
#define _FILE "alib/memmove.as"
#include "_alib.h"

unsigned asm memmove(unsigned dst, unsigned src, unsigned len)
{
    asm {
        ldy     2,s
        ldx     4,s
        ldd     6,s
        lbsr    MEMMOVE
        ldd     2,s
    }
}

