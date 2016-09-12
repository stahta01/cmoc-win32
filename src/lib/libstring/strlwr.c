
#define strlwr __obsolete

#include "_string.h"

char* strlwr(char* string)
{
    char* p = string;
    while (*p) {
        *p = (char)tolower(*p);
        p++;
    }
    return (string);
}

