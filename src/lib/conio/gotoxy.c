
#include "_conio.h"

void gotoxy(int x, int y)
{
    if (_is_coco3_mode) {
        coco3_gotoxy(x, y);
    } else {
        gotox(x);
        gotoy(y);
    }
}

