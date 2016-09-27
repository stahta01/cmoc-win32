
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <far.h>

#define STRING_COUNT 100

#pragma options --optimize=2

#include <rle.h>

// This code is just my experiments. Dont use it.


far_void_t* far_malloc_put(far_void_t* dst, void* src, size_t size)
{
    if (dst = far_malloc(dst, size)) {
        far_memput(dst, src, size);
    }
    return dst;
}

byte* rle_encode(byte* dst, byte* src, size_t srclen)
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

void test(void)
{
    far_void_t pak;
    char* s = "01         23456789";
    char buf[256];
    far_malloc_pak(&pak, s, strlen(s) + 1);
    far_getpak(buf, &pak);
    puts(buf);
}

int main(void)
{
    // Setup three 512 byte hanks (banked heaps).
    // Note: I am choosing small sizes to make sure the code handles
    // low memory situations.
    hank_create_clear(0, 0x8000, HEAP_SIZE_MAX);
    hank_create_clear(12, 0x8000, 512);
    hank_create_clear(13, 0x8000, 512);

    test();
    return 0;
    char s[100];

    far_char_t names[STRING_COUNT];
    size_t size = 0;
    for (int i = 0; i < STRING_COUNT; i++) {
        if (far_malloc((far_void_t*)&names[i], 20)->data) {
            far_sprintf(&names[i], "FAR STRING #%d", i);
        }
        size += far_msize((far_void_t*)&names[i]);
    }
    for (int i = 0; i < STRING_COUNT; i++) {
        printf("DATA:%Fs BANK:%u\n", &names[i], names[i].bank);
        far_free((far_void_t*)&names[i]);
    }
    printf("MEMORY REQUESTED: %d\n", size);
    return 0;
}

