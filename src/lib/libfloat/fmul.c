
#include "_float.h"

asm float_t* _fmul(float_t* dst, float_t* fp1, float_t* fp2)
{
    asm {
        pshs    u
        ldx     8,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        ldx     6,s
        jsr     _LBACA                          // MULTIPLY FPA0 BY (X) - RETURN PRODUCT IN FPA0
        ldx     4,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
        ldd     2,s
    }
}

