
#include "_conio.h"

void cursormove(int vt52_char)
{
    switch (vt52_char) {
    case VT52_CHR_UP:
        if (isvidram()) {
            _curpos -= 32;
            if (!isvidram()) {
                _curpos += 32;
            }
        } else {
            if (_conio.movetextposition) {
                _conio.movetextposition(_GMOVEUP);
            }
        }
        break;
    case VT52_CHR_DOWN:
        if (isvidram()) {
            _curpos += 32;
            if (!isvidram()) {
                _curpos -= 32;
                scrup();
            }
        } else {
            if (_conio.movetextposition) {
                _conio.movetextposition(_GMOVEDOWN);
            }
        }
        break;
    case VT52_CHR_RIGHT:
        if (isvidram()) {
            _curpos++;
            if (!isvidram()) {
                _curpos -= 32;
                scrup();
            }
        } else {
            if (_conio.movetextposition) {
                _conio.movetextposition(_GMOVERIGHT);
            }
        }
        break;
    case VT52_CHR_LEFT:
        if (isvidram()) {
            _curpos--;
            if (!isvidram()) {
                _curpos = _VIDRAM;
            }
        }  else if (_conio.movetextposition) {
            _conio.movetextposition(_GMOVELEFT);
        }
        break;
    }
}

