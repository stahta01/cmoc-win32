
#include "_system.h"

int system_fgetc(dev_t dev)
{
    byte c, dn = _devnum;
    _devnum = (byte)dev;
    asm {
        jsr     [handle_fgetc]
        sta     c
    }
    _devnum = dn;
    return c;
}

