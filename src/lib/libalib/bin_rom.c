
#define _FILE "alib/bin_rom.as"
#include "_alib.h"

unsigned asm bin_rom(int n, char* s)
{
    asm {
        ldd     2,s
        ldx     4,s
        lbsr    BIN_ROM
        ldd     4,s
    }
}

