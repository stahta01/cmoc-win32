
#include "_system.h"

asm void system_cputc(int c)
{
    asm {
        lda     3,s
        jsr     [handle_cputc]
    }
}

