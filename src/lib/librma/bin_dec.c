
#define u pcr

#define DECTAB _DECTAB,DAT *

#define _FILE "alib/bin_dec.as"
#include "_rma.h"

unsigned asm bin_dec(int n, char* str)
{
    asm {
        ldd     2,s
        ldx     4,s
        bsr     BIN_SDEC
        ldd     4,s
    }
}

