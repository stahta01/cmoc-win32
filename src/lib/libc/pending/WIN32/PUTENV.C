/*---------------------------------------------------------------------------*/
/*  putenv() - add or update an environment variable                         */
/*---------------------------------------------------------------------------*/
#include <win32.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int putenv(const char *envstring)
{
  int index;
  int varlen;
  int rc = -1;
  int namelen = 0;
  LPSTR lpszName;
  LPSTR lpszValue;
  varlen = strlen(envstring);
  if(varlen)
  {
    for(index = 0; index < varlen; index++)
    {
      if(*(envstring + index) == '=')
      {
        namelen = index;
        break;
      }
    }
    if(namelen)
    {
      lpszName = calloc(namelen + 1, 1);
      if(lpszName == NULL)
      {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
      } else {
        strncpy(lpszName, envstring, namelen);
        lpszValue = (char *)(envstring + namelen + 1);
        rc = SetEnvironmentVariableA(lpszName, lpszValue);
        if(rc)
        {
          rc = 0;
        } else {
          _crt_base->_crt_errno = EINVAL;
          _crt_base->_crt_doserrno = GetLastError();
        }
      }
    } else {
      _crt_base->_crt_errno = EINVAL;
      _crt_base->_crt_doserrno = 0;
    }
  } else {
    _crt_base->_crt_errno = EINVAL;
    _crt_base->_crt_doserrno = 0;
  }
  return(rc);
}
