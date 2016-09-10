
#include "_system.h"

char asm system_polcat(void)
{
    asm {
        jsr     [$a000]
        tfr     a,b
    }
}

