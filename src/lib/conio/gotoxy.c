
#include "_conio.h"

void gotoxy(int x, int y)
{
    if (_is_coco3_mode) {
        _h_cursx = (byte)x;
        _h_cursy = (byte)y;
        // A little optimization to multiply y by either 40 or 80.
        y += (y <<= 2 +_h_width) << 2;
        _h_crsloc = 0x2000 + ((x + y) << 1);
    } else if (isvidram()) {
        _curpos = _VIDRAM + (y << 5) + x;
    } else if (_conio.settextposition) {
        _conio.settextposition(x, y);
    }
}

