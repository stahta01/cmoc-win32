
#include <conio.h>
#include <string.h>
#include <equates.h>

void scrclr(void)
{
    memset(_VIDRAM, 96, 32 * 16);
}

