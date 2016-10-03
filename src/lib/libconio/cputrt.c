
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
        if (isgrpram() && _conio.getfontinfo) {
            struct _fontinfo* fi = (struct _fontinfo*)_conio.getfontinfo();
            if (!fi->type || fi->base & 1) {
                _curpos++;
                if ((_curpos & (_horbyt - 1)) == 0) {
                    _curpos += ((word)_horbyt << 3) - _horbyt;
                }
                if (!isgrpram()) {
                    _curpos -= (word)_horbyt << 3;
                    scrup();
                }
            }
            if (fi->type) {
                fi->base ^= 1;
            }
        }
    }
}

