/*---------------------------------------------------------------------------*/
/* fcloseall() - close all files opened for stream i/o.                      */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

int fcloseall(void)
{
  FILE *fp;
  int fd;
  int count = 0;
  for(fd = _STDIN; fd < _crt_base->_crt_openmax; fd++)
  {
    fp = (FILE *) _iob + fd;
    if(fp->flag & (_READ | _WRITE))
    {
      fflush(fp);
      close(fd);
      count++;
    }
  }
  return(count);
}
