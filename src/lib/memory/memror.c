
#include "_memory.h"

asm void* memror(void* dst, int val, size_t size)
{
    asm {
        ldy     6,s                                 // y = size
        beq     exit                                // exit if zero
        ldx     2,s                                 // x = dst
        ror     5,s                                 // get cc from val byte
        loop:
        ror     ,x+                                 // rol next byte
        dey                                         // decrease size
        bne     loop                                // loop if not done
        exit:
        ldd     2,s                                 // return dst
    }
}

