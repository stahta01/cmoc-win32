/*---------------------------------------------------------------------------*/
/* close() - close a file                                                    */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <io.h>
#include <errno.h>

int close(int handle)
{
  int rc;
  int flag = 0;
  if(handle < _crt_base->_crt_openmax)
  {
    handle = *(_crt_base->_htab_base + handle) - 1;
    if(handle != -1)
    {
      #ifdef _WIN32
        rc = CloseHandle(handle);
        if(rc)
        {
          if(*(_crt_base->_tmpnam_base + handle) && !rc)
            DeleteFileA((char *)*(_crt_base->_tmpnam_base + handle));
          rc = 0;
        } else {
          rc = (int)GetLastError();
        }
      #else
        rc = DosClose(handle);
        if(*(_crt_base->_tmpnam_base + handle) && !rc)
          DosKill((char *)*(_crt_base->_tmpnam_base + handle));
      #endif
    } else {
      rc = ERROR_INVALID_HANDLE;
    }
  } else {
    rc = ERROR_INVALID_HANDLE;
  }
  if(!rc)
  {
    *(_crt_base->_htab_base + handle) = 0;
  } else {
    flag = -1;
    _crt_base->_crt_doserrno = rc;
    _crt_base->_crt_errno = EBADF;
  }
  return(flag);
}
