
#include "_stdio.h"

size_t fread(void* buf, size_t size, size_t count, FILE* fp)
{
    if (size && count) {
        size_t count_in = 0;
        for (count_in = 0; count_in < count; count_in++) {
            for (size_t size_in = 0; size_in < size; size_in++) {
                int chr =  fgetc(fp);
                if (chr == EOF) {
                    return count_in;
                }
                *(byte*)buf = (byte)chr;
                buf = buf + 1;
            }
        }
        return count_in;
    } else {
        return 0;
    }
}

