
#include "_conio.h"

unsigned char wherex(void)
{
    unsigned char result = ((unsigned char*)_CURPOS)[1];
    if (isvidram()) {
        result &= 31;
    } else {
        struct _fontinfo* fi = _getfontinfo();
        result &= _horbyt - 1;
        if (fi->type) {
            result <<= 1;
            if (fi->base & 128) {
                result |= 1;
            }
        }
    }
    return result;
}

