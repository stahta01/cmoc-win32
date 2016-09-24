
#include "_system.h"

asm int system_polcat(void)
{
    asm {
        jsr     [handle_polcat]
        tfr     a,b
        clra
    }
}

