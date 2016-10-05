
#include "_conio.h"

void screensize(int* x, int* y)
{
    if (isvidram()) {
        *x = 32;
        *y = 16;
    } else {
        _textscreensize(y, x);
    }
}

