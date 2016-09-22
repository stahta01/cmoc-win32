
#include "_system.h"

asm void system_sound(void)
{
    asm {
        pshs    u
        jsr     [sysptr_sound]
        puls    u
    }
}

