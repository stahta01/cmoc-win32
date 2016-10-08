
#pragma target coco

#include <basic.h>

int main()
{
    CLS(0);
    LLINE_B(0, 0, 64, 32, 2);
    LLINE_BF(2, 2, 62, 30, 7);
    LELLIPSE(32, 16, 25, 13, 0);
    LELLIPSE(32, 16, 22, 10, 0);
    LLINE_BF(14, 12, 50, 20, 1);
    LLINE_B(14, 12, 50, 20, 0);

    gotoxy(8, 7);
    cputs("COLOUR COMPUTER");
    gotoxy(9, 8);
    cputs("SEMI-GRAPHICS");

    return 0;
}

