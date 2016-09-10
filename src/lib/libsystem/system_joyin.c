
#include "_system.h"

void asm system_joyin(void)
{
    asm {
        pshs    u
        jsr     [sysptr_joyin]
        puls    u
    }
}

