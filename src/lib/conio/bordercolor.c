
#include "_conio.h"

int bordercolor(int color)
{
    int result = _v_border;
    _v_border = (byte)color;
    return result;
}

