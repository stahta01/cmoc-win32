
#include "_conio.h"

void putlf(void)
{
    putdn();
    _curpos &= 0xffe0;
    _conio.fontbase = 0;
}

