
#include "_memory.h"

asm void memset_w(void* dst, word val, size_t size)
{
    asm {
        ldy     6,s                                 // y = size
        beq     return                              // return if size = 0
        ldd     4,s                                 // d = val
        ldx     2,s                                 // x = dst
        repeat:
        std     ,x++                                // store val
        leay    -1,y
        bne     repeat                              // repeat until done
        return:
    }
}

