
#include <vectrex.h>

// Set the beam intensity. The value 0x7f is often used and is rather bright.
void vectrex_intensity(uint8_t i)
{
    asm {
        lda :i
        jsr Intensity_a
    }
}

