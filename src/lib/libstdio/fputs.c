
#include "_stdio.h"

int fputs(char* s, FILE* fp)
{
    if (fp->devnum) {
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

