
#define _FILE "alib/memmove.as"
#include "../rma/_rma.h"

asm void* memmove(void* dst, void* src, unsigned len)
{
    asm {
        ldy     2,s
        ldx     4,s
        ldd     6,s
        bsr     MEMMOVE
        ldd     2,s
    }
}

