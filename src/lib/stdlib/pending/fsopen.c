/*---------------------------------------------------------------------------*/
/* _fsopen() - open a file for stream i/o with sharing                       */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <share.h>
#include <sys\stat.h>

FILE *_fsopen(const char *filename, const char *mode, int shflag)
{
  FILE *fp;
  int fn;
  int flag;
  int oflag;
  int fd = 0;
  int fail = 1;
  int pmode = 0;
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
    if(strlen(mode) == 1)
    {
      if(!strcmp(mode, "r"))
      {
        flag= _READ;
        oflag = O_RDONLY;
      } else if(!strcmp(mode, "w"))
      {
        flag= _WRITE;
        oflag = O_WRONLY | O_TRUNC;
      } else if(!strcmp(mode, "a"))
      {
        flag= _WRITE;
        pmode = S_IWRITE;
        oflag = O_CREAT | O_APPEND | O_WRONLY;
      } else {
        fail++;
      }
    } else if(strlen(mode) == 2)
    {
      if(!strcmp(mode, "r+"))
      {
        flag= _READ | _WRITE;
        oflag = O_RDWR;
      } else if(!strcmp(mode, "w+"))
      {
        flag= _READ | _WRITE;
        oflag = O_RDWR | O_TRUNC;
      } else if(!strcmp(mode, "a+"))
      {
        flag= _READ | _WRITE;
        pmode = S_IREAD | S_IWRITE;
        oflag = O_CREAT | O_APPEND | O_RDWR;
      } else if(!strcmp(mode, "rb"))
      {
        flag= _READ;
        oflag = O_RDONLY | O_BINARY;
      } else if(!strcmp(mode, "rt"))
      {
        flag= _READ;
        oflag = O_RDONLY | O_TEXT;
      } else if(!strcmp(mode, "wb"))
      {
        flag= _WRITE;
        oflag = O_WRONLY | O_BINARY | O_TRUNC;
      } else if(!strcmp(mode, "wt"))
      {
        flag= _WRITE;
        oflag = O_WRONLY | O_TEXT | O_TRUNC;
      } else if(!strcmp(mode, "ab"))
      {
        flag= _WRITE;
        pmode = S_IWRITE;
        oflag = O_CREAT | O_APPEND | O_WRONLY | O_BINARY;
      } else if(!strcmp(mode, "at"))
      {
        flag= _WRITE;
        pmode = S_IWRITE;
        oflag = O_CREAT | O_APPEND | O_WRONLY | O_TEXT;
      } else {
        fail++;
      }
    } else if(strlen(mode) == 3)
    {
      if(!strcmp(mode, "rb+") || !strcmp(mode, "r+b"))
      {
        flag= _READ | _WRITE;
        oflag = O_RDWR | O_BINARY;
      } else if(!strcmp(mode, "rt+") || !strcmp(mode, "r+t"))
      {
        flag= _READ | _WRITE;
        oflag = O_RDWR | O_TEXT;
      } else if(!strcmp(mode, "wb+") || !strcmp(mode, "w+b"))
      {
        flag= _READ | _WRITE;
        oflag = O_RDWR | O_TRUNC | O_BINARY;
      } else if(!strcmp(mode, "wt+") || !strcmp(mode, "w+t"))
      {
        flag= _READ | _WRITE;
        oflag = O_RDWR | O_TRUNC | O_TEXT;
      } else if(!strcmp(mode, "ab+") || !strcmp(mode, "a+b"))
      {
        flag= _READ | _WRITE;
        pmode = S_IREAD | S_IWRITE;
        oflag = O_CREAT | O_APPEND | O_RDWR | O_BINARY;
      } else if(!strcmp(mode, "at+") || !strcmp(mode, "a+t"))
      {
        flag= _READ | _WRITE;
        pmode = S_IREAD | S_IWRITE;
        oflag = O_CREAT | O_APPEND | O_RDWR | O_TEXT;
      } else {
        fail++;
      }
    } else {
      fail++;
    }
    if(!fail)
    {
      if(shflag != -1)
      {
        fd = sopen((char *)filename, oflag, shflag, pmode);
      }
      if(fd != -1)
      {
        fp->fd = fd;
        fp->cnt = 0;
        fp->flag = flag;
        fp->base = NULL;
      } else {
        fp = NULL;
      }
    } else {
      fp = NULL;
      _crt_base->_crt_errno = EINVAL;
      _crt_base->_crt_doserrno = ERROR_INVALID_PARAMETER;
    }
  }
  return(fp);
}
