
#include "_system.h"

void asm system_sound(void)
{
    asm {
        pshs    u
        jsr     [sysptr_sound]
        puls    u
    }
}

