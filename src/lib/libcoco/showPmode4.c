
#include <coco.h>

// Set "PMODE 4 : SCREEN 1,colorset", where colorset is 0 (green/black)
// or 1 (white/black).
//
void showPmode4(byte colorset)
{
    byte* pia1bData = (byte*) 0xff22;
    byte b = *pia1bData & 7 | 0xf0;
    if (colorset) {
        b |= 8;
    }
    *pia1bData = b;
}

