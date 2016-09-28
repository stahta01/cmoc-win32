
#define u pcr

// The symbol name DECTAB$ was causing trouble. So this
// define changes it to _DECTAB
#define DECTAB _DECTAB,pcr *

#define _FILE "alib/bin_dec.as"
#include "_rma.h"

asm char* bin_dec(int n, char* str)
{
    asm {
        ldd     2,s
        ldx     4,s
        bsr     BIN_SDEC
        ldd     4,s
    }
}

