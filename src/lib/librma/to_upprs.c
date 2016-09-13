
#define _FILE "alib/to_upprs.as"
#include "_rma.h"

void asm to_upprs(char* s)
{
    asm {
        ldx     2,s
        bsr     TO_UPPRS
        ldd     2,s
    }
}

