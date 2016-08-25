
#include <conio.h>

// A simple "matrix" looking display.

int main(void)
{
    byte i, pitch = 0;
    byte* p = (byte*)0x400;
    for (i = 0; i < 32; i++) {
        *p++ = (byte)(rand() & 31);
    }
    while (!kbhit()) {
        memmove(0x420, 0x400, 480);
        beep(pitch--, 0);
        p = (byte*)0x400;
        for (i = 0; i < 32; i++) {
            *p = *p + 1;
            p++;
        }
    }
    return 0;
}

