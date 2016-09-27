
#include "_long.h"

asm long_t* _lshl(long_t* dst, long_t* src, word count)
{
    asm {
        ldd     6,s
        ldx     4,s
        pshs    x
        bsr     lshl_call
        ldy     2,s
        ldd     0,x
        std     0,y
        ldd     2,x
        std     2,y
        tfr     y,d
        rts
        lshl_call:
        bra     ___lshl
    }
}

