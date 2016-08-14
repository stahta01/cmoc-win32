/*---------------------------------------------------------------------------*/
/* fread() - read data from a stream                                         */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

size_t fread(void *buffer, size_t size, size_t count, FILE *fp)
{
  int c;
  char *p;
  size_t pos;
  size_t index;
  size_t items = 0;
  p = (char *)buffer;
  for(index = 1; index <= count; index++)
  {
    for(pos = 0; pos < size; pos++)
    {
      if((c = fgetc(fp)) != EOF)
      {
        *p++ = (char)c;
      } else {
        break;
      }
    }
    if(c != EOF)
    {
      items++;
    } else {
      break;
    }
  }
  return(items);
}
