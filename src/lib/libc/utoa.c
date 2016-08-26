
#include <stdlib.h>
#include <string.h>

char* utoa(unsigned value, char* string, int radix)
{
    unsigned rem;
    char* p = string;
    if (radix >= 2 && radix <= 36) {
        do {
            rem = value % radix;
            value = value / radix;
            if (rem < 10) {
                *p = (char)((char)(rem) + (char)'0');
            } else {
                *p = (char)((char)(rem - 10) + (char)'A');
            }
            p++;
        } while (value > 0);
    } else {
        *p = '0';
        p++;
    }
    *p = '\0';
    return strrev(string);
}

