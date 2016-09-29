
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <far.h>
#include <program.h>

#define STRING_COUNT 100

#include <rle.h>

// This code is just my experiments. Dont use it.

byte* rle_encode2(byte* dst, byte* src, size_t srclen)
{
    for (byte* end = src + srclen, *pos = src; pos < end; pos = src) {
        for (src++; (src < end) && (*src != src[-1]) && (src - pos) < 128; src++);
        if ((src - pos) > 1) {
            for (*dst++ = (byte)(src - pos - 1); pos < src; *dst++ = *pos++);
        }
        for (; src < end && *src == *pos && (src - pos) < 128; src++);
        *dst++ = (byte)(257 - (src - pos));
        *dst++ = *pos;
    }
    return dst;
}

far_void_t* far_malloc_pak(far_void_t* dst, void* src, size_t size)
{
    word* buf = (word*)malloc(size * 2);
    if (buf) {
        byte* end = rle_encode((byte*)&buf[1], (byte*)src, *buf = size);
        far_malloc_put(dst, buf, end - (byte*)buf);
        free(buf);
    }
    return dst;
}

void far_getpak(void* dst, far_void_t* src)
{
    word* mem = (word*)far_zoom(src);
    rle_decode((byte*)dst, (byte*)&mem[1], *mem);
    far_zoom(src);
}


int main(void)
{
    char s[100];
    far_char_t* names[STRING_COUNT];
    size_t size = 0;

    // You must create the far heaps first.
    hank_create_clear(0, 0x8000, HEAP_SIZE_MAX);

    for (int i = 0; i < STRING_COUNT; i++) {
        if (names[i] = _falloc(300)) {
            far_sprintf(names[i], "FAR STRING #%d", i);
        }
        size += far_msize((far_void_t*)names[i]);
    }
    for (int i = 0; i < STRING_COUNT; i++) {
        printf("DATA:%Fs BANK:%u\n", names[i], names[i]->bank);
        _ffree((far_void_t*)names[i]);
    }
    printf("REQUESTED: %d %u %u\n", size, malloc(10), program_end);
    return 0;
}

