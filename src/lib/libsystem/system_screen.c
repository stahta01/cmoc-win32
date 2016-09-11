
#include "_system.h"

void asm system_screen(int mode)
{
    asm {
        lda     3,s
        jsr     [sysptr_screen]
    }
}

