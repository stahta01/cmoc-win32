
#include "_eat.h"

char* eat_sign(char* str)
{
    if (*str == '-' || *str == '+') {
        str++;
    }
    return str;
}

