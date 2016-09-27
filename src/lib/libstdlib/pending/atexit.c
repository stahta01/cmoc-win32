/*---------------------------------------------------------------------------*/
/* atexit() - register a function for execution at exit                      */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <crt.h>
#include <errno.h>

int atexit(void(*func)(void))
{
  int rc = 0;
  unsigned long *exitptr;
  if(_crt_base->_exit_list < _MAX_EXIT_)
  {
    exitptr = (unsigned long *)_crt_base->_exit_base;
    *(exitptr + _crt_base->_exit_list) = (unsigned long)func;
    _crt_base->_exit_list++;
  } else {
    rc = -1;
   _crt_base->_crt_errno = ENOMEM;
   _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
  }
  return(rc);
}
