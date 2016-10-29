
#include "_string.h"

int strtoi(char* str, char** endptr, int base)
{
    int chr = *(str = eat_while_space(str));
    if (chr == '+' || chr == '-') {
        str++;
    }
    int result = strtou(str, endptr, base);
    return chr == '-' ? -result : result;
}

