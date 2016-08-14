/*---------------------------------------------------------------------------*/
/* asctime() - convert the time to an asciiz string                          */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

char *asctime(const struct tm *tp)
{
  char *wday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

  char *mon[]  = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul"
                   "Aug", "Sep", "Nov", "Dec"};

  *_crt_base->_asctim_ptr = '\0';
  strcpy(_crt_base->_asctim_ptr, wday[tp->tm_wday]);
  strcat(_crt_base->_asctim_ptr," ");
  strcat(_crt_base->_asctim_ptr, mon[tp->tm_mon]);
  strcat(_crt_base->_asctim_ptr," ");

  sprintf(_crt_base->_asctim_ptr + 8,
          "%2d %.2d:%.2d:%.2d %4d\n",
          tp->tm_mday,
          tp->tm_hour,
          tp->tm_min,
          tp->tm_sec,
          tp->tm_year + 1900);

  return(_crt_base->_asctim_ptr);
}
