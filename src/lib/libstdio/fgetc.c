
#include "_stdio.h"

int fgetc(FILE* fp)
{
    if (fp->devnum) {
        if (fp->cinbfl) {
            return EOF;
        } else {
            char c, dn = _devnum;
            _devnum = fp->devnum;
            asm {
                jsr _LA176
                sta c
            }
            _devnum = dn;
            fp->cinbfl = _cinbfl;
            if (fp->cinbfl) {
                return EOF;
            }
            return c;
        }
    } else {
        return cgetc();
    }
}

