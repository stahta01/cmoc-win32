
#include "_long.h"

asm long_t* _linc(long_t* l)
{
    asm {
        ldx     2,s
        bsr     linc
        ldd     2,s
    }
}

asm long_t* _ldec(long_t* l)
{
    asm {
        ldx     2,s
        bsr     ldec
        ldd     2,s
    }
}

#define _FILE  "clincdec.as"
#include "../kreiderclib/_kreider.h"

