
#include "_system.h"

void system_chrout(char c)
{
    asm {
        lda     c
        jsr     [$a002]
    }
}

