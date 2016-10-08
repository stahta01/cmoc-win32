
#include "_memory.h"

asm void* memrol2(void* dst, int val, size_t size)
{
    asm {
        ldy     6,s                                 // y = size
        beq     return                              // return if zero
        tfr     y,d                                 // d = y
        ldx     2,s                                 // x = dst
        leax    d,x                                 // offset x by size
        lda     5,s                                 // a = val
        rola                                        // rol 2 bits
        rolb
        rola
        rorb
        repeat:
        lda     ,-x
        rola
        rolb
        rola
        rorb
        sta     ,x
        dey
        bne     repeat                              // repeat until done
        return:
        ldd     2,s
    }
}

