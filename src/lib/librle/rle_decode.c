
#include <rle.h>
#include <memory.h>

void rle_decode(byte* dst, byte* src, size_t n)
{
    for (byte len; n--; dst += len) {
        len = *src++;
        if (len > 128) {
            memset(dst, *src++, len = 1 - len);
        } else if (len < 128) {
            memcpy(dst, src, ++len);
            src += len;
        } else {
            break;
        }
    }
}

