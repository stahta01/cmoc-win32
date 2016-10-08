
#include <stdlib.h>
#include <conio.h>
#include <bob.h>

char* image =
    "                              "
    "   XXX   XX   XX  XXX   XXX   "
    "  X   X  X X X X X   X X   X  "
    "  X      X  X  X X   X X      "
    "  X   X  X     X X   X X   X  "
    "   XXX   X     X  XXX   XXX   "
    "                              ";

bob_t* screen;
bob_t* test;

int main(void)
{
    int i, y;

    for (char* p = image; *p; p++) {
        *p = (char)(*p == ' ' ? 128 : (128 + (((p - image) / 30) << 4) | 8));
    }

    screen = bob_create_with(32, 16, 0x400, 32, false);
    test = bob_create_with(30, 7, (byte*)image, 30, false);

    clrscr();

    y = 16;

    for (;;) {
        for (i = 0; i < 25; i++) {
            bob_stretch(screen, 16 - i, y, 16 + i, y + 10, test);
        }
        for (i = 25; i > 0; i--) {
            bob_stretch(screen, 16 - i, y, 16 + i, y + 10, test);
        }
        y -= 1;
        if (y < -10) {
            y = 16;
        }
    }
    return 0;
}

