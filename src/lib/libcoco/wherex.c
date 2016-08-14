
#include <conio.h>
#include <coco/equates.h>

unsigned char wherex(void)
{
    return (unsigned char)(_curpos & 31);
}

