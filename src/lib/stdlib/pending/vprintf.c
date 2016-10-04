/*---------------------------------------------------------------------------*/
/* vprintf() - print formatted data to stdout with variable arg pointer      */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int vprintf(const char *format, va_list ap)
{
  return(_printfs(stdout, NULL, format, ap));
}
