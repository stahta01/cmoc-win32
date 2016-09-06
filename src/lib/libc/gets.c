
#include "_libc.h"

char* gets(char* s)
{
    return fgets(s, BUFSIZ, stdin);
}

