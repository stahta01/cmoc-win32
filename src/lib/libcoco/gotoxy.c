
#include <conio.h>
#include <coco/equates.h>

void gotoxy(unsigned char x, unsigned char y)
{
    _curpos = 1024 + (((unsigned)y) << 5) + x;
}

