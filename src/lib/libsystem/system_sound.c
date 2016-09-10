
#include "_system.h"

void system_sound(unsigned char tone, unsigned duration)
{
    asm {
        pshs    u
        lda     tone
        sta     _SNDTON
        ldd     duration
        std     _SNDDUR
        jsr     [sysptr_sound]
        puls    u
    }
}

