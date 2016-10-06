
#include "_system.h"

int system_fgetc(dev_t dev)
{
    byte chr, devold = _devnum;
    _devnum = (byte)dev;
    asm {
        jsr     [handle_fgetc]
        sta     chr
    }
    _devnum = devold;
    return chr;
}

