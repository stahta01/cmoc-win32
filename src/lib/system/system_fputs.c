
#include "_system.h"

void system_fputs(char* str)
{
    while (*str) {
        system_fputc(*str++);
    }
}

