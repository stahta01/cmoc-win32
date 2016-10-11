
#include "_string.h"

char* strnset(char* str, int chr, size_t size)
{
    char* p = str;
    while (*p && size) {
        *p = (char)chr;
        size--;
        p++;
    }
    return str;
}

