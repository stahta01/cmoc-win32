
#include "_long.h"

asm long_t* _ldec(long_t* l)
{
    asm {
        ldx     2,s
        bsr     ___ldec
        ldd     2,s
    }
}

