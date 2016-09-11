
#define _FILE "alib/bin_rom.as"
#include "_alib.h"

void asm bin_rom(int n, char* s)
{
    asm {
        ldd     2,s
        ldx     4,s
        lbra    BIN_ROM
    }
}

