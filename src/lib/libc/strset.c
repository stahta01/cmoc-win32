
/*---------------------------------------------------------------------------*/
/* strset() - set the contents of a string to a character                    */
/*---------------------------------------------------------------------------*/

#include <string.h>

char* strset(char* string, int c)
{
    char* p = string;
    while (*p) {
        *p = (char)c;
        p++;
    }
    return (string);
}

