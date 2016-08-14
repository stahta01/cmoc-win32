
#include <vectrex.h>

// Draw one dot at the relative y and x coordinate from the last beam position.
void dot(int8_t y, int8_t x)
{
    asm {
        JSR     DP_to_D0
        LDA     y
        LDB     x
        JSR     Dot_d
    }
}

