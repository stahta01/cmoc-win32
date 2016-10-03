
#include "_conio.h"

void _cputlt(void)
{
    if (isvidram()) {
        _curpos--;
        if (!isvidram()) {
            _curpos = _VIDRAM;
        }
    }  else if (isgrpram() && _conio.getfontinfo) {
        struct _fontinfo* fi = (struct _fontinfo*)_conio.getfontinfo();
        if (fi->type) {
            fi->base ^= 1;
        }
        if (!fi->type || fi->base & 1) {
            if (_curpos & (_horbyt - 1)) {
                _curpos--;
            } else {
                _curpos -= 1 + ((word)_horbyt << 3) - _horbyt;
            }
            if (!isgrpram()) {
                _curpos = _beggrp;
            }
        }
    }
}

