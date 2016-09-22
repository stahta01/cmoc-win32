
#include "_system.h"

asm void system_screen(int mode)
{
    asm {
        lda     3,s
        jsr     [sysptr_screen]
    }
}

