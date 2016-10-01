
/*  stdarg.h - Support for variable argument functions

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.
*/

#ifndef _STDARG_H
#define _STDARG_H

#include <sys/size.h>

typedef word* va_list;

extern char* _va_arg(va_list* list, size_t size);

#define va_start(_LIST,_ARG) ((_LIST)=(va_list)&(_ARG)+1)
#define va_arg(_LIST,_TYPE) (*(_TYPE*)_va_arg(&(_LIST),sizeof(_TYPE)))
#define va_end(_LIST)

#endif

