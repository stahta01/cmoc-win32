
#include <unistd.h>
#include <fcntl.h>
#include <disk.h>

int read(int fd, void* buf, unsigned count)
{
    if (fd > FD_MAX) {
        return _read((struct FileDesc*)fd, (char*)buf, count);
    } else {
        // DISK BASIC reading is not implemented yet.
        return 0;
    }
}

