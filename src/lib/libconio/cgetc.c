
#include "_conio.h"

bool _cursor_onoff = true;

bool cursor(bool onoff)
{
    bool result = _cursor_onoff;
    _cursor_onoff = onoff;
    return result;
}

int cgetc(void)
{
    if (!_cursor_onoff) {
        while (!kbhit()) {}
    }
    return getch();
}

