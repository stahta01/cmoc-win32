
#include "_string.h"

char* strdup(char* src)
{
    char* dst = (char*)malloc(strlen(src) + 1);
    if (dst) {
        strcpy(dst, src);
    }
    return dst;
}

