/*---------------------------------------------------------------------------*/
/* gets() - get a string from a stdin                                        */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

char *gets(char *buffer)
{
  int c;
  int num = 0;
  FILE *fp = stdin;
  char *p = buffer;
  while((c = fgetc(fp)) != EOF)
  {
    *p = (char)c;
    num++;
    if((char)c == '\n')
    {
      break;
    }
    p++;
  }
  if((fp->flag & _ERR) != _ERR)
  {
    if(num == 0)
    {
      return(NULL);
    }
  } else {
    return(NULL);
  }
  *p = '\0';
  return(buffer);
}
