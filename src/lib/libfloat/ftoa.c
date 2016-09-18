
#include "_float.h"

void asm _ftoa(char* dst, float_t* src)
{
    asm {
        pshs    u
        ldx     6,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        ldu     4,s
        jsr     _LBDDC                          // CONVERT FP NUMBER TO ASCII STRING (U)
        puls    u
        ldd     2,s
    }
}

