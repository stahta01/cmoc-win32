
#include "_float.h"

asm float_t* _fdiv10(float_t* dst, float_t* src)
{
    asm {
        pshs    u
        ldx     6,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        jsr     _LBB82                          // DIVIDE FPA0 BY 10
        ldx     4,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
        ldd     2,s
    }
}

