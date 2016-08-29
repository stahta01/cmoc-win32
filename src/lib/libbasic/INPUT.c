
#include "_basic.h"

void INPUT(int f, char* s)
{
    if (f < 1) {
        cgets(s);
    } else {
        char buf[100];
        word offset[2];

        offset[0] = _filedesc[f].offset[0];
        offset[1] = _filedesc[f].offset[1];

        char* pos = buf;
        for (;;) {
            word len = read(&_filedesc[f], pos, 16);
            pos[len] = 0;
            char* eol = strchr(pos, 13);
            if (eol) {
                *eol = 0;
                break;
            }
            if (len < 16) {
                break;
            }
            pos += len;
        }
        adddww(offset, strlen(buf) + 1);
        seek(&_filedesc[f], offset);
        strcpy(s, buf);
    }
}

