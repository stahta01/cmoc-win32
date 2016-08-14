/*---------------------------------------------------------------------------*/
/* fopen() - open a file for stream i/o                                      */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <share.h>

FILE *fopen(const char *filename, const char *mode)
{
  return(_fsopen(filename, mode, SH_DENYNO));
}
