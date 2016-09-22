
#include "_rle.h"

byte* rle_encode(byte* dst, byte* src, size_t srclen)
{
    for (byte* end = src + srclen, *pos = src; pos < end; pos = src) {
        for (; (src[0] != src[1]) && (src - pos) < 128 && src < end; src++);
        if (src > pos) {
            // TODO: Should this be replaced with a memcpy?
            for (*dst++ = (byte)((src - pos) - 1); pos < src; *dst++ = *pos++);
        }
        for (; *src == *pos && (src - pos) < 128 && src < end; src++);
        *dst++ = (byte)(257 - (src - pos));
        *dst++ = *pos;
    }
    return dst;
}

