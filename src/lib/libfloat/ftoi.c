
#include "_float.h"

int asm _ftoi(float_t* f)
{
    asm {
        ldx     2,s
        jsr     _LBC14
        clr     _VALTYP
        jsr     _INTCNV
    }
}

