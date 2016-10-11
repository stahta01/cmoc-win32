
#include "_stdlib.h"

int strtoi(char* str, char** endptr, int base)
{
    for (; isspace(*str); str++);
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
        if (isdigit(chr)) {
            chr -= '0';
        } else if (islower(chr)) {
            chr -= 'a' - 10;
        } else if (isupper(chr)) {
            chr -= 'A' - 10;
        } else {
            break;
        }
        result = result * base + chr;
    }
    if (*str == '-') {
        result = -result;
    }
    if (endptr) {
        *endptr = pos;
    }
    return result;
}

