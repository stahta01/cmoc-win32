
#include "_string.h"

word strton(char* str, char** endptr, int base)
{
    word result = 0;
    for (int chr; chr = *str; str++) {
        chr = isdigit(chr) ?  chr - '0' : tolower(chr) - 'a' + 10;
        if (chr >= 0 && chr < base) {
            result = result * base + chr;
        } else {
            break;
        }
    }
    if (endptr) {
        *endptr = str;
    }
    return result;
}

