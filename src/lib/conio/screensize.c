
#include "_conio.h"

void screensize(int* x, int* y)
{
    if (_is_coco3_mode) {
        *x = _h_column;
        *y = _h_row;
    } else if (isvidram()) {
        *x = 32;
        *y = 16;
    } else {
        _textscreensize(x, y);
    }
}

