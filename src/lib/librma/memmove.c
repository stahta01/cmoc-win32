
#define _FILE "alib/memmove.as"
#include "_rma.h"

unsigned asm memmove(unsigned dst, unsigned src, unsigned len)
{
    asm {
        ldy     2,s
        ldx     4,s
        ldd     6,s
        bsr     MEMMOVE
        ldd     2,s
    }
}

