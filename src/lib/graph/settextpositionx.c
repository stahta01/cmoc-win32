
#include "_graph.h"

void _settextpositionx(int x)
{
    if (fontinfo.packed) {
        fontinfo.base = (fontinfo.base & 0xfe) | (x & 1);
        x >>= 1;
    }
    _curpos = _curpos & ((word)(_horbyt - 1) ^ -1) | x;
}

