
#include "_stdio.h"

int fputc(int c, FILE* fp)
{
    if (fp->dev) {
        system_fputc(c, fp->dev);
    } else {
        cputc(c);
    }
    return 0;
}

