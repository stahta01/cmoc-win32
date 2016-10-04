
/*---------------------------------------------------------------------------*/
/* setvbuf() - set stream buffering and buffer size                          */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

int setvbuf(FILE *fp, char *buffer, int mode, size_t size)
{
  int flag = 0;
  if(fp->flag & (_READ | _WRITE))
  {
    if(mode == _IONBF)
    {
      fp->flag |= _UNBUF;
    } else if((mode == _IOLBF) | (mode == _IOFBF)) {
      if((size > 0) && (size <= 32767))
      {
        fp->size = size;
        fp->base = buffer;
      } else {
        flag = EOF;
       }
    } else {
      flag = EOF;
     }
   } else {
      flag = EOF;
   }
   return(flag);
}
