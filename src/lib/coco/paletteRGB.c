
#include "_coco.h"

// Easier interface when assuming an RGB monitor.
// slot: 0..15.
// red, green, blue: 0..3.
//
void _paletteRGB(byte slot, byte red, byte green, byte blue)
{
    if (!isCoCo3) {
        return;
    }
    if (slot > 15) {
        return;
    }
    * (((byte*)0xFFB0) + slot) = ((red   & 2) << 4)
                                 | ((red   & 1) << 2)
                                 | ((green & 2) << 3)
                                 | ((green & 1) << 1)
                                 | ((blue  & 2) << 2)
                                 | (blue  & 1);
}

