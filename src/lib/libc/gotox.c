
#include "_conio.h"

void gotox(unsigned char x)
{
    if (isvidram()) {
        _curpos = (_curpos & -32) | x;
    } else {
        if (_conio.fontpack) {
            _curpos = _curpos & ((unsigned)(_horbyt - 1) ^ -1) | (x >> 1);
            _conio.fontbase = x & 1 ? 128 : 0;
        } else {
            _curpos = _curpos & ((unsigned)(_horbyt - 1) ^ -1) | x;
        }
    }
}

