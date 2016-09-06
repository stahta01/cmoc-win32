
#include "_libc.h"

int fputc(int c, FILE* fp)
{
    assert(fp);
    if (fp->devnum) {
        return EOF;
    } else {
        cputc((char)c);
        return 0;
    }
}

