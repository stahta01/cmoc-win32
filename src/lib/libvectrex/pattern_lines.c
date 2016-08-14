
#include <vectrex.h>

// Draw patterned lines, where the pattern is provided as the first parameter, for the rest
// this function behaves the same as the lines fucntion.
void pattern_lines(uint8_t pattern, uint8_t nr_lines, int8_t* list)
{
    asm {
        JSR     DP_to_D0
        LDA     pattern
        STA     Vec_Pattern
        LDA     nr_lines
        DECA
        LDX     list
        JSR     Draw_Pat_VL_a
    }
}

