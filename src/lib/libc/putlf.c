
#include <conio.h>
#include <equates.h>

void putlf(void)
{
    putdn();
    _curpos &= 0xffe0;
}

