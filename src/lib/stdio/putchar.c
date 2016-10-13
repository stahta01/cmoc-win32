
#include "_stdio.h"

int putchar(int chr)
{
    return fputc(chr, stdout);
}

