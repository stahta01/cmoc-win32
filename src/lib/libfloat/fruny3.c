
#include "_float.h"

asm void _fruny3(void)
{
    asm {
        pshs    u
        ldx     8,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        ldx     6,s
        jsr     ,y                              // CALL FLOATING POINT ROUNTINE
        ldx     4,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
        ldd     2,s
    }
}

