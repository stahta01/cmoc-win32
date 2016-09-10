
#include "_system.h"

void system_putchr(char c, char devnum)
{
    char dn = _devnum;
    _devnum = devnum;
    asm {
        lda     c
        jsr     _PUTCHR
    }
    _devnum = dn;
}

