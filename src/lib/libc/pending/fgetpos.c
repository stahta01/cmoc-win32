/*---------------------------------------------------------------------------*/
/* fgetpos() - get the current stream file position                          */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

int fgetpos(FILE *fp, fpos_t *pos)
{
  long fpos;
  fpos = ftell(fp);
  if(fpos != -1L)
  {
    *pos = fpos;
    return(0);
  } else {
    return(EOF);
  }
}
