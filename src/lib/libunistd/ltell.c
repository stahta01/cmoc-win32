
#include <unistd.h>
#include <stdio.h>
#include <disk.h>

size_t ltell(int fd)
{
    if (fd > FOPEN_MAX) {
        return ((struct FileDesc*)fd)->offset[1];
    }
    return EOF;
}

