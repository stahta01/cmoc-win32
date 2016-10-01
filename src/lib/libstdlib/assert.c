
#include "_stdlib.h"

void _assert(char* message, char* filename, unsigned line)
{
    printf("\nASSERT FAILED!\n\nFILE:%s\nLINE:%u\n%s\n", filename, line, message);
    exit(-1);
}

