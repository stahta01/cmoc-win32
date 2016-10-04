/*---------------------------------------------------------------------------*/
/* ungetc() - push a character back onto a stream                            */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

int ungetc(int c, FILE *fp)
{
 if((fp->flag & _ENABLED) && (fp->ptr != fp->base))
 {
   fp->cnt++;
   *(--fp->ptr) = (char)c;
   fp->flag &= ((~_EOF) & (~_ERR));
 } else {
   c = EOF;
 }
 return(c);
}
