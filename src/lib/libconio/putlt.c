
#include "_conio.h"

void putlt(void)
{
    if (isvidram()) {
        _curpos--;
        if (!isvidram()) {
            _curpos = _VIDRAM;
        }
    }  else if (isgrpram()) {
        struct _fontinfo* fi = _getfontinfo();

        if (fi->type) {
            fi->base -= 128;
        }
        if (!fi->type || fi->base & 128) {
            if (_curpos & (_horbyt - 1)) {
                _curpos--;
            } else {
                _curpos -= 1 + ((unsigned)_horbyt << 3) - _horbyt;
            }
            if (!isgrpram()) {
                _curpos = _beggrp;
            }
        }
    }
}

