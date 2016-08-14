/*---------------------------------------------------------------------------*/
/* fputc() - put a character to a file opened for stream i/o                 */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

int fputc(int c, FILE *fp)
{
  if(--fp->cnt >= 0)
  {
    c = (int)(*fp->ptr++ = (char)(c));
  } else {
    c = _flushbuf(c, fp);
  }
  return(c);
}
