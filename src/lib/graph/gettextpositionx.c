
#include "_graph.h"

int _gettextpositionx(void)
{
    int result = _curpos & (_horbyt - 1);
    if (fontinfo.packed) {
        result = (result << 1) | (fontinfo.base & 1);
    }
    return result;
}

