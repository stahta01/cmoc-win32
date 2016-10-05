
#include "_float.h"

asm int _ftoi(float_t* f)
{
    asm {
        ldx     2,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        clr     _VALTYP
        jsr     _INTCNV                         // CONVERT FPA0 TO INTEGER IN ACCD
    }
}

