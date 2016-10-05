
#include <vectrex.h>

// Draw lines.
// The list of lines can live in ROM.
// You provide the list of lines as follows:
// int8_t list[n] = {
//    y1, x1,
//    y2, x2,
//    ...
//    xn, yn
// };
// Make note that these are not absolute, but relative coordinates.
void vectrex_lines(uint8_t nr_lines, int8_t* list)
{
    asm {
        jsr     DP_to_D0
        lda     :nr_lines
        deca
        ldx     :list
        jsr     Draw_VL_a
    }
}


