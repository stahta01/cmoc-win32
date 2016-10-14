
#pragma target coco

#pragma options -machine=cocous

#include <basic.h>
#include <conio.h>
#include <unistd.h>

void DrawGraphics(void)
{
    MLINE(255, 0, 0, 192, 2);
    MLINE(0, 0, 255, 192, 2);
    for (int i = 0; i < 256; i += 8) {
        MLINE(0, i, i, 190, 1);
        MLINE(i, 0, 254, i, 1);
    }
    MELLIPSE(128, 96, 70, 40, 3);
}

void DrawDemo(void)
{
    MCLIP(2, 2, 128, 96);
    DrawGraphics();
    MCLIP(128, 2, 254, 96);
    DrawGraphics();
    MCLIP(2, 96, 128, 190);
    DrawGraphics();
    MCLIP(128, 96, 254, 190);
    DrawGraphics();
}

int main(void)
{
    PMODE(4, 1);
    SCREEN(1, 1);
    PCLS(0);
    _pmode = 3;

    DrawDemo();

    while (!kbhit()) {
    }

    return 0;
}

