/*---------------------------------------------------------------------------*/
/* flushall() - flush all stream i/o buffers                                 */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

int flushall(void)
{
  FILE *fp;
  int fd;
  int count = 0;
  for(fd = 0; fd < _crt_base->_crt_openmax; fd++)
  {
    fp = (FILE *) _iob + fd;
    if(fp->flag & (_READ | _WRITE))
    {
      fflush(fp);
      count++;
    }
  }
  return(count);
}
