/*---------------------------------------------------------------------------*/
/*  getenv() - get a pointer to an environment variable                      */
/*---------------------------------------------------------------------------*/
#include <win32.h>
#include <errno.h>
#include <stdlib.h>

#define _ENVAR_BUFSIZ     256

char *getenv(const char *varname)
{
  DWORD varlen;
  char *varptr = NULL;
  if(_crt_base->_envar_buflen == 0)
  {
     _crt_base->_envar_buffer = malloc(_ENVAR_BUFSIZ);
     if(_crt_base->_envar_buffer == NULL)
     {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
        return(NULL);
     }
     _crt_base->_envar_buflen = _ENVAR_BUFSIZ;
  }
  varlen = GetEnvironmentVariableA(varname,
                                   _crt_base->_envar_buffer,
                                   _crt_base->_envar_buflen - 1);

  if((int)varlen > (_crt_base->_envar_buflen - 1))
  {
     _crt_base->_envar_buffer = realloc(_crt_base->_envar_buffer, varlen + 1);
     if(_crt_base->_envar_buffer == NULL)
     {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
        return(NULL);
     }
     _crt_base->_envar_buflen = varlen;

     varlen = GetEnvironmentVariableA(varname,
                                      _crt_base->_envar_buffer,
                                      varlen);
  }
  if(varlen)
  {
    varptr = _crt_base->_envar_buffer;
  }
  return(varptr);
}
