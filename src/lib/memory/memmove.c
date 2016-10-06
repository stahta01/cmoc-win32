
#include "_memory.h"

asm void* memmove(void* dst, void* src, size_t size)
{
    asm {
        ldd     2,s
        cmpd    4,s
        lblo    _memcpy
        lbhi    _memrcpy
    }
}

