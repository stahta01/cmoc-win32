
#include "_libc.h"

char* itoa(int value, char* string, int radix)
{
    return (ltoa((long)value, string, radix));
}

