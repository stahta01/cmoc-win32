
#define DECTAB _DECTAB,DAT *
#define u pcr
#define _FILE "alib/bin_dec.as"
#include "_alib.h"

void asm bin_dec(int n, char* s)
{
    asm {
        ldd     2,s
        ldx     4,s
        bra     BIN_SDEC
    }
}

