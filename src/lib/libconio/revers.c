
#include "_conio.h"

bool revers(bool onoff)
{
    bool result = _conio.revers;
    _conio.revers = onoff;
    return result;
}
