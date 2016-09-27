
#include "_long.h"

asm long_t* _lshr(long_t* dst, long_t* src, word count)
{
    asm {
        ldd     6,s
        ldx     4,s
        pshs    x
        bsr     lshr_call
        ldy     2,s
        ldd     0,x
        std     0,y
        ldd     2,x
        std     2,y
        tfr     y,d
        rts
        lshr_call:
        bra     ___lshr
    }
}

