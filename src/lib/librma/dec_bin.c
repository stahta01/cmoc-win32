
#define u pcr

#define DECTAB _DECTAB,pcr *

#define _FILE "alib/dec_bin.as"
#include "_rma.h"

int asm dec_bin(char* s)
{
    asm {
        ldx     2,s
        bra     DEC_BIN
    }
}
