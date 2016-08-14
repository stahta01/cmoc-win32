/*---------------------------------------------------------------------------*/
/* _flushbuf() - allocate and flush an output buffer                         */
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

int _flushbuf(int c, FILE *fp)
{
  if((fp->flag & (_WRITE | _EOF | _ERR)) == _WRITE)
  {
    if(fp->flag & _UNBUF)
    {
      fp->size = 1;
      if(write(fp->fd, &c, fp->size) != fp->size)
      {
        fp->flag |= _ERR;
        return(EOF);
      }
    } else {
      if(fp->size == 0)
      {
        fp->size = _crt_base->_crt_bufsize;
      }
    }
    if(fp->base == NULL)
    {
      fp->base = (char *)malloc(fp->size);
      if(fp->base == NULL)
      {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
        return(EOF);
      }
    } else {
      if((fp->flag & _ENABLED) && !(fp->flag & _UNBUF))
      {
        if(write(fp->fd, fp->base, fp->size) != fp->size)
        {
          fp->flag |= _ERR;
          return(EOF);
        }
      }
    }
    fp->ptr = fp->base;
    *fp->ptr++ = (char)c;
    fp->cnt = fp->size - 1;
    fp->flag |= _ENABLED;
    return(c);
  } else {
    fp->flag |= _ERR;
    return(EOF);
  }
}
