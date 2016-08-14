/*
** Al's FREE-C Runtime Library (2016)
**
** This is an updated version of A. Maromaty's library dated 21-Apr-1998
** Code includes bug fixes, optimizations and native memory allocation.
**
*/

/*---------------------------------------------------------------------------*/
/* strupr() - convert a string to upper case                                 */
/*---------------------------------------------------------------------------*/

#include <ctype.h>

char* strupr(char* string)
{
    char* p = string;
    while (*p) {
        *p = (char)toupper(*p);
        p++;
    }
    return (string);
}

