/*---------------------------------------------------------------------------*/
/* open() - open a file                                                      */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <share.h>
#include <fcntl.h>
#include <stdarg.h>

int open(char *filename, int oflag, ...)
{
  int pmode = 0;
  va_list ap;

  if(oflag & O_CREAT)
  {
    va_start(ap, oflag);
    pmode = va_arg(ap, int);
  }
  return(sopen(filename, oflag, SH_DENYNO, pmode));
}
