
#include "_conio.h"

void screensize(int* x, int* y)
{
    if (_hrwidth) {
        coco3_screen(x, y);
    } else if (isvidram()) {
        *x = 32;
        *y = 16;
    } else {
        _textscreensize(y, x);
    }
}

