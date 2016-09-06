
#include "_stdio.h"

int fputc(int c, FILE* fp)
{
    if (fp->devnum) {
        char a = (char)c, dn = _devnum;
        _devnum = fp->devnum;
        asm {
            lda     a
            jsr     _PUTCHR
        }
        _devnum = dn;
    } else {
        cputc((char)c);
    }
    return 0;
}

