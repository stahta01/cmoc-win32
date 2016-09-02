
#include "_conio.h"

void gotox(unsigned char x)
{
    if (isvidram()) {
        _curpos = (_curpos & -32) | x;
    } else {
        _settextpositionx(x);
    }
}

