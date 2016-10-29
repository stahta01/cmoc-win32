
#include "_eat.h"

char* eat_ident(char* str)
{
    if (isident(*str)) {
        do {
            str++;
        } while (isalnum(*str) || *str == '_');
    }
    return str;
}

