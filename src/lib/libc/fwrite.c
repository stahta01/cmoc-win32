
#include "_libc.h"

size_t fwrite(void* buf, size_t size, size_t count, FILE* fp)
{
    if (size && count) {
        size_t count_out = 0;
        for (count_out = 0; count_out < count; count_out++) {
            for (size_t size_out = 0; size_out < size; size_out++) {
                if (fputc(*(unsigned char*)buf, fp) == EOF) {
                    return count_out;
                }
                buf = buf + 1;
            }
        }
        return count_out;
    } else {
        return 0;
    }
}

