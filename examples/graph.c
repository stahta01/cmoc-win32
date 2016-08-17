
#pragma target coco

#include <basic.h>
#include <conio.h>

void DrawBar(int month, int percent)
{
    byte x = (byte)(month * 4 + 8);
    byte y = (byte)(percent * 18 / 100);
    FILLRECT(x, (21 - y) & 0xFE, x + 1, 21, (byte)(month >> 1) + 2);
}

int monthlysales[] = {20, 10, 25, 30, 40, 35, 45, 50, 40, 52, 90, 80};

int main(void)
{
    int i;
    CLS(1);

    DRAWLINE(2, 4, 2, 24, COLOR_BLACK);
    DRAWLINE(1, 24, 60, 24, COLOR_BLACK);
    DRAWLINE(1, 15, 60, 15, 0);

    for (i = 0; i < 12; i++) {
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





