
#include "_rejuice.h"

asm void rejuice_4(void)
{
    asm {
        .rejuice    0
        pshs    u
        pshs    u
        ldu     4,s
        stu     2,s
        puls    u
        stu     2,s
        leau    2,s
    }
}

