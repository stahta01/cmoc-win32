
#pragma options -machine=coco -ram=64

#include <sys/mman.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    int i;
    char s[256];
    for (i = 0; i < 256; i++) {
        s[i] = (char)i;
    }
    cputs("\n\nCOPY STRING TO $8000\n");
    if (!mlock(0x8000, 256)) {
        memcpy(0x8000, s, 256);
        munlock(0x8000, 256);
    }
    cputs("PRESS ANY KEY\n\n");
    getch();

    cputs("COPY $8000 TO $400\n");
    if (!mlock(0x8000, 256)) {
        memcpy(0x400, 0x8000, 256);
        munlock(0x8000, 256);
    }

    return 0;
}

