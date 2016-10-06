
#include "_conio.h"

void screensize(int* x, int* y)
{
    if (_is_coco3_mode) {
        coco3_screensize(x, y);
    } else if (isvidram()) {
        *x = 32;
        *y = 16;
    } else {
        _textscreensize(x, y);
    }
}

