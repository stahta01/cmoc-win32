
#include "_long.h"

asm char* _ltoa(long_t* src, char* dst)
{
    asm {
        ldx     2,s
        ldy     4,s
        pshs    y
        ldd     2,x
        pshs    d
        ldd     0,x
        pshs    d
        bsr     ___ltoa
        leas    6,s
    }
}

