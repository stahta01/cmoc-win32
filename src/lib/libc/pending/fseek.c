/*---------------------------------------------------------------------------*/
/* fseek() - Move the stream file pointer relative to origin                 */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

int fseek(FILE *fp, long offset, int origin)
{
  if(lseek(fp->fd, offset, origin) != -1L)
  {
    clearerr(fp);
    return(0);
  } else {
    return(EOF);
  }
}
