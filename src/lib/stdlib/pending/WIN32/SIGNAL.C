/*---------------------------------------------------------------------------*/
/* signal() - set signal handler                                             */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <errno.h>
#include <signal.h>

PFSIG signal(int sig, void(*func)(int sig))
{
  PFSIG sigptr = SIG_ERR;
  unsigned long *excpptr;
  if((sig >= SIGINT) && (sig <= SIGABRT))
  {
    excpptr = (unsigned long *) (_crt_base->_excp_base);
    excpptr += (sig - 1);
    sigptr = (PFSIG)*excpptr;
    *excpptr = (unsigned long)func;
  } else {
    _crt_base->_crt_errno = EINVAL;
  }
  return(sigptr);
}
