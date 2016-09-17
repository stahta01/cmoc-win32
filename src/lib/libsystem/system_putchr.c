
#include "_system.h"

void system_putchr(char chr, char devnum)
{
    char dn = _devnum;
    _devnum = devnum;
    asm {
        lda     chr
        jsr     [sysptr_putchr]
    }
    _devnum = dn;
}

