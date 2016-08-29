
#include <fcntl.h>
#include <disk.h>
#include <stdlib.h>

int close(int fd)
{
    if (fd <= _fcbact) {
        return systemf("CLOSE #%u", fd);
    }
    if (fd > FD_MAX) {
        return _close((struct FileDesc*)fd);
    }
    return 0;
}

