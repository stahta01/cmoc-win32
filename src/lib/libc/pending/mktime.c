/*---------------------------------------------------------------------------*/
/* mktime() - convert the local time to calendar time                        */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <time.h>

time_t mktime(struct tm *tp)
{
  long ctime;
  struct tm *tm_base;
  unsigned long elapsed_days;
  unsigned long elapsed_years;
  unsigned long julian_days[12] = {  0,  31,  59,  90, 120, 151,
                                   181, 212, 243, 273, 304, 334 };

  if(tp->tm_year < 139 && tp->tm_mon < 817 && tp->tm_mday < 24837)
  {
    elapsed_years = (tp->tm_mon / 12);
    tp->tm_mon -= (elapsed_years * 12);
    tp->tm_year += elapsed_years;

    elapsed_years = (tp->tm_mday / 365);
    tp->tm_mday -= (elapsed_years * 365);
    tp->tm_year += elapsed_years;

    elapsed_days = (tp->tm_hour / 24) +
                   (tp->tm_min / 1440) +
                   (tp->tm_sec / 86400L);

    if(tp->tm_year > 69 && tp->tm_year < 139 && elapsed_days < 24837)
    {
      ctime = tp->tm_hour * 3600 + tp->tm_min * 60 + tp->tm_sec;

      elapsed_days = (((tp->tm_year - 70) * 365) +
                      (((tp->tm_year - 70) + 1) / 4) +
                      julian_days[tp->tm_mon] +
                      tp->tm_mday - 1);

      if(!(tp->tm_year % 4) && tp->tm_mon > 1) elapsed_days++;

      if(elapsed_days < 24837)
      {
        ctime += elapsed_days * 86400L;
        ctime += _crt_base->_crt_timezone;

        if(ctime <= 2147483647L)
        {
          tm_base = _crt_base->_tm_base;
          _crt_base->_tm_base = tp;
          if(gmtime((const time_t *)&ctime) == NULL) ctime = (time_t) -1;
          _crt_base->_tm_base = tm_base;
        } else {
          ctime = (time_t) -1;
        }
      } else {
        ctime = (time_t) -1;
      }
    } else {
      ctime = (time_t) -1;
    }
  } else {
    ctime = (time_t) -1;
  }
  return((time_t)ctime);
}
