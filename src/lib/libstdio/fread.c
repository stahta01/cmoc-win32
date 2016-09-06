
#include "_stdio.h"

size_t fread(void* buf, size_t size, size_t count, FILE* fp)
{
    if (size && count) {
        size_t count_in = 0;
        for (count_in = 0; count_in < count; count_in++) {
            for (size_t size_in = 0; size_in < size; size_in++) {
                int c =  fgetc(fp);
                if (c == EOF) {
                    return count_in;
                }
                *(unsigned char*)buf = (unsigned char)c;
                buf = buf + 1;
            }
        }
        return count_in;
    } else {
        return 0;
    }
}

