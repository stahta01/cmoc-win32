/*---------------------------------------------------------------------------*/
/* remove() - delete a file                                                  */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <io.h>
#include <errno.h>

int remove(char *filename)
{
  int rc;
  int flag = 0;
  #ifdef _WIN32
    rc = DeleteFileA(filename);
    if(rc)
    {
      rc = 0;
    } else {
      rc = (int)GetLastError();
    }
  #else
    rc = DosKill(filename);
  #endif
  if(rc)
  {
    flag = -1;
    _crt_base->_crt_doserrno = rc;
    if(rc == ERROR_FILE_NOT_FOUND || rc == ERROR_PATH_NOT_FOUND)
    {
      _crt_base->_crt_errno = ENOENT;
    } else {
      _crt_base->_crt_errno = EACCES;
    }
  }
  return(flag);
}
