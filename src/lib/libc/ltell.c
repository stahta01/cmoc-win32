
#include <unistd.h>
#include <stdio.h>
#include <disk.h>

int ltell(int fd)
{
    if (fd > FOPEN_MAX) {
        return ((struct FileDesc*)fd)->offset[1];
    }
    return -1;
}

