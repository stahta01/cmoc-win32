
#include "_string.h"

unsigned strtou(char* str, char** endptr, int base)
{
    if (!base) {
        if (*str == '0') {
            str++;
            if (*str == 'x' || *str == 'X') {
                str++;
                base = 16;
            } else {
                base = 8;
            }
        } else {
            base = 10;
        }
    }
    return strton(str, endptr, base);
}

