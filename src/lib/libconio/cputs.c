
#include "_conio.h"

void cputs(char* s)
{
    while (*s) {
        cputc(*s++);
    }
}

