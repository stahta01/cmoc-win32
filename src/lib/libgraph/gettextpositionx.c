
#include "_graph.h"

int _gettextpositionx(void)
{
    int result = _curpos & (_horbyt - 1);
    if (fontinfo.type) {
        result <<= 1;
        if (fontinfo.base & 128) {
            result |= 1;
        }
    }
    return result;
}

