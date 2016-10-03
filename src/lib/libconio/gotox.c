
#include "_conio.h"

void gotox(int x)
{
    if (isvidram()) {
        _curpos = (_curpos & -32) | x;
    } else {
        if (_conio.settextpositionx) {
            _conio.settextpositionx(x);
        }
    }
}

