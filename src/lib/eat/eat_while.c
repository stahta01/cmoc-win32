
#include "_eat.h"

char* eat_while(char* str, ischar_t ischar)
{
    for (; *str && ischar(*str); str++);
    return str;
}
