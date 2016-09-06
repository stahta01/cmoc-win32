
#include "_libc.h"

int fgetc(FILE* fp)
{
    assert(fp);
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
            return c;
        }
    } else {
        return cgetc();
    }
}

