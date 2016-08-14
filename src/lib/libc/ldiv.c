/*---------------------------------------------------------------------------*/
/* ldiv() - divide signed long integers giving quotient and remainder        */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <llmath.h>

void ldiv(ldiv_t* result, long numer, long denom)
{
    result->quot = _idiv32(numer, denom);
    result->rem  = numer - _imul32(result->quot, denom);
}

