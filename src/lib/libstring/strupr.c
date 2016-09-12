
#define strupr __obsolete

#include "_string.h"

char* strupr(char* string)
{
    char* p = string;
    while (*p) {
        *p = (char)toupper(*p);
        p++;
    }
    return (string);
}

