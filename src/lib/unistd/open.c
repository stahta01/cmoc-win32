
#include "_unistd.h"

// Note: Disk only.

int open(char* name, int flags, ...)
{
    int fd = 0;
    if (flags & O_RDONLY) {
        fd = calloc(sizeof(struct FileDesc), 1);
        if (!_open((struct FileDesc*)fd, name)) {
            free((void*)fd);
            fd = 0;
        }
    } else if (flags & O_WRONLY) {
        for (fd = _fcbact; fd > 0; fd--) {
            byte* fcb = (byte*)((word*)_FCBV1)[fd - 1];
            if (!fcb[_FCBTYP]) {
                break;
            }
        }
        if (fd) {
            systemf("OPEN\"O\",#%d,\"%s\"", fd, name);
        }
    }
    return fd;
}

