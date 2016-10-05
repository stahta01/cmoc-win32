
#include "_conio.h"

bool cursor(bool onoff)
{
    bool result = _conio.cursor;
    _conio.cursor = onoff;
    return result;
}

