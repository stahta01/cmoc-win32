/*---------------------------------------------------------------------------*/
/* _ceh() WIN32 32 bit control break handler                                 */
/*---------------------------------------------------------------------------*/
#include <win32.h>
#include <crt.h>
#include <signal.h>
#include <stdlib.h>
#include <except.h>

#define TRUE  1
#define FALSE 0

BOOL WINAPI _ceh(DWORD CtrlType)
{
  int signal;
  unsigned long *excpptr;
  excpptr = (unsigned long *) (_crt_base->_excp_base);

  switch(CtrlType)
  {
    case CTRL_C_EVENT:
      signal = SIGINT;
      break;

    case CTRL_BREAK_EVENT:
      signal = SIGBREAK;
      break;

    case CTRL_CLOSE_EVENT:
    case CTRL_LOGOFF_EVENT:
    case CTRL_SHUTDOWN_EVENT:
      signal = SIGTERM;
      break;

    default:
      signal = 0;
  }
  if(signal)
  {
    excpptr += (unsigned long)(signal - 1);
    if(*excpptr == (unsigned long)SIG_DFL)
    {
      return(FALSE);
    } else if(*excpptr != (unsigned long)SIG_IGN) {
      ((PFSIG)*excpptr)(signal);
    }
    return(TRUE);
  }
  return(FALSE);
}
