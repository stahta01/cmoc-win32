
#include "_coco.h"

// slot: 0..15.
// color: 0..63.
// Returns true for success, false if args are invalid.
// See also paletteRGB().
//
byte _palette(byte slot, byte color)
{
    if (!isCoCo3) {
        return false;
    }
    if (slot > 15) {
        return false;
    }
    if (color > 63) {
        return false;
    }
    byte* palette = (byte*)0xFFB0;
    palette[slot] = color;
    return true;
}

