
#define toupper __obsolete

/*---------------------------------------------------------------------------*/
/* toupper() - convert to upper case                                         */
/*---------------------------------------------------------------------------*/

#include <ctype.h>

int toupper(int c)
{
    return _toupper(c);
}

