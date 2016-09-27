
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <far.h>

#define STRING_COUNT 100

#pragma options --optimize=2

int main(void)
{
    char s[100];
    // Setup three 512 byte hanks (banked heaps).
    // Note: I am choosing small sizes to make sure the code handles
    // low memory situations.
    hank_create_clear( 0, 0x8000, 512);
    hank_create_clear(12, 0x8000, 512);
    hank_create_clear(13, 0x8000, 512);

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

