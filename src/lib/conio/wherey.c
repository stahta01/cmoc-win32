
#include "_conio.h"

int wherey(void)
{
    return isvidram() ? (_curpos >> 5) & 15 : _gettextpositiony();
}

