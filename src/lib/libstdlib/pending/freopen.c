/*---------------------------------------------------------------------------*/
/* freopen() - reassign a file pointer                                       */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

FILE *freopen(const char *filename, const char *mode, FILE *fp)
{
  FILE *fp1;
  if(close(fp->fd) != -1)
  {
    fp1 = fopen(filename, mode);
    if(fp1 != NULL)
    {
      fp->fd = fp1->fd;
      fp->cnt = fp1->cnt;
      fp->flag = fp1->flag;
      fp->base = fp1->base;
    } else {
      fp->flag |= _ERR;
      fp1 = NULL;
    }
  } else {
    fp1 = NULL;
  }
  return(fp1);
}
