
#include "_stdio.h"

size_t fwrite(void* buf, size_t size, size_t count, FILE* fp)
{
    if (size && count) {
        if (fp->dev) {
            byte olddev = _devnum;
            _devnum = (byte)fp->dev;
            for (size_t i = 0; i < count; i++) {
                for (size_t j = size; j--;) {
                    // todo: how do we check for an error here?
                    system_fputc(*(byte*)buf);
                    buf = buf + 1;
                }
            }
            _devnum = olddev;
        } else {
            cwrite((char*)buf, size * count);
        }
    }
    return count;
}

