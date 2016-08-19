
#include <stdlib.h>
#include <equates.h>
#include <stdio.h>

void beep(unsigned char tone, unsigned duration)
{
    asm {
        pshs    u
        lda     tone
        sta     _SNDTON
        ldd     duration
        std     _SNDDUR
        JSR_SOUND
        puls    u
    }
}


