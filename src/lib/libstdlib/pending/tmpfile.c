/*---------------------------------------------------------------------------*/
/* tmpfile() - create a unique temporary file                                */
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys\stat.h>

FILE *tmpfile(void)
{
  FILE *fp;
  int fn;
  int fd = 0;
  int fail = 1;
  int found = 0;
  char *tmpptr;
  char *filename;
  fp = (FILE *)_iob;
  for(fn = 1; fn <= _crt_base->_crt_openmax; fn++)
  {
    if(!fp->flag)
    {
      fail = 0;
      break;
    }
    fp++;
  }
  if(fail)
  {
    fp = NULL;
    _crt_base->_crt_errno = EMFILE;
    _crt_base->_crt_doserrno = ERROR_TOO_MANY_OPEN_FILES;
  } else {
    while(!found)
    {
      filename = _tmpnam(NULL);
      if(filename != NULL)
      {
        fd = sopen(filename, O_CREAT | O_EXCL, SH_DENYRW, S_IREAD | S_IWRITE);
        if(fd != -1)
        {
          found = 1;
          tmpptr = malloc(strlen(filename) + 1);
          if(tmpptr != NULL)
          {
            fp->fd = fd;
            fp->cnt = 0;
            fp->flag = _READ | _WRITE;
            fp->base = NULL;
            strcpy(tmpptr, filename);
            *(_crt_base->_tmpnam_base + fd) = (long)tmpptr;
          } else {
            fp = NULL;
            _crt_base->_crt_errno = ENOMEM;
            _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
          }
        } else {
          if(errno != EEXIST)
          {
            fp = NULL;
            found = 1;
          }
        }
      } else {
        fp = NULL;
        found = 1;
      }
    }
  }
  return(fp);
}
