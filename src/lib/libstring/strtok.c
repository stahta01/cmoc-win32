
/*---------------------------------------------------------------------------*/
/* strtok() - find the next token in a string                                */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stddef.h>

char* _strtok_ptr = NULL;

char* strtok(char* string1, char* string2)
{
    char* p1, *p2;
    int found = 1;
    p2 = NULL;
    if (string1 != NULL) {
        _strtok_ptr = string1;
    }
    while (*_strtok_ptr && (found)) {
        found = 0;
        p1 = (char*)string2;
        while (*p1 && (!found)) {
            if (*_strtok_ptr == *p1) {
                found = 1;
                _strtok_ptr++;
            }
            p1++;
        }
    }
    if (*_strtok_ptr) {
        p2 = _strtok_ptr;
        while (*_strtok_ptr && (!found)) {
            p1 = (char*)string2;
            while (*p1 && (!found)) {
                if (*_strtok_ptr == *p1) {
                    *_strtok_ptr = '\0';
                    found = 1;
                }
                p1++;
            }
            _strtok_ptr++;
        }
    }
    return (p2);
}

