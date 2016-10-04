
#include "_string.h"

char* strset(char* string, int c)
{
    char* p = string;
    while (*p) {
        *p = (char)c;
        p++;
    }
    return (string);
}

