
#include "_conio.h"

void gotoat(int pos)
{
    if (_is_coco3_mode) {
        // TODO: Should we use _h_column here?
        switch (*(byte*)_HRWIDTH) {
        case 1:
            coco3_gotoxy(pos % 40, pos / 40);
            break;
        case 2:
            coco3_gotoxy(pos % 80, pos / 80);
            break;
        }
    } else if (isvidram()) {
        _curpos = _VIDRAM + pos;
    } else if (_conio.settextpositionat) {
        _conio.settextpositionat(pos);
    }
}

