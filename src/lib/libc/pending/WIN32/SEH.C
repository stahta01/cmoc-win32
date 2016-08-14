/*---------------------------------------------------------------------------*/
/* _seh() WIN32 32 bit structured exception handler                           */
/*---------------------------------------------------------------------------*/
#include <win32.h>
#include <crt.h>
#include <signal.h>
#include <stdlib.h>
#include <except.h>

EXCEPTION_DISPOSITION _seh(struct _EXCEPTION_RECORD *ExceptionRecord,
                           void * EstablisherFrame,
                           struct _CONTEXT *ContextRecord,
                           void * DispatcherContext)
{
  int signal;
  unsigned long *excpptr;
  excpptr = (unsigned long *) (_crt_base->_excp_base);

  switch(ExceptionRecord->ExceptionCode)
  {
    case EXCEPTION_ACCESS_VIOLATION:
      signal = SIGSEGV;
      break;

    case EXCEPTION_ILLEGAL_INSTRUCTION:
    case EXCEPTION_PRIV_INSTRUCTION:
      signal = SIGILL;
      break;

    case EXCEPTION_FLT_DENORMAL_OPERAND:
    case EXCEPTION_FLT_DIVIDE_BY_ZERO:
    case EXCEPTION_FLT_INEXACT_RESULT:
    case EXCEPTION_FLT_INVALID_OPERATION:
    case EXCEPTION_FLT_OVERFLOW:
    case EXCEPTION_FLT_STACK_CHECK:
    case EXCEPTION_FLT_UNDERFLOW:
      signal = SIGFPE;
      break;

    default:
      signal = 0;
  }
  if(signal)
  {
    excpptr += (unsigned long)(signal - 1);
    if(*excpptr == (unsigned long)SIG_DFL)
    {
      return(EXCEPTION_CONTINUE_SEARCH);
    } else if(*excpptr != (unsigned long)SIG_IGN) {
      ((PFSIG)*excpptr)(signal);
    }
    return(EXCEPTION_CONTINUE_EXECUTION);
  }
  return(EXCEPTION_CONTINUE_SEARCH);
}
