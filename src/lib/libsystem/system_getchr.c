
#include "_system.h"

char system_getchr(char devnum)
{
    char c, dn = _devnum;
    _devnum = devnum;
    asm {
        jsr _LA176
        sta c
    }
    _devnum = dn;
    return c;
}

