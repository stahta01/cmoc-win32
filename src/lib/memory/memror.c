
#include "_memory.h"

asm void* memror(void* dst, size_t size, int feed)
{
    asm {
        ldy     4,s                             // y = size
        beq     exit                            // exit if zero
        ldx     2,s                             // x = dst
        ror     7,s                             // get cc from first byte
        loop:
        ror     ,x+                             // rol next byte
        dey                                     // decrease size
        bne     loop                            // loop if not done
        exit:
        ldd     2,s                             // return dst
    }
}

