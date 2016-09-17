
#include <vectrex.h>

// Print a string to the screen. The string must end with 0x80
void print_str(int8_t y, int8_t x, char* string)
{
    asm {
        JSR     DP_to_D0
        LDA     :y
        LDB     :x
        PSHS    U
        LDU     :string
        JSR     Print_Str_d
        PULS    U
    }
}

