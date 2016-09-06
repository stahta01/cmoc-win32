
#include "_stdio.h"

int fgetc(FILE* fp)
{
    if (fp->devnum) {
        if (fp->buffer == EOF) {
            return EOF;
        }
        int c = fp->buffer;
        char a, dn = _devnum;
        _devnum = fp->devnum;
        asm {
            jsr _LA176
            sta a
        }
        _devnum = dn;
        if (_cinbfl) {
            fp->buffer = EOF;
            return EOF;
        }
        fp->buffer = a;
        return c;
    } else {
        return cgetc();
    }
}

