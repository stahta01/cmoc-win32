
#define tolower __obsolete

/*---------------------------------------------------------------------------*/
/* tolower() - convert to lower case                                         */
/*---------------------------------------------------------------------------*/

#include <ctype.h>

int tolower(int c)
{
    return _tolower(c);
}

