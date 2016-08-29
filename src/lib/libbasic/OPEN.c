
#include "_basic.h"

int OPEN(char mode, int fd, char* fn, size_t len)
{
    mode = (char)toupper(mode);
    if (fd <= FD_SCREEN) {
        systemf("OPEN \"%c\",#%d,\"%s\"", mode, fd, fn);
    } else {
        if (_filedesc[fd]) {
            fd = 0;
        } else {
            switch (mode)   {
            case 'I':
                _filedesc[fd] = open(fn, O_RDONLY);
                break;
            case 'O':
                _filedesc[fd] = open(fn, O_WRONLY);
                break;
            }
            fd = _filedesc[fd];
        }
    }
    return fd;
}

