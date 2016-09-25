
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <far.h>

#define STRING_COUNT 100

int main(void)
{
    char s[100];
    // Setup three 512 byte banks.
    // Note: I am choosing small sizes to make sure the code handles
    // low memory situations.
    far_bank(0, 512);
    far_bank(12, 512);
    far_bank(13, 512);

    far_char_t names[STRING_COUNT];
    size_t size = 0;
    for (int i = 0; i < STRING_COUNT; i++) {
        if (far_alloc((far_void_t*)&names[i], 20)->data) {
            far_sprintf(&names[i], "FAR STRING #%d", i);
        }
        size += far_size((far_void_t*)&names[i]);
    }
    for (int i = 0; i < STRING_COUNT; i++) {
        printf("DATA:%Fs BANK:%u\n", &names[i], names[i].bank);
        far_free((far_void_t*)&names[i]);
    }
    printf("MEMORY REQUESTED: %d\n", size);
    return 0;
}

