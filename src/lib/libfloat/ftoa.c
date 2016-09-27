
#include "_float.h"

asm char* _ftoa(float_t* src, char* dst)
{
    asm {
        pshs    u
        ldx     4,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        ldu     6,s
        jsr     _LBDDC                          // CONVERT FP NUMBER TO ASCII STRING (U)
        puls    u
        ldd     4,s
    }
}

