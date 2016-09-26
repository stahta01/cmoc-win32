
#include <vectrex.h>

// Draw a list of dots to the screen. Each dot is positioned relative to the previous one.
void vectrex_dots(uint8_t nr_dots, int8_t* list)
{
    asm {
        jsr     DP_to_D0
        lda     nr_dots
        sta     $C823
        ldx     list
        jsr     Dot_List
    }
}

