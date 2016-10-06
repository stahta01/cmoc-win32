
#include "_conio.h"

bool _static_cursor = true;

bool cursor(bool onoff)
{
    bool result = _static_cursor;
    _static_cursor = onoff;
    return result;
}

int cgetc(void)
{
    if (!_static_cursor) {
        while (!kbhit()) {}
    }
    return getch();
}

