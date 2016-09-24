
#include "_system.h"

int system_getchr(dev_t dev)
{
    byte c, dn = _devnum;
    _devnum = (byte)dev;
    asm {
        jsr     [handle_getchr]
        sta     c
    }
    _devnum = dn;
    return c;
}

