
#include "_system.h"

int system_getchr(char devnum)
{
    byte c, dn = _devnum;
    _devnum = devnum;
    asm {
        jsr     [sysptr_getchr]
        sta     c
    }
    _devnum = dn;
    return c;
}

