
#include "_stdio.h"

int fputs(char* s, FILE* fp)
{
    if (fp->dev) {
        while (*s) {
            if (fputc(*s++, fp) == EOF) {
                return EOF;
            }
        }
    } else {
        cputs(s);
    }
    return 0;
}

