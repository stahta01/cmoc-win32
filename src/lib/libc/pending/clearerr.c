/*---------------------------------------------------------------------------*/
/* clearerr() - clear error and end of file flags for a stream               */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

void clearerr(FILE *fp)
{
  /* * *
   *  fix: flags were OR'd which caused failure to effect flag state
   *        change to AND fixed the problem -- R. Scudder on 01/05/1999
   * * */
  fp->flag &= (~_ERR & ~_EOF);
}
