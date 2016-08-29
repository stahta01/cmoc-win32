
#include <fcntl.h>
#include <disk.h>
#include <stdlib.h>
#include <stdio.h>

int close(int fd)
{
    if (fd <= _fcbact) {
        return systemf("CLOSE #%d", fd);
    }
    if (fd > FD_MAX) {
        _close((struct FileDesc*)fd);
        free((void*)fd); // We are responsible for freeing fd
    }
    return 0;
}

