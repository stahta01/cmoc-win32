
#include "_coco.h"

// Waits for a key to be pressed and returns its code.
//
byte _waitkey(byte blinkCursor)
{
    byte key;
    if (blinkCursor) {
        asm {
            jsr $A1B1                               // blink cursor while waiting for a keystroke
            sta key
        }
        return key;
    }

    for (;;) {
        key = _inkey();
        if (key) {
            return key;
        }
    }
}

