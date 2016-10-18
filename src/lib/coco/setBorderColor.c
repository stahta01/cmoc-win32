
#include "_coco.h"

// Sets the given 6-bit color code as the border color
// for the 40 and 80 column modes.
//
byte _setBorderColor(byte color)
{
    if (!isCoCo3) {
        return false;
    }

    *(byte*)0xFF9A = color;
    return true;
}

