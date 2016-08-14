
#include <conio.h>

void cputc(char c)
{
    putch(c == 10 ? 13 : c);
}
