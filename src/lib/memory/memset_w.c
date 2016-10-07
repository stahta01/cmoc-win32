
#include "_memory.h"

asm void memset_w(void* dst, word val, size_t size)
{
    asm {
        ldy     6,s
        beq     exit
        ldd     4,s
        ldx     2,s
        loop:
        std     ,x++
        leay    -1,y
        bne     loop
        exit:
    }
}

