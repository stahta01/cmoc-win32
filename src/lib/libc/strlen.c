
#define strlen __obsolete

/*---------------------------------------------------------------------------*/
/* strlen() - get the length of a string                                     */
/*---------------------------------------------------------------------------*/

#include <string.h>

size_t strlen(char* string)
{
    size_t slen = 0;
    while (*string) {
        slen++;
        string++;
    }
    return (slen);
}

