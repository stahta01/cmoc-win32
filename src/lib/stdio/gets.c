
#include "_stdio.h"

char* gets(char* s)
{
    return fgets(s, MAX_INPUT, stdin);
}

