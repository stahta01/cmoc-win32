
#include "_rejuice.h"

asm void __rejuice_3(void)
{
    asm {
        .rejuice    0
        ldd     ,x
        tfr     b,a
        clrb
        std     ,x
    }
}

