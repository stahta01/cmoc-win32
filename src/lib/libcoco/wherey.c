
#include <conio.h>
#include <coco/equates.h>

unsigned char wherey(void)
{
    return (unsigned char)(_curpos >> 5) & 15;
}

