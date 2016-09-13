
#include "_memory.h"

void asm memcom(void* ptr, size_t n)
{
    asm {
        ldx     2,s
        beq     exit$
        ldy     4,s
        beq     exit$
        loop$:
        com     ,x+
        leay    -1,y
        bne     loop$
        exit$:
    }
}

