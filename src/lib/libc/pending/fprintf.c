/*---------------------------------------------------------------------------*/
/* fprintf() - print formatted data to a stream                              */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int fprintf(FILE *fp, const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  return(_printfs(fp, NULL, format, ap));
}
