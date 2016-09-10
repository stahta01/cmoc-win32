
#include "_system.h"

void asm system_line(void)
{
    asm {
        pshs    u
        jsr     [sysptr_line]
        puls    u
    }
}

