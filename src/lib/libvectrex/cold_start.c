
#include <vectrex.h>

// What follows here are some low level BIOS fucntions that are not really necessary to call from your
// C program, but the are here for completeness.
void asm cold_start()
{
    asm {
        JSR   _COLD_START
    }
}

