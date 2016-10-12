
#include "_rejuice.h"

asm void rejuice_7(void)
{
    asm {
        .rejuice    0
        leax    d,x
        ldb     ,x
        sex
    }
}

