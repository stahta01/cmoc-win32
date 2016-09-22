
#include "_system.h"

asm char system_polcat(void)
{
    asm {
        jsr     [sysptr_polcat]
        tfr     a,b
    }
}

