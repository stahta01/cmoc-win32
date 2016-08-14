
#include <vectrex.h>

// Draw a list of dots to the screen. Each dot is positioned relative to the previous one.
void dots(uint8_t nr_dots, int8_t* list)
{
    asm {
        JSR     DP_to_D0
        LDA     nr_dots
        STA     $C823
        LDX     list
        JSR     Dot_List
    }
}

