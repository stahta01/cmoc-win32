
/*  stdarg.h - Support for variable argument functions

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.
*/

#ifndef _stdarg_h_
#define _stdarg_h_

typedef unsigned int* va_list;

extern char* __va_arg(va_list* app, unsigned int sizeInBytes);

#define va_start(ap, lastFixed) do { (ap) = ((unsigned *) &(lastFixed)) + 1; } while (0)
#define va_arg(ap, type) (* (type *) __va_arg(&(ap), sizeof(type)))
#define va_end(ap) do {} while (0)


#endif  /* _stdarg_h_ */

