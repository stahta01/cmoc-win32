/*---------------------------------------------------------------------------*/
/* system() - execute an operating system command                            */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <crt.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int system(const char *command)
{
  unsigned int rc = 0;
  char *comptr, *cmdbuf;

  #ifdef _WIN32
    struct STARTUPINFOA StartInfo;
    struct PROCESS_INFORMATION ProcInfo;
  #else
    struct RESULTCODES ReturnCodes;
  #endif

  comptr = getenv("COMSPEC");
  if(comptr != NULL)
  {
    if(command != NULL)
    {
      cmdbuf = calloc(strlen(comptr) + strlen(command) + 6, 1);
      if(cmdbuf != NULL)
      {
        #ifdef _WIN32
          strcpy(cmdbuf, comptr);
          strcat(cmdbuf, " /c ");
          strcat(cmdbuf, command);
          StartInfo.cb = sizeof(struct STARTUPINFOA);
          StartInfo.lpReserved = NULL;
          StartInfo.lpReserved2 = NULL;
          StartInfo.lpReserved2 = NULL;
          StartInfo.cbReserved2 = 0;
          StartInfo.lpDesktop = NULL;
          StartInfo.dwFlags = 0;

          rc = CreateProcessA(NULL,
                              (char *)cmdbuf,
                              NULL,
                              NULL,
                              1,
                              0,
                              NULL,
                              NULL,
                              &StartInfo,
                              &ProcInfo);
          if(rc)
          {
            rc = 0;
            WaitForSingleObject(ProcInfo.hProcess, INFINITE);
          } else {
            rc = (int)GetLastError();
          }
        #else
          strcpy(cmdbuf, comptr);
          strcpy(cmdbuf + strlen(comptr) + 1, "/c ");
          strcpy(cmdbuf + strlen(comptr) + 4, command);

          rc = DosExecPgm(NULL,
                          0,
                          0,
                          cmdbuf,
                          NULL,
                          &ReturnCodes,
                          cmdbuf);
       #endif
       if(!rc)
       {
         #ifdef _WIN32
           GetExitCodeProcess(ProcInfo.hProcess, (LPDWORD)&rc);
         #else
           rc = ReturnCodes.codeResult;
         #endif
       } else {
         if(rc == ERROR_FILE_NOT_FOUND || rc == ERROR_PATH_NOT_FOUND)
         {
           _crt_base->_crt_errno = ENOENT;
         } else if(rc == ERROR_TOO_MANY_OPEN_FILES)
         {
           _crt_base->_crt_errno = EMFILE;
         } else if(rc == ERROR_NOT_ENOUGH_MEMORY)
         {
           _crt_base->_crt_errno = ENOMEM;
         } else if(rc == ERROR_ACCESS_DENIED || rc == ERROR_SHARING_VIOLATION)
         {
           _crt_base->_crt_errno = EACCES;
         } else {
           _crt_base->_crt_errno = ENOEXEC;
         }
        _crt_base->_crt_doserrno = rc;
        rc = (unsigned)-1;
       }
      } else {
        rc = (unsigned)-1;
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
      }
    } else {
      rc = 1;
    }
  } else {
    if(command != NULL) rc = (unsigned)-1;
    _crt_base->_crt_errno = ENOENT;
    _crt_base->_crt_doserrno = ERROR_FILE_NOT_FOUND;
  }
  return(rc);
}
