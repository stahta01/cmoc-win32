
#include "_float.h"

void asm _itof(float_t* dst, int src)
{
    asm {
        pshs    u
        ldd     6,s
        jsr     _GIVABF                         // CONVERT THE VALUE IN ACCD INTO A FLOATING POINT NUMBER IN FPA0
        ldx     4,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
    }
}

