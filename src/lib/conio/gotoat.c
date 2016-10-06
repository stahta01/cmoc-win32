
#include "_conio.h"

void gotoat(int pos)
{
    if (_is_coco3_mode) {
        coco3_gotoat(pos);
    } else if (isvidram()) {
        _curpos = _VIDRAM + pos;
    } else if (_conio.settextpositionat) {
        _conio.settextpositionat(pos);
    }
}

