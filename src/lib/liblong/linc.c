
#include "_long.h"

asm long_t* _linc(long_t* l)
{
    asm {
        ldx     2,s
        bsr     ___linc
        ldd     2,s
    }
}

