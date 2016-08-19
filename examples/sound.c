
#pragma target coco

#include <conio.h>
#include <stdlib.h>

#define SIMPLE_EFFECT(X) for (unsigned char i = 0; i < 255; i++) beep(X, 0)

int main(void)
{
    clrscr();
    cputs("SOUND EFFECTS MACHINE\n\n");
    cputs("PRESS [0-9] FOR EFFECTS");
    for (;;) {
        switch (getch()) {
        case '0':
            SIMPLE_EFFECT(i | 170);
            break;
        case '1':
            SIMPLE_EFFECT((i >> 3) * i);
            break;
        case '2':
            SIMPLE_EFFECT(i * i << 1);
            break;
        case '3':
            SIMPLE_EFFECT(i & 223);
            break;
        case '4':
            SIMPLE_EFFECT((i << 1) & 87);
            break;
        case '5':
            SIMPLE_EFFECT(i * 87);
            break;
        case '6':
            SIMPLE_EFFECT((i << 3) ^ 170);
            break;
        case '7':
            SIMPLE_EFFECT(-i ^ 231);
            break;
        case '8':
            SIMPLE_EFFECT(i ^ 170);
            break;
        case '9':
            SIMPLE_EFFECT(i & 170);
            break;
        }
    }
    return 0;
}


















