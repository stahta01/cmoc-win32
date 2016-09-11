
#define atoi __obsolete

/*---------------------------------------------------------------------------*/
/* atoi() - convert a string to a signed short integer                       */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>

int atoi(char* string)
{
    char sign = 0;
    int value = 0;
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
            value = (value * 10) + (*string - '0');
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

