
#include <vectrex.h>

// Draw one dot at the relative y and x coordinate from the last beam position.
void vectrex_dot(int8_t y, int8_t x)
{
    asm {
        jsr     DP_to_D0
        lda     :y
        ldb     :x
        jsr     Dot_d
    }
}

