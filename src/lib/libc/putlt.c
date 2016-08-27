
#include "_conio.h"

void putlt(void)
{
    if (isvidram()) {
        _curpos--;
        if (!isvidram()) {
            _curpos = _VIDRAM;
        }
    }  else if (isgrpram()) {
        if (_conio.fontpack) {
            _conio.fontbase -= 128;
        }
        if (!_conio.fontpack || _conio.fontbase & 128) {
            if (_curpos & (_horbyt - 1)) {
                _curpos--;
            } else {
                _curpos += (unsigned)_horbyt << 3;
            }
            if (!isgrpram()) {
                _curpos = _beggrp;
            }
        }
    }
}

