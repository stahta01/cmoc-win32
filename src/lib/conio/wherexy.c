
#include "_conio.h"

void wherexy(int* x, int* y)
{
    if (_is_coco3_mode) {
        coco3_wherexy(x, y);
    } else if (isvidram()) {
        *x = _curpos & 31;
        *y = (_curpos >> 5) & 15;
    } else {
        _gettextposition(x, y);
    }
}

