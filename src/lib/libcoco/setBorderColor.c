
#include "_coco.h"

// Sets the given 6-bit color code as the border color
// for the 40 and 80 column modes.
//
byte setBorderColor(byte color)
{
    if (!isCoCo3) {
        return FALSE;
    }

    * (byte*) 0xFF9A = color;
    return TRUE;
}

