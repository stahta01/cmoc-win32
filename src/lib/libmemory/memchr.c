
#define memchr __obsolete

#include "_memory.h"

void* memchr(void* buf, int c, size_t count)
{
    char* p1 = NULL;
    char* p2;
    p2 = (char*)buf;
    while (count) {
        if ((int)(*p2) == c) {
            p1 = p2;
            break;
        }
        p2++;
        count--;
    }
    return ((void*)p1);
}

