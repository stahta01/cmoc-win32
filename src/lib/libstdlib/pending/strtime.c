/*---------------------------------------------------------------------------*/
/* _strtime() - move the current time to a string                            */
/*---------------------------------------------------------------------------*/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

char *_strtime(char *string)
{
  time_t ltime;
  char tmsep = ':';
  struct tm *tp;

  time(&ltime);
  tp = localtime(&ltime);

  if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_FRANCE)) tmsep = '.';

  sprintf(string,
          "%.2d%c%.2d%c%.2d",
           tp->tm_hour,
           tmsep,
           tp->tm_min,
           tmsep,
           tp->tm_sec);

  return(string);
}
