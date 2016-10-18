
#include "_coco.h"

byte _hscreen(byte mode)
{
    if (!isCoCo3) {
        return false;
    }

    if (mode > 4) {
        return false;
    }
    asm("PSHS", "U,Y");                             // protect against BASIC routine
    asm("LDB", mode);
    asm("JSR", "$E69C");
    asm("PULS", "Y,U");
    return true;
}

