/*---------------------------------------------------------------------------*/
/* dup2() - reassign a file handle                                           */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
#include <win32.h>
#else
 #include <os2.h>
#endif
#include <io.h>
#include <errno.h>

int dup2(int handle1, int handle2)
{
  int rc;
  USIZE hdup = handle2;
  if(handle1 < _crt_base->_crt_openmax)
  {
    handle1 = *(_crt_base->_htab_base + handle1) - 1;
    if(handle1 != -1)
    {
      #ifdef _WIN32
        rc = DuplicateHandle(GetCurrentProcess(),
                             handle1,
                             GetCurrentProcess(),
                             &hdup,
                             0,
                             1,
                             DUPLICATE_SAME_ACCESS);
        if(rc)
        {
          rc = 0;
        } else {
          rc = (int)GetLastError();
        }
      #else
        rc = DosDupHandle(handle1, &hdup);
      #endif
    } else {
      rc = ERROR_INVALID_HANDLE;
    }
  } else {
    rc = ERROR_INVALID_HANDLE;
  }
  if(rc)
  {
    hdup = (unsigned)-1;
    _crt_base->_crt_doserrno = rc;
    if(rc == ERROR_TOO_MANY_OPEN_FILES)
    {
      _crt_base->_crt_errno = EMFILE;
    } else {
      _crt_base->_crt_errno = EBADF;
    }
  } else {
    *(_crt_base->_htab_base + hdup) = hdup + 1;
  }
  return(hdup);
}
