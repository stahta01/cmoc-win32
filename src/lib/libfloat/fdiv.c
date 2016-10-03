
#include "_float.h"

asm float_t* _fdiv(float_t* dst, float_t* fp1, float_t* fp2)
{
    asm {
        ldy     #_LBB8F
        jmp     _fruny3
        /*
        pshs    u
        ldx     8,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        ldx     6,s
        jsr     _LBB8F                          // DIVIDE (X) BY FPA0-LEAVE NORMALIZED QUOTIENT IN FPA0
        ldx     4,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
        ldd     2,s
        */
    }
}

