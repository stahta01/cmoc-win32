
#include "_stdio.h"

void perror(char* str)
{
    if (str) {
        cputs(str);
        cputs(": ");
    }
    cputs(strerror(errno));
    cputc('\n');
}

