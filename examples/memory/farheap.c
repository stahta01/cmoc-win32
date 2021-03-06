
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fmalloc.h>
#include <program.h>

#define STRING_COUNT 100

int main(void)
{
    system("WIDTH80");

    char s[100];
    far_char_t* names[STRING_COUNT];
    size_t size = 0;

    // You must create the far heaps first.
    hank_create_clear(0, 0x8000, HEAP_SIZE_MAX);

    puts("STORING STRINGS IN BANK #0 ...");

    for (int i = 0; i < STRING_COUNT; i++) {
        if (names[i] = (far_char_t*)fmalloc(300)) {
            far_sprintf(names[i], "FAR STRING #%d", i);
        }
        size += far_msize((far_void_t*)names[i]);
    }

    puts("RETRIEVING STRINGS");

    for (int i = 0; i < STRING_COUNT; i++) {
        // Note: 40/80 compatiblity issues.
        // We can printf with far strings, because the strings are copied out
        // to common memory before printing. puts doesn't work, because
        // it sends the strings to chrout, which is in ROM. ie: strings cant be in
        // a bank.
        // This is only the case for far_char_t types. libfar will handle the switching,
        // but if you are using libbank directly, you still need to copy the string
        // out before calling puts.
        // This does not apply to 32 col mode, or the libgraph modes, since they
        // dont rely on ROM routines. I will be looking into accessing 40/80 col video ram
        // directly. ie: bypass the ROM.
        printf("DATA:%Fs BANK:%u\n", names[i], names[i]->bank);
        ffree((far_void_t*)names[i]);
    }
    printf("REQUESTED: %d %u %u\n", size, malloc(10), program_end);

    puts("BACK TO BASIC");

    return 0;
}


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

