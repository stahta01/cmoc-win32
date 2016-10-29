
#include "_eat.h"

char* eat_quoted(char* str, char quote)
{
    if (*str == quote) {
        do {
            str++;
        } while (*str && *str != quote && str[-1] != '\\');
        if (*str) {
            str++;
        }
    }
    return str;
}

