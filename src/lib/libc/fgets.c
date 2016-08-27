
#include <stdio.h>
#include <string.h>
#include <conio.h>

char* fgets(char* s, size_t n, FILE* fp)
{
    if (fp) {
        return NULL;
    } else {
        s[0] = (char)n;
        strcpy(s, cgets(s));
        cputc('\n');
        return s;
    }
}

