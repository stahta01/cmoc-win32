
#include "_libc.h"

char* ultoa(unsigned long value, char* string, int radix)
{
    uldiv_t result;
    char* p = string;
    if (radix >= 2 && radix <= 36) {
        do {
            uldiv(&result, value, (unsigned long)radix);
            value = result.quot;
            if (result.rem < 10) {
                *p = (char)((char)(result.rem) + (char)'0');
            } else {
                *p = (char)((char)(result.rem - 10) + (char)'A');
            }
            p++;
        } while (value > 0);
    } else {
        *p = '0';
        p++;
    }
    *p = '\0';
    return (strrev(string));
}

