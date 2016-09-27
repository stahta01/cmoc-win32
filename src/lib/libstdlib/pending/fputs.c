/*---------------------------------------------------------------------------*/
/* fputs() - write a string to a stream                                      */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>
#include <string.h>

int fputs(const char *string, FILE *fp)
{
  int num, slen;
  slen = strlen(string);
  num = fwrite((char *)string, sizeof(char), slen, fp);
  if(num != slen)
  {
    return(EOF);
  } else {
    return(num);
  }
}
