/*---------------------------------------------------------------------------*/
/* fscanf() - scan formatted data from a stream                              */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int fscanf(FILE *fp, const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  return(_scanfs(fp, NULL, format, ap));
}
