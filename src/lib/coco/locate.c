
#include "_coco.h"

byte _locate(byte column, byte row)
{
    byte hrwidth;
    if (isCoCo3) {
        hrwidth = * (byte*) 0x00E7;
    } else {
        hrwidth = 0;
    }

    if (hrwidth == 0) {                             // if 32 col mode
        if (column >= 32) {
            return false;
        }
        if (row >= 16) {
            return false;
        }
        * (word*) 0x0088 = 1024 + (((word) row) << 5) + column;
    } else {
        if (column >= 80) {
            return false;
        }
        if (row >= 24) {
            return false;
        }
        if (hrwidth == 1)                           // if 40 col mode
            if (column >= 40) {
                return false;
            }
        asm("PSHS", "U,Y");                         // protect against BASIC routine
        asm("LDA", column);
        asm("LDB", row);
        asm("JSR", "$F8F7");                        // inside the LOCATE command
        asm("PULS", "Y,U");
    }
    return true;
}

