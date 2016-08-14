
/*---------------------------------------------------------------------------*/
/* atol() - convert a string to a signed long integer                        */
/*---------------------------------------------------------------------------*/

#include <llmath.h>

long atol(char* string)
{
    char sign = 0;
    long value = 0;
    while ((*string == ' ') || (*string == '\t') ||
           (*string == '\n') || (*string == '\r')) {
        string++;
    }
    if ((*string == '-') || (*string == '+')) {
        sign = *string;
        string++;
    }
    while (*string) {
        if ((*string >= '0') && (*string <= '9')) {
            value = _mul32(value, 10) + (*string - '0');
            string++;
        } else {
            break;
        }
    }
    if (sign == '-') {
        value = -value;
    }
    return (value);
}


