
#pragma target coco

#include <basic.h>
#include <unistd.h>

void FillDonut(int x, int y, int w, int h, byte c)
{
    if (kbhit()) {
        puts("DONUTS ARE DONE!");
        exit(0);
    }
    beep(c << 4, 1);
    MELLIPSE(x, y, w, h, 3);
    MELLIPSE(x, y, w >> 1, h >> 1, 3);
    beep(c << 5, 1);
    PAINT(x, y + h - 2, c, 0);
    beep(c << 6, 1);
}

void FillDonuts(void)
{
    FillDonut(50, 50, 20, 20, 3);
    FillDonut(100, 100, 60, 20, 2);
    FillDonut(180, 60, 40, 50, 0);
    FillDonut(150, 140, 70, 30, 3);
}

void FillScreen(int css)
{
    PMODE(3, 1);
    PCLS(1);
    SCREEN(1, css);

    FillDonuts();

    PMODE(4, 1);
    PCLS(0);
    SCREEN(1, css);

    _pmode = 3;

    FillDonuts();
}

int main(void)
{
    for (;;) {
        FillScreen(0);
        FillScreen(1);
    }
    return 0;
}

