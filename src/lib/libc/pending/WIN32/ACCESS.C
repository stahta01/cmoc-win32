/*---------------------------------------------------------------------------*/
/* acccess() - get file access permission                                    */
/*---------------------------------------------------------------------------*/
#include <win32.h>
#include <crt.h>
#include <errno.h>

int access(char *pathname, int mode)
{
  int rc;
  int amode = -1;

  rc = GetFileAttributesA(pathname);

  if(rc == -1)
  {
    rc = GetLastError();
    _crt_base->_crt_errno = ENOENT;
    _crt_base->_crt_doserrno = rc;
  } else {
    switch(mode)
    {
      case 0:
      case 4:
        amode = 0;
        break;

      case 2:
      case 6:
        if(rc & FILE_ATTRIBUTE_READONLY)
        {
          _crt_base->_crt_errno = EACCES;
          _crt_base->_crt_doserrno = ERROR_ACCESS_DENIED;
        } else {
          amode = 0;
        }
        break;

      default:
        _crt_base->_crt_errno = EINVAL;
        _crt_base->_crt_doserrno = ERROR_INVALID_PARAMETER;
    }
  }
  return(amode);
}
