/*---------------------------------------------------------------------------*/
/* fgetc() - get a character for a file opened for stream i/o                */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

int fgetc(FILE *fp)
{
  int c;
  if(--fp->cnt >= 0)
  {
    c = (int)*fp->ptr++;
  } else {
    c = _fillbuf(fp);
  }
  return(c);
}
