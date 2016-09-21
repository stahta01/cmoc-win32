
#include <rle.h>
#include <memory.h>

// Amiga Stype RLE Memory Decoding
// https://en.wikipedia.org/wiki/ILBM#BODY:_Image_data

void rle_decode(byte* dst, byte* src, size_t len)
{
    for (byte* end = src + len; src < end; dst += len) {
        len = *src++;
        if (len > 128) {
            memset(dst, *src++, len = 257 - len);
        } else if (len < 128) {
            memcpy(dst, src, ++len);
            src += len;
        } else {
            break;
        }
    }
}

