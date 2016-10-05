
#include "_long.h"

asm long_t* _ladd(long_t* dst, long_t* slx, long_t* sly)
{
    asm {
        ldx     6,s
        ldy     4,s
        ldd     2,y
        pshs    d
        ldd     0,y
        pshs    d
        bsr     ___ladd
        ldy     2,s
        ldd     0,x
        std     0,y
        ldd     2,x
        std     2,y
        tfr     y,d
    }
}

