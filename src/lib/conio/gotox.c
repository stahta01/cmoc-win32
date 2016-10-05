
#include "_conio.h"

void gotox(int x)
{
    if (_hrwidth) {
        coco3_gotox(x);
    } else if (isvidram()) {
        _curpos = (_curpos & -32) | x;
    } else {
        if (_conio.settextpositionx) {
            _conio.settextpositionx(x);
        }
    }
}

