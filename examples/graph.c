
#pragma target coco

#include <basic.h>
#include <conio.h>

void DrawBar(int month, int percent)
{
    byte x = (byte)(month * 4 + 8);
    byte y = (byte)(percent * 18 / 100);
    SETBOX(x, (21 - y) & 0xFE, x + 2, 21, (byte)(month >> 1) + 3, true);
}

int monthlysales[] = {20, 10, 35, 30, 40, 35, 45, 50, 40, 52, 90, 80};

int main(void)
{
    CLS(1);

    SETLINE(2, 4, 2, 24, COLOR_BLACK);
    SETLINE(1, 24, 61, 24, COLOR_BLACK);
    SETLINE(1, 15, 61, 15, COLOR_BLACK);

    for (int i = 0; i < 12; i++) {
        DrawBar(i, monthlysales[i]);
    }

    gotoxy(4, 11);
    cputs("J F M A M J J A S O N D");

    cputsxy(10, 0, "COCO SALES 82");
    cputsxy(10, 1, "-------------");
    cputsxy(7, 13, "SALES PREDICT COCO");
    cputsxy(4, 14, "WORLD DOMINATION BY 1984");

    return 0;
}





