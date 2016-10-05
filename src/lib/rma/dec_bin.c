
#define u pcr

#define DECTAB _DECTAB,pcr *

#define _FILE "alib/dec_bin.as"
#include "_rma.h"

asm int dec_bin(char* str)
{
    asm {
        ldx     2,s
        bra     DEC_BIN
    }
}

