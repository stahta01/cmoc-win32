
#define _FILE "alib/hex_bin.as"
#include "_rma.h"

asm unsigned hex_bin(char* str)
{
    asm {
        ldx     2,s
        bra     HEX_BIN
    }
}

