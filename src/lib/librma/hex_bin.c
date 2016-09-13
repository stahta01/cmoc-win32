
#define _FILE "alib/hex_bin.as"
#include "_rma.h"

unsigned asm hex_bin(char* s)
{
    asm {
        ldx     2,s
        bra     HEX_BIN
    }
}

