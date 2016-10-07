
#include "_conio.h"

conio_t _conio = {
    true, false, 0,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
};

void coco3_gotoxy(int x, int y)
{
    _h_cursx = (byte)x;
    _h_cursy = (byte)y;
    _h_crsloc = (((_h_column * y) + x) << 1) + 0x2000;
}

