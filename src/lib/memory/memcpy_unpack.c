
#include "_memory.h"

asm void memcpy_unpack(void* dst, void* src, size_t count, size_t size, size_t dstoff)
{
    asm {
        pshs    u
        ldd     8,s                                 // validate count
        beq     return
        ldd     10,s                                // validate size
        beq     return
        ldx     4,s                                 // x = dst
        ldu     6,s                                 // u = src
        ldd     12,s                                // d = dstoff
        subd    10,s                                // d -= size
        repeat$outer:
        ldy     10,s                                // y = size
        repeat$inner:
        lda     ,u+
        sta     ,x+
        dey
        bne     repeat$inner
        abx
        ldy     8,s                                 // y = count
        dey
        sty     8,s
        bne     repeat$outer
        return:
        puls    u
    }
}

