
#include "_rejuice.h"

asm void rejuice_2(void)
{
    asm {
        .rejuice    0
        ldd         ,x
        addd        #1
        std         ,x
        subd        #1
    }
}

