
#include "_stdio.h"

int fgetc(FILE* fp)
{
    if (fp->dev) {
        if (fp->buffer == EOF) {
            return EOF;
        }
        int c = fp->buffer;
        fp->buffer = system_getchr(fp->dev);
        if (_cinbfl) {
            fp->buffer = EOF;
        }
        return c;
    } else {
        return cgetc();
    }
}

