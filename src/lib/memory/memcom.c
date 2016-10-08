
#include "_memory.h"

void asm memcom(void* ptr, size_t size)
{
    asm {
        ldy     4,s
        beq     endloop
        ldx     2,s
        loop:
        com     ,x+
        leay    -1,y
        bne     loop
        endloop:
    }
}

