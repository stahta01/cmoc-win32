
#define memset __obsolete

#include "_string.h"

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

