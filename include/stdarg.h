
/*  stdarg.h - Support for variable argument functions

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.
*/

#ifndef _STDARG_H
#define _STDARG_H

typedef unsigned* va_list;

extern char* _va_arg(va_list* app, unsigned sizeInBytes);

#define va_start(ap, lastFixed) do { (ap) = ((unsigned *) &(lastFixed)) + 1; } while (0)
#define va_arg(ap, type) (* (type *) _va_arg(&(ap), sizeof(type)))
#define va_end(ap) do {} while (0)


#endif

