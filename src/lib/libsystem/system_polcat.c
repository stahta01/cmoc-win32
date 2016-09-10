
#include "_system.h"

char asm system_polcat(void)
{
    asm {
        jsr     [sysptr_polcat]
        tfr     a,b
    }
}

