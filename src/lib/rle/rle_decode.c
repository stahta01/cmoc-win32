
#include "_rle.h"

// Amiga Style RLE Memory Decoding
// https://en.wikipedia.org/wiki/ILBM#BODY:_Image_data

byte* rle_decode(byte* dst, byte* src, size_t dstlen)
{
    for (byte* end = dst + dstlen; dst < end; dst += dstlen) {
        dstlen = *src++;
        if (dstlen > 128) {
            memset(dst, *src++, dstlen = 257 - dstlen);
        } else if (dstlen < 128) {
            memcpy(dst, src, ++dstlen);
            src += dstlen;
        } else {
            break;
        }
    }
    return src;
}

