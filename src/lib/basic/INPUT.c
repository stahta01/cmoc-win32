
#include "_basic.h"

size_t INPUT(int fd, char* s)
{
    size_t size = 0;
    if (fd) {
        fd = _filedesc[fd];
        if (fd > FOPEN_MAX) {
            size = lgets(fd, s, 200);
            if (size > 0 && s[size - 1] == '\r') {
                s[size - 1] = 0;
            }
        }
    } else {
        // Does not support cas input. Yet.
        char buf[MAX_INPUT];
        buf[0] = MAX_INPUT - 1;
        size = strlen(strcpy(s, cgets(buf)));
    }
    return size;
}

