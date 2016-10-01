
#include "_system.h"

void system_cputs(char* s)
{
    while (*s) {
        system_cputc(*s++);
    }
}

