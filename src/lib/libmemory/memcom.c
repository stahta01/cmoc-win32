
#include "_memory.h"

void asm _memcom(void* ptr, size_t n)
{
    asm {
        ldx     2,s
        ldy     4,s
        beq     LEXIT
        LLOOP:
        com     ,x+
        leay    -1,y
        bne     LLOOP
        LEXIT:
    }
}

