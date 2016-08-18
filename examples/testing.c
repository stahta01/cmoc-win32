
// This file is uses for testing of new functions. It may
// not contain useful code.

#pragma org $3600

#include <basic.h>
#include <motorola.h>

int main(void)
{
    SCREEN(1, 1);
    PMODE(4, 0);

    _pmode = 3;

    PCLIP(1, 1, 254, 191);

    PCLS(0);

    PLINE(255, 0, 0, 192, 3);

    PLINE(0, 0, 255, 192, 2);

    for (int i = 2; i < 190; i += 8) {
        PLINE(2, i, i, 190, 2);
    }

    PELLIPSE(128, 96, 70, 40, 1);

    while (!kbhit()) {
    }

    return 0;
}





































































