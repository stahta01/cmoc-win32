
#include "_conio.h"

void gotoxy(int x, int y)
{
    if (_is_coco3_mode) {
        _h_crsloc = 0x2000 + (((_h_column * y) + x) << 1);
        _h_cursx = (byte)x;
        _h_cursy = (byte)y;
    } else if (isvidram()) {
        _curpos = _VIDRAM + (y << 5) + x;
    } else if (_conio.settextposition) {
        _conio.settextposition(x, y);
    }
}

