
#include "_unistd.h"

size_t ltell(int fd)
{
    if (fd > FOPEN_MAX) {
        return ((struct FileDesc*)fd)->offset[1];
    }
    return EOF;
}

