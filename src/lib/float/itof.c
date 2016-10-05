
#include "_float.h"

asm float_t* _itof(int src, float_t* dst)
{
    asm {
        pshs    u
        ldd     4,s
        jsr     _GIVABF                         // CONVERT THE VALUE IN ACCD INTO A FLOATING POINT NUMBER IN FPA0
        ldx     6,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
        ldd     4,s
    }
}

