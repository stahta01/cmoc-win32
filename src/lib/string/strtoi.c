
#include "_string.h"

int strtoi(char* str, char** endptr, int base)
{
    for (; _isspace(*str); str++);
    int result = 0;
    char* pos = str;
    if (*pos == '+' || *pos == '-') {
        pos++;
    }
    if (!base) {
        if (*pos == '0') {
            pos++;
            if (*pos == 'x' || *pos == 'X') {
                base = 16;
                pos++;
            } else {
                base = 8;
            }
        } else {
            base = 10;
        }
    }
    for (char chr; chr = *pos; pos++) {
        chr = _isdigit(chr) ?  chr - '0' : _tolower(chr) - 'a' + 10;
        if (chr >= 0 && chr < base) {
            result = result * base + chr;
        } else {
            break;
        }
    }
    if (endptr) {
        *endptr = pos;
    }
    return *str == '-' ? -result : result;
}

