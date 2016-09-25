
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <far.h>

#define STRING_COUNT 100

int main(void)
{
    char s[100];
    // Setup three 512 byte banks.
    far_bank(0, 512);
    far_bank(12, 512);
    far_bank(13, 512);

    far_char_t names[STRING_COUNT];
    size_t size = 0;
    for (int i = 0; i < STRING_COUNT; i++) {
        sprintf(s, "FAR STRING #%d", i);
        size += strlen(s) + 1;
        far_strnew(&names[i], s);
    }
    for (int i = 0; i < STRING_COUNT; i++) {
        printf("DATA:%s BANK:%u\n", far_zoom((far_void_t*)&names[i]), names[i].bank);
        far_zoom((far_void_t*)&names[i]);
        far_free((far_void_t*)&names[i]);
    }
    printf("MEMORY REQUESTED: %d\n", size);
    return 0;
}

