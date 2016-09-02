
#include "_conio.h"

unsigned char wherey(void)
{
    return isvidram() ? (unsigned char)(_curpos >> 5) & 15 : (unsigned char)_gettextpositiony();
}

