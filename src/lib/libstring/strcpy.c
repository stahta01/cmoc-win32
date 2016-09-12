
#define strcpy __obsolete

#include "_string.h"

char* strcpy(char* dst, char* src)
{
    char* result = dst;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return result;
}

