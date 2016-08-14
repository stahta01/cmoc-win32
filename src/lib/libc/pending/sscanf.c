/*---------------------------------------------------------------------------*/
/* sscanf() - scan formatted data from a string                              */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int sscanf(const char *buffer, const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  return(_scanfs(NULL, buffer, format, ap));
}
