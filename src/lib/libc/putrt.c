
#include "_conio.h"

void putrt(void)
{
    if (isvidram()) {
        _curpos++;
        if (!isvidram()) {
            _curpos -= 32;
            scrup();
        }
    } else {
        if (isgrpram()) {
            if (!_conio.fontpack || _conio.fontbase & 128) {
                _curpos++;
                if ((_curpos & (_horbyt - 1)) == 0) {
                    _curpos--;
                    _curpos += _horbyt << 3;
                }
                if (!isgrpram()) {
                    _curpos -= _horbyt << 3;
                    scrup();
                }
            }
            if (_conio.fontpack) {
                _conio.fontbase += 128;
            }
        }
    }
}

