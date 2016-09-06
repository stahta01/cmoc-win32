
#include "_libc.h"

int fgetc(FILE* fp)
{
    if (fp) {
        char c, dn = _devnum;
        _devnum = (char)fp;
        asm {
            jsr _LA176
            sta c
        }
        _devnum = dn;
        return c ? c : EOF;
    } else {
        return cgetc();
    }
}

