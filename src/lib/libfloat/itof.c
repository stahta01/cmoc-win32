
#include "_float.h"

void asm _itof(float_t* f, int val)
{
    asm {
        pshs    u
        ldd     6,s
        jsr     _GIVABF
        ldx     4,s
        jsr     _LBC35
        puls    u
    }
}

