
#include "_stdio.h"

int fputs(char* str, FILE* fp)
{
    size_t count = strlen(str);
    return fwrite(str, sizeof(char), count, fp) == count ? true : EOF;
}

