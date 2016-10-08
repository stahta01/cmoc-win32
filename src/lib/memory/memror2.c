
#include "_memory.h"

asm void* memror2(void* dst, int val, size_t size)
{
    asm {
        ldy     6,s                                 // y = size
        beq     return                              // return if zero
        ldx     2,s                                 // x = dst
        lda     5,s                                 // a = val
        rora                                        // ror 2 bits
        rorb
        rora
        rolb
        repeat:
        lda     ,x
        rora
        rorb
        rora
        rolb
        sta     ,x+
        dey
        bne     repeat                              // repeat until done
        return:
        ldd     2,s
    }
}

