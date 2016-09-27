/*---------------------------------------------------------------------------*/
/* fflush() - flush a stream i/o buffer                                      */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

int fflush(FILE *fp)
{
  int bufsize;
  int flag = 0;
  if((fp->flag & _ENABLED) && (fp->flag & _WRITE) && !(fp->flag & _UNBUF))
  {
    bufsize = fp->size - fp->cnt;
    if(write(fp->fd, fp->base, bufsize) != bufsize)
    {
      fp->flag |= _ERR;
      flag = EOF;
    } else {
      fp->cnt = fp->size;
    }
  }
  return(flag);
}
