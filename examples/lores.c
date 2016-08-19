
#pragma target coco

#include <basic.h>

int main()
{
    CLS(0);

    SETBOX(0, 0, 64, 32, 2, false);
    SETBOX(2, 2, 62, 30, 7, true);
    SETELLIPSE(32, 16, 25, 13, 0, false);
    SETELLIPSE(32, 16, 22, 10, 0, false);
    SETBOX(14, 12, 50, 20, 1, true);
    SETBOX(14, 12, 50, 20, 0, false);

    gotoxy(8, 7);
    cputs("COLOUR COMPUTER");
    gotoxy(9, 8);
    cputs("SEMI-GRAPHICS");

    return 0;
}



