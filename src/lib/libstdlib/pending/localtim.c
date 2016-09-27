/*---------------------------------------------------------------------------*/
/* localtime() - convert the time value to a structure and correct for       */
/*               local time                                                  */
/*---------------------------------------------------------------------------*/
#include <time.h>

struct tm *localtime(const time_t *tp)
{
  time_t curtime;
  curtime = *tp - _crt_base->_crt_timezone;
  return(gmtime(&curtime));
}
