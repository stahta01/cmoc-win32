
#include "_libc.h"

int fputs(char* s, FILE* fp)
{
    assert(fp);
    if (fp->devnum) {
        return EOF;
    } else {
        cputs(s);
        return 0;
    }
}

