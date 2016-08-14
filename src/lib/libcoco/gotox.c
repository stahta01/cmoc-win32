
#include <conio.h>
#include <coco/equates.h>

void gotox(unsigned char x)
{
    _curpos = (_curpos & 0xFFE0) | x;
}

