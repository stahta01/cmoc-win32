
#include "_memory.h"

asm void* memlsr(void* dst, size_t size)
{
    asm {
        ldy     4,s                             // y = size
        beq     exit                            // exit if zero
        ldx     2,s                             // x = dst
        lsr     ,x+                             // lsr first byte
        dey                                     // decrease size
        beq     exit                            // exit if done
        loop:
        ror     ,x+                             // rol next byte
        dey                                     // decrease size
        bne     loop                            // loop if not done
        exit:
        ldd     2,s                             // return dst
    }
}

