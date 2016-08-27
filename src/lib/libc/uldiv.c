
/*---------------------------------------------------------------------------*/
/* uldiv() - divide unsigned long integers giving quotient and remainder     */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <llmath.h>

void uldiv(uldiv_t* result, unsigned long numer, unsigned long denom)
{
    result->quot = _div32(numer, denom);
    result->rem  = numer - _mul32(result->quot, denom);
}

