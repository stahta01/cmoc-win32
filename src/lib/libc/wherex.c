
#include "_conio.h"

unsigned char wherex(void)
{
    unsigned char result = ((unsigned char*)_CURPOS)[1];
    if (isvidram()) {
        result &= 31;
    } else {
        result &= _horbyt - 1;
        if (_conio.fontpack) {
            result <<= 1;
            if (_conio.fontbase & 128) {
                result |= 1;
            }
        }
    }
    return result;
}

