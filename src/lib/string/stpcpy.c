
#include "_string.h"

char* _stpcpy(char* dst, char* src)
{
    for (; *src; *dst++ = *src++);
    *dst = 0;
    return dst;
}
