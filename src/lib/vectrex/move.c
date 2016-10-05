
#include <vectrex.h>

// Move the dot to a specific position.
void vectrex_move(uint8_t y, uint8_t x)
{
    asm {
        jsr     DP_to_D0
        lda     :y
        ldb     :x
        jsr     Moveto_d
    }
}

