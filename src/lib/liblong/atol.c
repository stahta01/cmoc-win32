
#include "_long.h"

asm long_t* _atol(char* src, long_t* dst)
{
    asm {
        ldd     2,s
        pshs    d
        bsr     ___atol
        puls    d
        ldy     4,s
        ldd     0,x
        std     0,y
        ldd     2,x
        std     2,y
        tfr     y,d
    }
}

