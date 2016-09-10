
#include "_system.h"

void system_putchr(char c, char devnum)
{
    char dn = _devnum;
    _devnum = devnum;
    asm {
        lda     c
        jsr     [sysptr_putchr]
    }
    _devnum = dn;
}

