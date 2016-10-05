
#include "_coco3.h"

void coco3_gotoat(int at)
{
    switch (*(byte*)_HRWIDTH) {
    case 1:
        coco3_gotoxy(at % 40, at / 40);
        break;
    case 2:
        coco3_gotoxy(at % 80, at / 80);
        break;
    }
}

