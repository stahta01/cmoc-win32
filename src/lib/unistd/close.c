
#include "_unistd.h"

int close(int fd)
{
    if (fd <= (int)_fcbact) {
        return systemf("CLOSE#%d", fd) ? EOF : 0;
    }
    if (fd > FD_MAX) {
        _close((struct FileDesc*)fd);
        free((void*)fd);                            // We are responsible for freeing fd
    }
    return 0;
}

