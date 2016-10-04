/*---------------------------------------------------------------------------*/
/* scanf() - scan formatted data from stdout                                 */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int scanf(const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  return(_scanfs(stdout, NULL, format, ap));
}
