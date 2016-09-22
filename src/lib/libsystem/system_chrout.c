
#include "_system.h"

asm void system_chrout(int c)
{
    asm {
        lda     3,s
        jsr     [sysptr_chrout]
    }
}

