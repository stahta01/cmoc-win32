
#include "_coco.h"

// Bits 0-2: background color (0-7)
// Bits 3-5: foreground color (0-7)
// Bits 6: underline if set.
// Bits 7: blink if set.
//
byte _attr(byte foreColor, byte backColor, byte blink, byte underline)
{
    if (!isCoCo3) {
        return false;
    }

    asm {
        ldb     foreColor
        lslb
        lslb
        lslb
        orb     backColor
        tst     blink
        beq     attr_no_b
        orb     #$80
        attr_no_b:
        tst     underline
        beq     attr_no_u
        orb     #$40
        attr_no_u:
        stb     $FE08
    }

    return true;
}

