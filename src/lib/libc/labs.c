/*---------------------------------------------------------------------------*/
/* labs() - calculate the absolute value of a long integer                   */
/*---------------------------------------------------------------------------*/

#include <stddef.h>

long labs(long n)
{
    if (n < 0) {
        n = -n;
    }
    return (n);
}

