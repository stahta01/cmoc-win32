
#include "_stdio.h"

int fputc(int c, FILE* fp)
{
    if (fp->dev) {
        byte prev = _devnum;
        _devnum = (byte)fp->dev;
        system_fputc(c);
        _devnum = prev;
    } else {
        cputc(c);
    }
    return 0;
}

