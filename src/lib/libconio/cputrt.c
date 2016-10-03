
#include "_conio.h"

void _cputrt(void)
{
    if (isvidram()) {
        _curpos++;
        if (!isvidram()) {
            _curpos -= 32;
            scrup();
        }
    } else {
        if (isgrpram()) {
            struct _fontinfo* fi = _getfontinfo();
            if (!fi->type || fi->base & 1) {
                _curpos++;
                if ((_curpos & (_horbyt - 1)) == 0) {
                    _curpos += ((unsigned)_horbyt << 3) - _horbyt;
                }
                if (!isgrpram()) {
                    _curpos -= (unsigned)_horbyt << 3;
                    scrup();
                }
            }
            if (fi->type) {
                fi->base ^= 1;
            }
        }
    }
}

