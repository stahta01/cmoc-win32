
#include <conio.h>
#include <equates.h>

void cputlf(void)
{
    cputdn();
    _curpos &= 0xffe0;
}

