/*---------------------------------------------------------------------------*/
/* rewind() - reposition the file pointer to the beginning of the file       */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

void rewind(FILE *fp)
{
  fseek(fp, 0L, SEEK_SET);
}
