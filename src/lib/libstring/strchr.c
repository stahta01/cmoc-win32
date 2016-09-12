
#define strchr __obsolete

#include "_string.h"

char* strchr(char* s, int c)
{
    do {
        if (*s == c) {
            return s;
        }
    } while (*s++);
    return NULL;
}
