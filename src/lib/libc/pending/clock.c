/*---------------------------------------------------------------------------*/
/* clock() - get the processor time since the start of execution             */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <crt.h>
#include <time.h>

clock_t clock(void)
{
  clock_t ctime;
  struct DATETIME timebuf;
  unsigned long elapsed_days;
  unsigned long julian_days[12] = {  0,  31,  59,  90, 120, 151,
                                   181, 212, 243, 273, 304, 334 };

  #ifdef _WIN32
     GetLocalTime(&timebuf);
     timebuf.hundredths /= 10;
  #else
    DosGetDateTime(&timebuf);
  #endif

  ctime = (timebuf.hours * 360000L + timebuf.minutes * 6000L +
           timebuf.seconds * 100L + timebuf.hundredths) -
           _crt_base->_base_time;

  elapsed_days = (((timebuf.year - 1970) * 365L) +
                 (((timebuf.year - 1970) + 1)/ 4) +
                 julian_days[timebuf.month - 1] +
                 timebuf.day - 1) - _crt_base->_base_date;

  if(timebuf.year > 2000) elapsed_days--;

  if(timebuf.year != 2000 && !(timebuf.year % 4) && timebuf.month > 2)
     elapsed_days++;

  ctime += elapsed_days * 8640000L;

  return(ctime);
}
