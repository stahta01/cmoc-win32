
#include "_memory.h"

asm void* memlsr(void* dst, size_t size)
{
    asm {
        ldy     4,s                                 // y = size
        beq     return                              // return if zero
        ldx     2,s                                 // x = dst
        lsr     ,x+                                 // lsr first byte
        dey                                         // decrease size
        beq     return                              // return if done
        repeat:
        ror     ,x+                                 // rol next byte
        dey                                         // decrease size
        bne     repeat                              // loop if not done
        return:
        ldd     2,s                                 // return dst
    }
}

