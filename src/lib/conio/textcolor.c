
#include "_conio.h"

int textcolor(int pen)
{
    int result = (_h_crsatt >> 3) & 7;
    _h_crsatt = (byte)((_h_crsatt & 0xc7) | ((pen & 7) << 3));
    return result;
}

