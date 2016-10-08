
// A simple "matrix" looking display.

#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define byte unsigned char

int main(void)
{
    byte i, pitch = 0;
    byte* p = (byte*)0x400;
    for (i = 0; i < 32; i++) {
        *p++ = (byte)(rand() & 15);
    }
    while (!kbhit()) {
        memmove(0x420, 0x400, 480);
        beep((pitch * pitch) << 1, 0);
        pitch += 1;
        p = (byte*)0x400;
        for (i = 0; i < 32; i++) {
            *p = *p + 1;
            p++;
        }
    }
    return 0;
}

