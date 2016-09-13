
#define _FILE "alib/to_lowrs.as"
#include "_rma.h"

void asm to_lowrs(char* s)
{
    asm {
        ldx     2,s
        bsr     TO_LOWRS
        ldd     2,s
    }
}

