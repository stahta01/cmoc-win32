
#include "_system.h"

void system_chrout(char c)
{
    asm {
        lda     c
        jsr     [sysptr_chrout]
    }
}

