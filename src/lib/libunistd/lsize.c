
#include <unistd.h>
#include <stdio.h>
#include <disk.h>

size_t lsize(int fd)
{
    if (fd > FOPEN_MAX) {
        return ((struct FileDesc*)fd)->length[1];
    }
    return 0;
}

