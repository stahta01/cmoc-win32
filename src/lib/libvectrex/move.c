
#include <vectrex.h>

// Move the dot to a specific position.
void move(uint8_t y, uint8_t x)
{
    asm {
        JSR     DP_to_D0
        LDA     y
        LDB     x
        JSR     Moveto_d
    }
}

