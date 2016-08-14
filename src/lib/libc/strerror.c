/*---------------------------------------------------------------------------*/
/* strerror() - get the system defined error message                         */
/*---------------------------------------------------------------------------*/

#include <errno.h>
#include <stdlib.h>

char* strerror(int errnum)
{
    if ((errnum >= 0) && (errnum <= _sys_nerr)) {
        return _sys_errlist[errnum];
    } else {
        return _sys_errlist[_sys_nerr];
    }
}

