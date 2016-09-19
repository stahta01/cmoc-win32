
#include "_conio.h"

int wherex(void)
{
    return isvidram() ? _curpos & 31 : _gettextpositionx();
}

