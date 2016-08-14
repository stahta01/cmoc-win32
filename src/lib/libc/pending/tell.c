/*---------------------------------------------------------------------------*/
/* tell() - get the current position of the file pointer                     */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

long tell(int handle)
{
  return(lseek(handle, 0L, SEEK_CUR));
}
