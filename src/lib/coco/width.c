
#include "_coco.h"

// Returns true for success, false if arg is invalid.
//
byte width(byte columns)
{
    if (!isCoCo3) {
        return FALSE;
    }

    if (columns != 32 && columns != 40 && columns != 80) {
        return FALSE;
    }

    asm("PSHS", "U,Y");                     // protect against BASIC routine
    asm("LDB", columns);
    asm("JSR", "$F643");                    // inside the WIDTH command
    asm("PULS", "Y,U");

    textScreenWidth = columns;
    textScreenHeight = (columns == 32 ? 16 : 24);

    return TRUE;
}
