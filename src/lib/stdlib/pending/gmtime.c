/*---------------------------------------------------------------------------*/
/* gmtime() - convert the time value to a structure                          */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <time.h>
#include <llmath.h>

struct tm *gmtime(const time_t *timer)
{
  struct tm *tp;
  time_t curtime;
  unsigned long adjust = 0;
  unsigned long elapsed_days;
  unsigned long elapsed_years;
  unsigned long julian_days[12] = {  0,  31,  59,  90, 120, 151,
                                   181, 212, 243, 273, 304, 334 };
  if(*timer <= 2147483647L)
  {
    tp = _crt_base->_tm_base;
    curtime = (time_t)*timer;
    elapsed_days = curtime / 86400L;
    tp->tm_wday = (int)((elapsed_days + 4L) % 7L);
    curtime -= elapsed_days * 86400L;
    elapsed_years = elapsed_days / 365L;
    elapsed_days -= (elapsed_years + 1) / 4L;
    elapsed_years = elapsed_days / 365L;
    elapsed_days -= elapsed_years * 365L;
    tp->tm_year = (int)(elapsed_years + 70L);
    if(!(tp->tm_year % 4))
    {
      for(tp->tm_mon = 11; tp->tm_mon > 1; tp->tm_mon--)
        julian_days[tp->tm_mon]++;
    }
    tp->tm_mon = 11;
    while(julian_days[tp->tm_mon] > elapsed_days) tp->tm_mon--;
    tp->tm_mday = (int)((elapsed_days - julian_days[tp->tm_mon]) + 1);
    tp->tm_hour = (int)(curtime / 3600L);
    curtime -= (time_t)((unsigned long)tp->tm_hour * 3600L);
    tp->tm_min = (int)(curtime / 60L);
    tp->tm_sec = (int)(curtime - (tp->tm_min * 60));
    tp->tm_yday = (int)(julian_days[tp->tm_mon] + tp->tm_mday - 1);
    tp->tm_isdst = -1;
  } else {
    tp = NULL;
  }
  return(tp);
}
