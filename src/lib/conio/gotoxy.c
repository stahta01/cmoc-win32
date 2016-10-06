
#include "_conio.h"

void gotoxy(int x, int y)
{
    if (_is_coco3_mode) {
        coco3_gotoxy(x, y);
    } else if (isvidram()) {
        _curpos = _VIDRAM + (y << 5) + x;
    } else if (_conio.settextposition) {
        _conio.settextposition(x, y);
    }
}

