
#include "_conio.h"

void gotoat(int at)
{
    if (_is_coco3_mode) {
        coco3_gotoat(at);
    } else if (isvidram()) {
        _curpos = _VIDRAM + at;
    } else if (_conio.settextpositionat) {
        _conio.settextpositionat(at);
    }
}

