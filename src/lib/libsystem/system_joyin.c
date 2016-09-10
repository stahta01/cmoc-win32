
#include "_system.h"

void asm system_joyin(void)
{
    asm {
        pshs    u
        jsr     [$a00a]
        puls    u
    }
}

