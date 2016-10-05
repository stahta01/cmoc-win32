
#include "_eat.h"

char* eat_until(char* str, ischar_t ischar)
{
    for (; *str && !ischar(*str); str++);
    return str;
}

