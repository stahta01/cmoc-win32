
#include <vectrex.h>

// Draw a line.
void vectrex_line(int8_t y, int8_t x)
{
    asm {
        clr     Vec_Misc_Count    // To draw only 1 line, clear
        lda     :y
        ldb     :x
        jsr     Draw_Line_d
    }
}

