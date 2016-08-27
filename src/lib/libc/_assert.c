
#include <stdio.h>
#include <assert.h>

void _assert(char* _Message,  char* _File, unsigned _Line)
{
    printf("\nASSERT FAILED!\n\nFILE:%s\nLINE:%d\n%s\n", _File, _Line, _Message);
    exit(-1);
}

