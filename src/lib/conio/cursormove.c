
#include "_conio.h"

void cursormove(int vt52_char)
{
    if (_is_coco3_mode) {
        coco3_cursormove(vt52_char);
    } else if (isvidram())  {
        switch (vt52_char) {
        case VT52_CHR_UP:
            _curpos -= 32;
            if (!isvidram()) {
                _curpos += 32;
            }
            break;
        case VT52_CHR_DOWN:
            _curpos += 32;
            if (!isvidram()) {
                _curpos -= 32;
                scrup();
            }
            break;
        case VT52_CHR_RIGHT:
            _curpos++;
            if (!isvidram()) {
                _curpos -= 32;
                scrup();
            }
            break;
        case VT52_CHR_LEFT:
            _curpos--;
            if (!isvidram()) {
                _curpos = _VIDRAM;
            }
            break;
        }
    } else if (_conio.movetextposition) {
        _conio.movetextposition(_GMOVEUP);
    }
}

