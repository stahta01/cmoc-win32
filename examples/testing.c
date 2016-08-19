
// This file is uses for testing of new functions. It may
// not contain useful code.

#pragma org $3600

#include <basic.h>
#include <unistd.h>

void DrawGraphics(void)
{
    LINE(255, 0, 0, 192, 2);
    LINE(0, 0, 255, 192, 2);
    for (int i = 0; i < 256; i += 8) {
        LINE(0, i, i, 190, 1);
        LINE(i, 0, 254, i, 1);
    }
    ELLIPSE(128, 96, 70, 40, 3);
}

int main(void)
{
    sleep(1);

    PMODE(4, 1);
    PCLS(0);
    SCREEN(1, 1);

    _pmode = 3;

    CLIP(2, 2, 128, 96);
    DrawGraphics();
    CLIP(128, 2, 254, 96);
    DrawGraphics();
    CLIP(2, 96, 128, 190);
    DrawGraphics();
    CLIP(128, 96, 254, 190);
    DrawGraphics();

    while (!kbhit()) {
    }

    return 0;
}




















































































