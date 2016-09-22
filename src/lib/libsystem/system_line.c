
#include "_system.h"

asm void system_line(void)
{
    asm {
        pshs    u
        jsr     [sysptr_line]
        puls    u
    }
}

