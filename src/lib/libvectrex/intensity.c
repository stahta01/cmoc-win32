
#include <vectrex.h>

// Set the beam intensity. The value 0x7f is often used and is rather bright.
void intensity(uint8_t i)
{
    asm {
        LDA i
        JSR Intensity_a
    }
}

