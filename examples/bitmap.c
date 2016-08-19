
#pragma target coco

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include <basic.h>
#include <zeropage.h>

#include <windef.h>

char* image =
    "                              "
    "   XXX   XX   XX  XXX   XXX   "
    "  X   X  X X X X X   X X   X  "
    "  X      X  X  X X   X X      "
    "  X   X  X     X X   X X   X  "
    "   XXX   X     X  XXX   XXX   "
    "                              ";

BITMAP* screen;
BITMAP* test;

int main(void)
{
    int i, y;

    for (char* p = image; *p; p++) {
        *p = (char)(*p == _SPACE ? 128 : (128 + (((p - image) / 30) << 4) | 8));
    }

    screen = BITMAPATTACH(32, 16, 0x400, 32, false);
    test = BITMAPATTACH(30, 7, (byte*)image, 30, false);

    CLS(0);

    y = 16;

    for (;;) {
        for (i = 0; i < 25; i++) {
            BITMAPSTRETCH(screen, 16 - i, y, 16 + i, y + 10, test);
        }
        for (i = 25; i > 0; i--) {
            BITMAPSTRETCH(screen, 16 - i, y, 16 + i, y + 10, test);
        }
        y -= 1;
        if (y < -10) {
            y = 16;
        }
    }
    return 0;
}






























