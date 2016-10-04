
#include "_graph.h"

void _movetextposition(int direction)
{
    word bytesperrow = (word)_horbyt << 3;
    switch (direction) {
    case _GMOVEUP:
        _curpos -= bytesperrow;
        if (_curpos < _beggrp) {
            _curpos += bytesperrow;
        }
        break;
    case _GMOVEDOWN:
        _curpos += bytesperrow;
        if (_curpos >= _endgrp) {
            _curpos -= bytesperrow;
            _scrolltextwindow(_GSCROLLUP);
        }
        break;
    case _GMOVELEFT:
        if (fontinfo.type) {
            fontinfo.base ^= 1;
        }
        if (!fontinfo.type || fontinfo.base & 1) {
            if (_curpos & (_horbyt - 1)) {
                _curpos--;
            } else {
                _curpos -= 1 + bytesperrow - _horbyt;
            }
            if (_curpos < _beggrp) {
                _curpos = _beggrp;
            }
        }
        break;
    case _GMOVERIGHT:
        if (!fontinfo.type || fontinfo.base & 1) {
            _curpos++;
            if ((_curpos & (_horbyt - 1)) == 0) {
                _curpos += bytesperrow - _horbyt;
            }
            if (_curpos >= _endgrp) {
                _curpos -= bytesperrow;
                _scrolltextwindow(_GSCROLLUP);
            }
        }
        if (fontinfo.type) {
            fontinfo.base ^= 1;
        }
        break;
    }
}

