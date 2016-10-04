/*---------------------------------------------------------------------------*/
/* eof() - Test for end of file                                              */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif
#include <io.h>
#include <errno.h>

int eof(int handle)
{
  int flag = 0;
  if(handle < _crt_base->_crt_openmax)
  {
    handle = *(_crt_base->_htab_base + handle) - 1;
    if(handle != -1)
    {
      if((*(_crt_base->_crt_llioflg + handle)) & _FOPN_)
      {
        flag = (((*(_crt_base->_crt_llioflg + handle)) & _FEOF_) != 0);
      } else {
        flag = -1;
      }
    } else {
      flag = -1;
    }
  } else {
    flag = -1;
  }
  if(flag == -1)
  {
    _crt_base->_crt_errno = EBADF;
    _crt_base->_crt_doserrno = ERROR_INVALID_HANDLE;
  }
  return(flag);
}
