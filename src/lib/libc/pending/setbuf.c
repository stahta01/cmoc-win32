
/*---------------------------------------------------------------------------*/
/* setbuf() - set user stream buffer                                         */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

void setbuf(FILE *fp, char *buffer)
{
  int flag = 0;
  if(fp->flag & (_READ | _WRITE))
  {
    if(buffer == NULL)
    {
      fp->flag |= _UNBUF;
    } else {
      fp->base = buffer;
    }
  }
}
