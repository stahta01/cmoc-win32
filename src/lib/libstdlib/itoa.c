
#include "_libc.h"

char* itoa(int value, char* string, int radix)
{
    char* p = string;
    if (radix >= 2 && radix <= 36) {
        bool sign = value < 0 && radix == 10;
        if (sign) {
            value = -value;
        }
        do {
            word rem = (word)value % radix;
            value = (word)value / radix;
            *p++ = (char)(rem < 10 ? rem + '0' : rem + 'W');
        } while (value > 0);
        if (sign) {
            *p++ = '-';
        }
    } else {
        *p++ = '0';
    }
    *p = 0;
    return _strrev(string);
}

