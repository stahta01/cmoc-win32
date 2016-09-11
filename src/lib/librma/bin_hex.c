
#define BIN2HEX _BIN2HEX
#define _FILE "alib/bin_hex.as"
#include "_alib.h"

unsigned asm bin_hex(int n, char* s)
{
    asm {
        ldd     2,s
        ldx     4,s
        bsr     BIN_HEX
        ldd     4,s
    }
}

