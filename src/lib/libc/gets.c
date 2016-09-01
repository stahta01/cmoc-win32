
#include <stdio.h>
#include <string.h>

char* gets(char* s)
{
    return fgets(s, BUFSIZ, stdin);
}

