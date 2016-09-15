
#define memccpy __obsolete

#include "_memory.h"

void* memccpy(void* dest,  void* src, int c, unsigned int count)
{
    char* p1;
    char* p2;
    p1 = (char*)src;
    p2 = (char*)dest;
    while (count) {
        *p2 = *p1;
        if (*p2 == (char)c) {
            dest = (void*)(p2 + 1);
            break;
        }
        p2++;
        p1++;
        count--;
    }
    return (dest);
}

