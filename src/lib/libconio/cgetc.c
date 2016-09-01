
#include <conio.h>

unsigned char _cursor_onoff = 1;

unsigned char cursor(unsigned char onoff)
{
    unsigned char result = _cursor_onoff;
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

