
#include "_memory.h"

asm void* memror(void* dst, size_t size, int cc)
{
    asm {
        ldy     4,s                             // y = size
        beq     exit                            // exit if zero
        ldx     2,s                             // x = dst
        clra                                    // get cc from parameter
        cmpa    7,s
        loop:
        ror     ,x+                             // rol next byte
        dey                                     // decrease size
        bne     loop                            // loop if not done
        exit:
        ldd     2,s                             // return dst
    }
}

