
#define strlen __obsolete

#include "_string.h"

size_t strlen(char* string)
{
    size_t slen = 0;
    while (*string) {
        slen++;
        string++;
    }
    return (slen);
}

