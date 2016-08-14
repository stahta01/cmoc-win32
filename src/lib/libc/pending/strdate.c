/*---------------------------------------------------------------------------*/
/* _strdate() - move the current date to a string                            */
/*---------------------------------------------------------------------------*/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

char *_strdate(char *string)
{
  time_t ltime;
  struct tm *tp;

  time(&ltime);
  tp = localtime(&ltime);

  if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C) ||
     !strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_USA))
  {
    sprintf(string,
            "%.2d/%.2d/%.2d",
            tp->tm_mon + 1,
            tp->tm_mday,
            tp->tm_year);

  } else if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_FRANCE) ||
            !strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_GERMANY))
  {
    sprintf(string,
            "%.2d.%.2d.%.2d",
            tp->tm_mday,
            tp->tm_mon + 1,
            tp->tm_year);
  } else {
    sprintf(string,
            "%.2d/%.2d/%.2d",
            tp->tm_mday,
            tp->tm_mon + 1,
            tp->tm_year);
  }
  return(string);
}
