
#include "_basic.h"

void CLOSE(int fd)
{
    close(_filedesc[fd]);
    _filedesc[fd] = 0;
}

