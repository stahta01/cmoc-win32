
#include "_coco.h"

byte _resetPalette(byte isRGB)
{
    if (!isCoCo3) {
        return false;
    }

    // Fix bug in CoCo 3 BASIC's RGB and CMP commands.
    if (*(byte*)0xE649 == 15) {
        *(byte*)0xE649 = 16;
    }

    // Jump to RGB or CMP routine.
    asm("PSHS", "U,Y");                             // protect against BASIC routine
    if (isRGB) {
        asm("JSR", "$E5FA");
    } else {
        asm("JSR", "$E606");
    }
    asm("PULS", "Y,U");
    return true;                                    // success
}

