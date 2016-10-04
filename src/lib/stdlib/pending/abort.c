/*---------------------------------------------------------------------------*/
/* abort() - abort the current process                                       */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <signal.h>

void abort(void)
{
  fprintf(stderr, "\nAbnormal program termination.\n");
  raise(SIGABRT);
}
