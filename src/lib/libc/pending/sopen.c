/*---------------------------------------------------------------------------*/
/* sopen() - open a file with sharing                                        */
/*---------------------------------------------------------------------------*/

#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys\stat.h>

int sopen(char *filename, int oflag, int shflag, ...)
{
  int fn;
  int fmode;
  int omode;
  int pmode = 0;
  USIZE handle;
  va_list ap;

  #ifdef _WIN32
    DWORD fdwAccess;
    DWORD fdwShareMode;
    DWORD fdwCreate;
  #else
    USIZE action;
  #endif

  int oflags = O_OPEN;
  int attrib = A_NORMAL;
  int rc = ERROR_TOO_MANY_OPEN_FILES;
  if(oflag & O_CREAT)
  {
    va_start(ap, shflag);
    pmode = va_arg(ap, int);
  }
  for(fn = 0; fn < _crt_base->_crt_openmax; fn++)
  {
    if (!*(_crt_base->_htab_base + fn))
    {
      rc = 0;
      break;
    }
  }
  if(!rc)
  {
    fmode = (oflag & (O_TEXT | O_BINARY));
    if(!fmode)
    {
      fmode = _crt_base->_crt_fmode;
    }
    fmode |= (oflag & O_APPEND);
    omode = (oflag & (O_RDWR | O_WRONLY));
    shflag = (shflag & (SH_DENYRW | SH_DENYWR | SH_DENYRD | SH_DENYNO));
    if(!shflag)
    {
      shflag = SH_DENYNO;
    }
    omode |= shflag;
    pmode = (pmode & (~_crt_base->_crt_umask));
    if(oflag & O_TRUNC)
    {
      oflags = (O_REPL | C_CREAT);
    } else if(oflag & O_CREAT)
    {
      oflags |= C_CREAT;
      if(!(pmode & S_IWRITE))
      {
        attrib = A_RDONLY;
      }
      if(oflag & O_EXCL)
      {
        oflags = C_CREAT;
      }
    }
    #ifdef _WIN32
     if(omode & O_WRONLY) {
       fdwAccess = GENERIC_WRITE;
     } else if(omode & O_RDONLY) {
       fdwAccess = GENERIC_READ;
     } else {
       fdwAccess = (GENERIC_READ | GENERIC_WRITE);
     }
     if(shflag & SH_DENYRW)
     {
       fdwShareMode = 0;
     } else if(shflag & SH_DENYWR) {
       fdwShareMode = FILE_SHARE_READ;
     } else if(shflag & SH_DENYRD) {
       fdwShareMode = FILE_SHARE_WRITE;
     } else {
       fdwShareMode = (FILE_SHARE_READ | FILE_SHARE_WRITE);
     }
     if(oflag & O_TRUNC)
     {
       fdwCreate = CREATE_ALWAYS;
     } else if(oflag & O_CREAT) {
       fdwCreate = OPEN_ALWAYS;
     } else if(oflag & O_EXCL) {
       fdwCreate = CREATE_NEW;
     } else {
       fdwCreate = OPEN_EXISTING;
     }
     handle = CreateFileA(filename,
              fdwAccess,
              fdwShareMode,
              NULL,
              fdwCreate,
              attrib,
              0);
     if(handle == INVALID_HANDLE_VALUE)
     {
       rc = (int)GetLastError();
     } else {
       rc = 0;
     }
    #else
      rc = DosOpen(filename, &handle, &action, 0L, attrib, oflags, omode, 0L);
    #endif
  }
  _crt_base->_crt_doserrno = rc;
  if(!rc)
  {
    *(_crt_base->_htab_base + fn) = handle + 1;
    *(_crt_base->_crt_llioflg + handle) = (_FOPN_ | fmode);
    handle = fn;
    _crt_base->_crt_errno = EZERO;
  } else {
    handle = (unsigned)-1;
    if(rc == ERROR_FILE_NOT_FOUND || rc == ERROR_PATH_NOT_FOUND ||
       (rc == ERROR_OPEN_FAILED && !(oflag & O_EXCL)))
    {
      _crt_base->_crt_errno = ENOENT;
    } else if(rc == ERROR_TOO_MANY_OPEN_FILES)
    {
      _crt_base->_crt_errno = EMFILE;
    } else if(rc == ERROR_NOT_ENOUGH_MEMORY)
    {
      _crt_base->_crt_errno = ENOMEM;
    } else if(rc == ERROR_INVALID_ACCESS || rc == ERROR_INVALID_PARAMETER)
    {
      _crt_base->_crt_errno = EINVAL;
    } else if(rc == ERROR_OPEN_FAILED)
    {
      _crt_base->_crt_errno = EEXIST;
    } else {
      _crt_base->_crt_errno = EACCES;
    }
  }
  return(handle);
}
