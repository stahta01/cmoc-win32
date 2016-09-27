
#include "_string.h"

char* _stpcpy(char* dst, char* src)
{
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return dst;
}
