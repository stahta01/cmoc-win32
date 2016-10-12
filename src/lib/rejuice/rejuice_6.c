
#include "_rejuice.h"

asm void rejuice_6(void)
{
    asm {
        .rejuice    0
        leax    d,x
        ldb     ,x
        clra
    }
}

