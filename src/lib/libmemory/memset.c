
#define memset __obsolete

#include "_memory.h"

void* memset(void* dest, int c, size_t count)
{
    char* p = (char*)dest;
    while (count) {
        *p = (char)c;
        p++;
        count--;
    }
    return (dest);
}

