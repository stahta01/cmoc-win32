
#include <vectrex.h>

// Draw patterned lines, where the pattern is provided as the first parameter, for the rest
// this function behaves the same as the lines fucntion.
void vectrex_pattern_lines(uint8_t pattern, uint8_t nr_lines, int8_t* list)
{
    asm {
        jsr     DP_to_D0
        lda     :pattern
        sta     Vec_Pattern
        lda     :nr_lines
        deca
        ldx     :list
        jsr     Draw_Pat_VL_a
    }
}

