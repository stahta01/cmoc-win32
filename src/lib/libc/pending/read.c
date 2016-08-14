/*---------------------------------------------------------------------------*/
/* read() - read data from a file                                            */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif
#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int read(int handle, void *buffer, unsigned int count)
{
  int rc;
  USIZE pos;
  USIZE bytes;
  char *p;
  if(handle < _crt_base->_crt_openmax)
  {
    handle = *(_crt_base->_htab_base + handle) - 1;
    if(handle != -1)
    {
      if((*(_crt_base->_crt_llioflg + handle)) & _FEOF_)
      {
        rc = 0;
        bytes = 0;
      } else {

        #ifdef _WIN32
          rc = ReadFile(handle, buffer, count, &bytes, NULL);
          if(rc)
          {
            rc = 0;
          } else {
            rc = (int)GetLastError();
          }
        #else
          rc = DosRead(handle, buffer, count, &bytes);
        #endif
      }
    } else {
      rc = ERROR_INVALID_HANDLE;
    }
  } else {
    rc = ERROR_INVALID_HANDLE;
  }
  _crt_base->_crt_doserrno = rc;
  if(rc)
  {
    bytes = (unsigned)-1;
    _crt_base->_crt_errno = EBADF;
  } else {
    if(!bytes)
    {
      *(_crt_base->_crt_llioflg + handle) |= _FEOF_;
    } else if(!((*(_crt_base->_crt_llioflg + handle)) & O_BINARY)) {
      pos = 0;
      p = (char *)buffer;
      while(pos < bytes)
      {
        if(*p == _EOF_)
        {
          *(_crt_base->_crt_llioflg + handle) |= _FEOF_;
          bytes = pos;
          break;
        }
        p++;
        pos++;
      }
      if(bytes > 1)
      {
        p = (char *)buffer;
        for(pos = 1; pos < bytes; pos++)
        {
          if(*p == _CR_ && (*(p + 1) == _LF_))
          {
            memcpy(p, p + 1, (bytes - pos));
            *p = '\n';
            bytes--;
          }
          p++;
        }
      }
    }
  }
  return(bytes);
}
