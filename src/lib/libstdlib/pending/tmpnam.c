/*---------------------------------------------------------------------------*/
/* tmpnam() - create a unique temporary filename                             */
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
#include <stdlib.h>
#include <string.h>
#include <sys\stat.h>

char *tmpnam(char *string)
{
  char *name;
  int handle;
  int found = 0;
  while(!found)
  {
    name = _tmpnam(string);
    if(name != NULL)
    {
      handle = open(name, O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
      if(handle != -1)
      {
        found = 1;
        close(handle);
        remove(name);
      } else if(errno != EEXIST) {
        found = 1;
        name = NULL;
      }
    }
  }
  return(name);
}

/*---------------------------------------------------------------------------*/
/* _tmpnam() - create a unique temporary filename string                     */
/*---------------------------------------------------------------------------*/
char *_tmpnam(char *string)
{
  char *name;
  char *tmpdir;
  char *cmdptr = NULL;
  unsigned int rc = 0;
  struct DATETIME dt;

  #ifdef _WIN32
    GetLocalTime(&dt);
    dt.hundredths /= 10;
  #else
    rc = DosGetDateTime(&dt);
  #endif

  if(!rc)
  {
    if(string != NULL)
    {
      name = string;
    } else {
      if(_crt_base->_tmpnam_ptr == NULL)
        _crt_base->_tmpnam_ptr = malloc(L_tmpnam);
      if(_crt_base->_tmpnam_ptr != NULL)
      {
        name = _crt_base->_tmpnam_ptr;
      } else {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
      }
    }
    if(name != NULL)
    {
      *name = '\0';
      tmpdir = getenv("TMP");
      if(tmpdir != NULL)
      {
        strcpy(name, tmpdir);
        if(*(tmpdir + strlen(tmpdir) - 1) != '\\')
          strcat(name, "\\");
      }
      sprintf(name + strlen(name), "%2.2X%2.2X%2.2X%2.2X",
               (unsigned int)dt.hours,
               (unsigned int)dt.minutes,
               (unsigned int)dt.seconds,
               (unsigned int)dt.hundredths);

      strcat(name, ".TMP");
    }
  } else {
    name = NULL;
  }
  return(name);
}
