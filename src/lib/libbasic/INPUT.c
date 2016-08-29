
#include "_basic.h"

void INPUT(int fd, char* s)
{
    if (fd) {
        fd = _filedesc[fd];
        if (fd > FOPEN_MAX) {
            int len = lgets(fd, s, 200);
            if (len > 0 && s[len - 1] == '\r') {
                s[len - 1] = 0;
            }
        }
    } else {
        cgets(s);
    }
}

