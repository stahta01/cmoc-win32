
#include <conio.h>

unsigned char conio_bgcolor = 1;

unsigned char bgcolor(unsigned char color)
{
    unsigned char result = conio_bgcolor;
    conio_bgcolor = color;
    return result;
}

