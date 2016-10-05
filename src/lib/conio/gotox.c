
#include "_conio.h"

void gotox(int x)
{
    if (_is_coco3_mode) {
        coco3_gotox(x);
    } else if (isvidram()) {
        _curpos = (_curpos & -32) | x;
    } else if (_conio.settextpositionx) {
        _conio.settextpositionx(x);
    }
}

