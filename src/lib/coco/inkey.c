
#include "_coco.h"

// Returns 0 if no key is currently pressed.
//
asm byte _inkey(void)
{
    asm {
        jsr     [$a000]
        tfr     a,b                                 // byte return value goes in B
    }
}

