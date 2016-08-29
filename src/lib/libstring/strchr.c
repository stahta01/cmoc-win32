
#define strchr __obsolete

/*---------------------------------------------------------------------------*/
/* strchr() - find a character in a string                                   */
/*---------------------------------------------------------------------------*/

#include <string.h>

char* strchr(char* s, int c)
{
    do {
        if (*s == c) {
            return s;
        }
    } while (*s++);
    return NULL;
}
