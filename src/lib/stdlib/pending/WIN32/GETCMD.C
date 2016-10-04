/*---------------------------------------------------------------------------*/
/*  _getcmd() - get a pointer to the command line                            */
/*---------------------------------------------------------------------------*/
#include <win32.h>

char *_getcmd(void)
{
  return (GetCommandLineA());
}
