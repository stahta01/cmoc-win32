/*---------------------------------------------------------------------------*/
/* itoa() - convert a signed integer to a string                             */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>

char* itoa(int value, char* string, int radix)
{
    return (ltoa((long)value, string, radix));
}

