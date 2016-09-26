
#include <vectrex.h>

// What follows here are some low level BIOS fucntions that are not really necessary to call from your
// C program, but the are here for completeness.

asm void vectrex_cold_start()
{
    asm {
        jsr   _COLD_START
    }
}

