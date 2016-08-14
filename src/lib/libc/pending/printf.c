/*---------------------------------------------------------------------------*/
/* printf() - print formatted data to stdout                                 */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int printf(const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  return(_printfs(stdout, NULL, format, ap));
}
