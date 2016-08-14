
#include <coco.h>

// slot: 0..15.
// color: 0..63.
// Returns true for success, false if args are invalid.
// See also paletteRGB().
//
byte palette(byte slot, byte color)
{
    if (!isCoCo3) {
        return FALSE;
    }
    if (slot > 15) {
        return FALSE;
    }
    if (color > 63) {
        return FALSE;
    }
    byte* palette = (byte*) 0xFFB0;
    palette[slot] = color;
    return TRUE;
}


