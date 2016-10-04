
#include "_system.h"

void system_cputs(char* str)
{
    while (*str) {
        system_cputc(*str++);
    }
}

