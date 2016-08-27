
#define strcpy __obsolete

/*---------------------------------------------------------------------------*/
/* strcpy() - copy a string to another                                       */
/*---------------------------------------------------------------------------*/

#include <string.h>

char* strcpy(char* dst, char* src)
{
    char* result = dst;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return result;
}

