
#include "_basic.h"

void CLOSE(int fd)
{
    if (fd <= FD_SCREEN) {
        close(fd);
    } else {
        close(_filedesc[fd]);
        _filedesc[fd] = 0;
    }
}

