
#include "_system.h"

asm void system_fputc(int chr)
{
    asm {
        lda     3,s
        jsr     [handle_fputc]
    }
}

