
#include <stdio.h>
#include <conio.h>

int fputc(int c, FILE* fp)
{
    if (fp) {
        return EOF;
    } else {
        cputc((char)c);
        return 0;
    }
}

