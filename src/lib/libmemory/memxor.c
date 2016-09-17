
#include "_memory.h"

void* _memxor(void* ptr, int value, size_t n)
{
    for (char* p = (char*)ptr, *e = p + n; p < e; p++) {
        *p ^= (char)value;
    }
    return ptr;
}

