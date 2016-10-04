/*---------------------------------------------------------------------------*/
/* raise() - send a signal to the executing process                          */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <signal.h>
#include <stdlib.h>

int raise(int sig)
{
  int rc = 0;
  unsigned long *excpptr;
  switch(sig)
  {
    case SIGABRT:
    case SIGBREAK:
    case SIGTERM:
    case SIGFPE:
    case SIGILL:
    case SIGSEGV:
    case SIGINT:
      excpptr = (unsigned long *) (_crt_base->_excp_base);
      excpptr += (sig - 1);
      if(*excpptr == (unsigned long)SIG_DFL)
      {
        exit(3);
      } else if(*excpptr != (unsigned long)SIG_IGN) {
        ((PFSIG)*excpptr)(sig);
      }
      break;

     default:
      rc = -1;
      break;
  }
  return(rc);
}
