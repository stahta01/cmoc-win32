
#include <vectrex.h>

// Print a string to the screen. The string must end with 0x80
void vectrex_print_str(int8_t y, int8_t x, char* string)
{
    asm {
        jsr     DP_to_D0
        lda     :y
        ldb     :x
        pshs    U
        ldu     :string
        jsr     Print_Str_d
        puls    U
    }
}

