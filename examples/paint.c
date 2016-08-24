
// This file is uses for testing of new functions. It may
// not contain useful code.

#pragma org $3600

#pragma target coco

#include <basic.h>
#include <unistd.h>


void FillDonut(int x, int y, int w, int h, byte c)
{
    ELLIPSE(x, y, w, h, 3);
    ELLIPSE(x, y, w >> 1, h >> 1, 3);
    PAINT(x, y + h - 2, c);
}

int main(void)
{
    PMODE(4, 1);
    PCLS(0);
    SCREEN(1, 1);

    _pmode = 3;

    FillDonut(50, 50, 20, 20, 1);
    FillDonut(100, 100, 60, 20, 2);
    FillDonut(180, 60, 40, 50, 1);

    while (!kbhit()) {
    }

    return 0;
}

