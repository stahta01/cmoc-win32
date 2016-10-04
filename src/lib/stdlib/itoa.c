
#include "_stdlib.h"

char* itoa(int val, char* str, int radix)
{
    char* p = str, prefix = '0';
    if (radix >= 2 && radix <= 36) {
        if (val < 0 && radix == 10) {
            prefix = '-';
            val = -val;
        } else {
            prefix = 0;
        }
        do {
            byte rem = (byte)((byte)val % (byte)radix);
            *p++ = rem + (rem < 10 ? '0' : 'W');
        } while (val = (word)val / (byte)radix);
    }
    if (*p++ = prefix) {
        *p = 0;
    }
    return _reverse(str);
}

