/*---------------------------------------------------------------------------*/
/* fclose() - close a file opened for stream i/o                             */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

int fclose(FILE *fp)
{
  int flag;
  flag = fflush(fp);
  if(!flag)
  {
    flag = close(fp->fd);
    if(!flag)
    {
      fp->cnt = 0;
      fp->flag = 0;
      fp->size = 0;
	  /* * *
	   *  fix: fp->base was not being free'd when a stream was closed
	   *       instead it was being set to NULL which created a leak.
	   *       fixed by R. Scudder on 06/12/1999
	   * * */
	  if(fp->base)
	  	free(fp->base);
	  fp->base = NULL;
    } else {
      fp->flag |= _ERR;
    }
  }
  return(flag);
}
