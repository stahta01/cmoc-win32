
#include "_libc.h"

char* utoa(word value, char* string, int radix)
{
    char* p = string;
    if (radix >= 2 && radix <= 36) {
        do {
            word rem = value % radix;
            value = value / radix;
            *p++ = (char)(rem < 10 ? rem + '0' : rem + 'W');
        } while (value);
    } else {
        *p++ = '0';
    }
    *p = 0;
    return _strrev(string);
}

