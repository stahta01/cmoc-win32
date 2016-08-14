/*---------------------------------------------------------------------------*/
/* unlink() - unlink (delete) a file                                         */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

int unlink(const char *filename)
{
  return(remove(filename));
}
