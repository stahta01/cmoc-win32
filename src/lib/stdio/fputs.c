
#include "_stdio.h"

int fputs(char* str, FILE* fp)
{
    if (fp->dev) {
        byte olddev = _devnum;
        _devnum = (byte)fp->dev;
        while (*str) {
            system_fputc(*str++);
        }
        _devnum = olddev;
    } else {
        cputs(str);
    }
    return 0;
}

