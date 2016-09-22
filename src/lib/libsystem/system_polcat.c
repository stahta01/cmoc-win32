
#include "_system.h"

asm int system_polcat(void)
{
    asm {
        jsr     [sysptr_polcat]
        tfr     a,b
        clra
    }
}

