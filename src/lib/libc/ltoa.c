/*---------------------------------------------------------------------------*/
/* ltoa() - convert a signed long integer to a string                        */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>

char* ltoa(long value, char* string, int radix)
{
    uldiv_t result;
    short sign = 0;
    char* p = string;
    if (radix >= 2 && radix <= 36) {
        if ((value < 0) && (radix == 10)) {
            value = -value;
            sign++;
        }
        do {
            uldiv(&result, value, (unsigned long)radix);
            value = result.quot;
            if (result.rem < 10) {
                *p = (char)((char)(result.rem) + (char)'0');
            } else {
                *p = (char)((char)(result.rem - 10) + (char)'a');
            }
            p++;
        } while (value > 0);
        if (sign) {
            *p = '-';
            p++;
        }
    } else {
        *p = '0';
        p++;
    }
    *p = '\0';
    return (strrev(string));
}
