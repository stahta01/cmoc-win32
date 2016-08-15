
#include <conio.h>
#include <equates.h>

void gotoy(unsigned char y)
{
    _curpos = (_curpos & 31) | (((unsigned)y) << 5);
}

