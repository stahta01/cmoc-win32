
#pragma options -machine=coco

#include <far.h>
#include <heman.h>
#include <stdio.h>
#include <bank.h>
#include <string.h>

#define type_cast(A) *(A*)&

far_void_t nullptr16 = {16, 0};
#define nullstr16 (type_cast(far_char_t)nullptr16)

#define STRING_COUNT 100

int main(void)
{
    char s[100];
    far_init(16);

    far_char_t names[STRING_COUNT];

    for (int i = 0; i < STRING_COUNT; i++) {
        names[i] = nullstr16;
        sprintf(s, "FAR STRING #%d", i);
        far_strdup(&names[i], s);
    }
    for (int i = 0; i < STRING_COUNT; i++) {
        far_strget(s, &names[i]);
        puts(s);
        far_free((far_void_t*)&names[i]);
    }
    return 0;
}

