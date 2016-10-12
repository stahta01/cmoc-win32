
#include "_rejuice.h"

asm void rejuice_5(void)
{
    asm {
        .rejuice    0
        leas    ,u
        puls    u,pc
    }
}

