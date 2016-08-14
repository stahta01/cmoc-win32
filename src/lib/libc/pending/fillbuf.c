/*---------------------------------------------------------------------------*/
/* _fillbuf() - allocate and fill an input buffer                            */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
#include <win32.h>
#else
#include <os2.h>
#endif

#include <io.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int _fillbuf(FILE* fp)
{
  if((fp->flag & (_READ | _EOF | _ERR)) == _READ) {
    if(fp->flag & _UNBUF) {
      fp->size = 1;
    } else {
      if(fp->size == 0) {
        fp->size = _crt_base->_crt_bufsize;
      }
    }
    if(fp->base == NULL) {
      fp->base = (char*)malloc(fp->size);
      if(fp->base == NULL) {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
        return(EOF);
      }
    }
    fp->ptr = fp->base;
    fp->flag |= _ENABLED;
    fp->cnt = read(fp->fd, fp->ptr, fp->size);
    if(--fp->cnt < 0) {
      if(fp->cnt == -1) {
        fp->flag |= _EOF;
      } else {
        fp->flag |= _ERR;
      }
      fp->cnt = 0;
      return(EOF);
    }
    return((unsigned char)(*fp->ptr++));
  } else {
    fp->flag |= _ERR;
    return(EOF);
  }
}
