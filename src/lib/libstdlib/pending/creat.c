/*---------------------------------------------------------------------------*/
/* creat() - create a file                                                   */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <fcntl.h>
#include <share.h>

int creat(char *filename, int pmode)
{
  return(sopen(filename, O_CREAT | O_TRUNC, SH_DENYNO, pmode));
}
