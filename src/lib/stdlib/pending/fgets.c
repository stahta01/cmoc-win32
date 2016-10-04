/*---------------------------------------------------------------------------*/
/* fgets() - get a string from a stream                                      */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

char *fgets(char *string, int count, FILE *fp)
{
  int c;
  int bytes;
  int num = 0;
  char *p = string;
  if(count > 1)
  {
    for(bytes = 1; bytes < count; bytes++)
    {
      if((c = fgetc(fp)) != EOF)
      {
        *p++ = (char)c;
        num++;
        if((char)c == '\n')
        {
          break;
        }
      } else {
        break;
      }
    }
    if((fp->flag & _ERR) != _ERR)
    {
      if(num > 0)
      {
        fp->flag &= ~_EOF;
      } else {
        return(NULL);
      }
    } else {
      return(NULL);
    }
  }
  *p = '\0';
  return(string);
}
