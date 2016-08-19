
// This file is uses for testing of new functions. It may
// not contain useful code.

#pragma org $3600

#include <basic.h>
#include <unistd.h>

int main(void)
{
    sleep(1);

    PMODE(4, 1);
    SCREEN(1, 1);

    _pmode = 3;

    PCLS(0);

    LINE(255, 0, 0, 192, 3);

    LINE(0, 0, 255, 192, 2);

    for (int i = 2; i < 190; i += 8) {
        LINE(2, i, i, 190, 2);
    }

    ELLIPSE(128, 96, 70, 40, 1);

    while (!kbhit()) {
    }

    return 0;
}















































































