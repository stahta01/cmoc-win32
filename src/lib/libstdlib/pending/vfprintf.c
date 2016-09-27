/*---------------------------------------------------------------------------*/
/* vfprintf() - print formatted data to a stream with variable arg pointer   */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int vfprintf(FILE *fp, const char *format, va_list ap)
{
  return(_printfs(fp, NULL, format, ap));
}
