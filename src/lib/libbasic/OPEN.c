
#include "_basic.h"

int OPEN(char mode, int f, char* fn, size_t len)
{
    if (mode == 'I' && f > 0) {
        char s[32];
        return open(&_filedesc[f], strcat(strcpy(s, fn), ".DAT"));
    } else {
        return systemf(len ? "OPEN \"%c\",#%d,\"%s\",%u" : "OPEN \"%c\",#%d,\"%s\"", toupper(mode), f, fn,
                       len);
    }
}

