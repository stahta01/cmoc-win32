
#include "_basic.h"

void INPUT(int f, char* s)
{
    if (f) {
        struct FileDesc* filedesc = (struct FileDesc*)_filedesc[f];
        if (filedesc > FOPEN_MAX) {
            char buf[100];
            word offset[2];

            offset[0] = filedesc->offset[0];
            offset[1] = filedesc->offset[1];

            char* pos = buf;
            for (;;) {
                word len = read(filedesc, pos, 16);
                pos[len] = 0;
                char* eol = strchr(pos, '\n');
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
            _seek(filedesc, offset);
            strcpy(s, buf);
        }
    } else {
        cgets(s);
    }
}

