
#include "_stdio.h"

char* gets(char* s)
{
    return fgets(s, BUFSIZ, stdin);
}

