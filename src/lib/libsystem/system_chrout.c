
#include "_system.h"

asm void system_chrout(int c)
{
    asm {
        lda     3,s
        jsr     [handle_chrout]
    }
}

