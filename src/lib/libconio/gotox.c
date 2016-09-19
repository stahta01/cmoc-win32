
#include "_conio.h"

void gotox(int x)
{
    if (isvidram()) {
        _curpos = (_curpos & -32) | x;
    } else {
        _settextpositionx(x);
    }
}

