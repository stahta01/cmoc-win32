
#include <stdio.h>
#include <string.h>

char* gets(char* s)
{
    // Note: fgets uses cgets for console input.
    // which is limited to 255 chars. So, dont use
    // a max number here that is greater than.
    // 64 is good I think
    return fgets(s, 64, stdin);
}

