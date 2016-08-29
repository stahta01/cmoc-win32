
#include <unistd.h>
#include <fcntl.h>
#include <cmoc.h>

off_t lseek(int fd, off_t offset, int whence)
{
    if (offset) {
        if (fd > FD_MAX) {
            struct FileDesc* filedesc = (struct FileDesc*)fd;
            word int32[2];
            switch (whence) {
            case SEEK_END:
                int32[0] = filedesc->length[0];
                int32[1] = filedesc->length[1];
                break;
            case SEEK_CUR:
                int32[0] = filedesc->offset[0];
                int32[1] = filedesc->offset[1];
                break;
            case SEEK_SET:
                int32[0] = 0;
                int32[1] = offset;
                break;
            }
            if (whence != SEEK_SET) {
                if (offset < 0) {
                    sub32(int32, -1, offset);
                } else {
                    adddww(int32,  offset);
                }
            }
            if (_seek(filedesc, int32)) {
                offset = 0;
            }
        } else {
            // Seeking not supported for DISK BASIC
            offset = 0;
        }
    }
    return offset;
}

