
#include "_memory.h"

void asm memcom(void* ptr, size_t size)
{
    asm {
        ldy     4,s                                 // y = size
        beq     return
        ldx     2,s                                 // x = dst
        repeat:
        com     ,x+
        leay    -1,y
        bne     repeat
        return:
    }
}

