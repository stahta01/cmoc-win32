
#include "_conio.h"

void cputc(int chr)
{
    chr <<= 8;
    cputs((char*)&chr);
}

