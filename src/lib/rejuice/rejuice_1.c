
#include "_rejuice.h"

asm void rejuice_1(void)
{
    asm {
        .rejuice    0
        ldd         ,x
        subd        #1
        std         ,x
        addd        #1
    }
}

