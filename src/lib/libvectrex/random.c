
#include <vectrex.h>

// Produce a random value using the BIOS Random function.
int8_t random()
{
    int8_t rnd;
    asm {
        JSR Random
        STA rnd
    }
    return rnd;
}

