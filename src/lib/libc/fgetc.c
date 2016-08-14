
#include <stdio.h>
#include <conio.h>

int fgetc(FILE* fp)
{
    if (fp) {
        return EOF;
    } else {
        return cgetc();
    }
}

