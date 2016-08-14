/*---------------------------------------------------------------------------*/
/* ftell() - get the current position of the stream file pointer             */
/*           Modified on 05/20/99 by Roger Scudder to return the bytes       */
/*           read by the user instead of bytes actually read into the        */
/*           internal buffer by the MS ReadFile function                     */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>

long ftell(FILE *fp)
{
	/* * *
	 * fix: Modified on 05/20/99 by Roger Scudder to return the bytes
	 *      read by the user instead of bytes actually read into the
	 *      internal buffer by the MS ReadFile function which caused
	 *      a constant EOF condition
	 * * */

	return(lseek(fp->fd, 0L, SEEK_CUR) - fp->cnt);
}
