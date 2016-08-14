
#include <vectrex.h>

// Draw a line.
void line(int8_t y, int8_t x)
{
    asm {
        CLR     Vec_Misc_Count    // To draw only 1 line, clear
        LDA     y
        LDB     x
        JSR     Draw_Line_d
    }
}

