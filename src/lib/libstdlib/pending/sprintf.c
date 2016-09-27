/*---------------------------------------------------------------------------*/
/* sprintf() - print formatted data to a string                              */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int sprintf(char *buffer, const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  return(_printfs(NULL, buffer, format, ap));
}
