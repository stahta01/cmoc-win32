
#include <string.h>

char* stpcpy(char* dst, char* src)
{
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return dst;
}
