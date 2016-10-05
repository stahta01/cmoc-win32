
#include "_conio.h"

void gotoxy(int x, int y)
{
    if (_hrwidth) {
        coco3_gotoxy(x, y);
    } else {
        gotox(x);
        gotoy(y);
    }
}

