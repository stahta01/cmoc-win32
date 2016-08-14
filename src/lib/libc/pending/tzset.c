/*---------------------------------------------------------------------------*/
/* _tzset() - set the current time zone                                      */
/*---------------------------------------------------------------------------*/
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <llmath.h>

void _tzset(void)
{
  int envlen;
  char sign = 0;
  char *envptr;
  envptr = getenv("TZ");
  if(envptr != NULL)
  {
    envlen = strlen(envptr);
    if(envlen >= 3)
    {
       strncpy(&_crt_base->_crt_tzbuffer[0][0], envptr, 3);
      _crt_base->_crt_tzname[0] = &_crt_base->_crt_tzbuffer[0][0];
      _crt_base->_crt_tzbuffer[1][3] = '\0';
      envptr += 3;
      if(envptr)
      {
        _crt_base->_crt_daylight = 0;
        _crt_base->_crt_timezone = 0;
        _crt_base->_crt_tzbuffer[1][0] = '\0';
        _crt_base->_crt_tzname[1] = &_crt_base->_crt_tzbuffer[1][0];
        if(*envptr == '+' || *envptr == '-')
        {
          sign = *envptr;
          envptr++;
        }
        while(*envptr >= '0' && *envptr <= '9')
        {
          _crt_base->_crt_timezone = _mul32(_crt_base->_crt_timezone, 10)
                                     + (*envptr - '0');
          envptr++;
        }
        if(sign == '-') _crt_base->_crt_timezone = -_crt_base->_crt_timezone;
        _crt_base->_crt_timezone = _mul32(_crt_base->_crt_timezone, 3600L);
        envlen = 0;
        while(*envptr && envlen < 3)
        {
          _crt_base->_crt_tzbuffer[1][envlen] = *envptr;
          envptr++;
          envlen++;
        }
        if(envlen)
        {
          _crt_base->_crt_daylight = 1;
          _crt_base->_crt_tzbuffer[1][envlen] = '\0';
        }
      }
    }
  }
}
