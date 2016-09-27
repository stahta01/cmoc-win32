/*---------------------------------------------------------------------------*/
/* sprintf() - print formatted data to a string with variable arg pointer    */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int vsprintf(char *buffer, const char *format, va_list ap)
{
  return(_printfs(NULL, buffer, format, ap));
}
