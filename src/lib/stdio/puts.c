
#include "_stdio.h"

int puts(char* str)
{
    if (fputs(str, stdout) == EOF) {
        return EOF;
    }
    if (fputc('\n', stdout) == EOF) {
        return EOF;
    }
    return 0;
}

