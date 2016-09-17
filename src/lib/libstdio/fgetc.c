
#include "_stdio.h"

int fgetc(FILE* fp)
{
    if (fp->devnum) {
        if (fp->buffer == EOF) {
            return EOF;
        }
        int c = fp->buffer;
        fp->buffer = system_getchr(fp->devnum);
        if (_cinbfl) {
            fp->buffer = EOF;
        }
        return c;
    } else {
        return cgetc();
    }
}

