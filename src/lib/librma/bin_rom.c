
#define _FILE "alib/bin_rom.as"
#include "_rma.h"

asm char* bin_rom(int n, char* str)
{
    asm {
        ldd     2,s
        ldx     4,s
        lbsr    BIN_ROM
        ldd     4,s
    }
}

