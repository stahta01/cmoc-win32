
#include "_system.h"

asm void system_joyin(void)
{
    asm {
        pshs    u
        jsr     [sysptr_joyin]
        puls    u
    }
}

