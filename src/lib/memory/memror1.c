
#include "_memory.h"

asm void* memror1(void* dst, int val, size_t size)
{
    asm {
        ldy     6,s                                 // y = size
        beq     return                              // return if zero
        ldx     2,s                                 // x = dst
        ror     5,s                                 // get cc from val byte
        repeat:
        ror     ,x+                                 // rol next byte
        dey                                         // decrease size
        bne     repeat                              // repeat if not done
        return:
        ldd     2,s                                 // return dst
    }
}

