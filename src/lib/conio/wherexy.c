
#include "_conio.h"

void wherexy(int* x, int* y)
{
    if (_is_coco3_mode) {
        *x = _h_cursx;
        *y = _h_cursy;
    } else if (isvidram()) {
        *x = _curpos & 31;
        *y = _udiv32(_curpos) & 15;
    } else {
        _gettextposition(x, y);
    }
}

