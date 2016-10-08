
#include "_conio.h"

int bgcolor(int pen)
{
    int result = _h_crsatt & 7;
    _h_crsatt = (byte)((_h_crsatt & 0xf8) | (pen & 7));
    return result;
}

