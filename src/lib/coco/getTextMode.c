
#include "_coco.h"

// Returns 32, 40 or 80.
//
byte _getTextMode(void)
{
    if (isCoCo3) {
        byte hrWidth = *(byte*)0x00E7;
        if (hrWidth == 1) {
            return 40;
        }
        if (hrWidth == 2) {
            return 80;
        }
    }
    return 32;
}

