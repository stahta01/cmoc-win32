/*---------------------------------------------------------------------------*/
/* lseek() - Move the file pointer relative to origin                        */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif
#include <io.h>
#include <errno.h>

long lseek(int handle, long offset, int origin)
{
  int rc;
  LSIZE fpos;
  if(handle < _crt_base->_crt_openmax)
  {
    handle = *(_crt_base->_htab_base + handle) - 1;
    if(handle != -1)
    {
      #ifdef _WIN32
        fpos = SetFilePointer(handle, offset, NULL, origin);
        if(fpos == -1)
        {
          rc = (int)GetLastError();
        } else {
          rc = 0;
        }
      #else
        rc = DosChgFilePtr(handle, offset, origin, &fpos);
      #endif
    } else {
      rc = ERROR_INVALID_HANDLE;
    }
  } else {
    rc = ERROR_INVALID_HANDLE;
  }
  if(rc)
  {
    fpos = (unsigned long)-1L;
    _crt_base->_crt_doserrno = rc;
    if(rc == ERROR_INVALID_HANDLE)
    {
      _crt_base->_crt_errno = EBADF;
    } else {
      _crt_base->_crt_errno = EINVAL;
    }
  } else {
    *(_crt_base->_crt_llioflg + handle) &= (~_FEOF_);
  }
  return(fpos);
}
