
#include <conio.h>
#include <equates.h>

unsigned char wherex(void)
{
    return (unsigned char)(_curpos & 31);
}

