
#include "_float.h"

void asm _fdiv(float_t* dst, float_t* fp1, float_t* fp2)
{
    asm {
        pshs    u
        ldx     8,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        ldx     6,s
        jsr     _LBB8F                          // DIVIDE (X) BY FPA0-LEAVE NORMALIZED QUOTIENT IN FPA0
        ldx     4,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
    }
}

