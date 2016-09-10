
#include "_stdio.h"

int fputc(int c, FILE* fp)
{
    if (fp->devnum) {
        system_putchr((char)c, fp->devnum);
    } else {
        cputc((char)c);
    }
    return 0;
}

