/*---------------------------------------------------------------------------*/
/* fdopen() - associate a handle with a stream                               */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

FILE *fdopen(int handle, const char *mode)
{
  FILE *fp;
  fp = _fsopen(NULL, mode, -1);
  if(fp != NULL)
  {
    fp->fd = handle;
  }
  return(fp);
}
