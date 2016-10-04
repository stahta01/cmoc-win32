/*---------------------------------------------------------------------------*/
/* time() - return the current calendar time                                 */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <time.h>

time_t time(time_t *tp)
{
  time_t ctime;
  struct DATETIME timebuf;
  unsigned long elapsed_days;
  unsigned long julian_days[12] = {  0,  31,  59,  90, 120, 151,
                                   181, 212, 243, 273, 304, 334 };
  #ifdef _WIN32
    GetLocalTime(&timebuf);
  #else
    DosGetDateTime(&timebuf);
  #endif

  ctime = timebuf.hours * 3600L +
          timebuf.minutes * 60L +
          timebuf.seconds;

  ctime += _crt_base->_crt_timezone;

  elapsed_days = (((timebuf.year - 1970) * 365L) +
                 (((timebuf.year - 1970) + 1) / 4) +
                 julian_days[timebuf.month - 1] +
                 timebuf.day - 1);

  if(!(timebuf.year % 4) && timebuf.month > 2)  elapsed_days++;

  ctime += elapsed_days * 86400L;

  if(tp != NULL) *tp = ctime;

  return(ctime);
}
