/*---------------------------------------------------------------------------*/
/* _dllstart() - Initialize the C runtime environment for a DLL              */
/*---------------------------------------------------------------------------*/
#include <win32.h>

#include <crt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <except.h>

typedef void (*PFV) (void);

int _cinit(void);

void _dllstart(void)
{
  int rc;
  int cmdlen;
  int argc = 0;
  int index = 1;
  char **argv;
  char *cmdptr, *cmdbuf;
  unsigned long *exitptr;
  #ifdef _WIN32
    REGISTRATION_RECORD RegRec;
  #elif API32
    ULONG ulTimes;
    SYSREGREC RegRec;
  #endif
  rc = _cinit();
  if(!rc)
  {
    cmdptr = _getcmd();
    cmdbuf = cmdptr;
    #ifdef _WIN32
      cmdlen = strlen(cmdbuf);
      cmdbuf = calloc(cmdlen + 1, 1);
      if(cmdbuf)
      {
        memcpy(cmdbuf, cmdptr, cmdlen);
        cmdbuf = cmdptr;
    #else
      argc = 1;
      cmdlen = strlen(cmdbuf) + 1;
      cmdbuf += (strlen(cmdbuf) + 1);
      cmdlen += strlen(cmdbuf);
      cmdbuf = calloc(cmdlen + 1, 1);
      if(cmdbuf)
      {
        memcpy(cmdbuf, cmdptr, cmdlen);
        cmdptr = cmdbuf + (strlen(cmdbuf) + 1);
    #endif
        cmdptr = strtok(cmdptr, " \t\n");
        while(cmdptr != NULL)
        {
        cmdptr = strtok(NULL, " \t\n");
        argc++;
        }
        argv = calloc(sizeof(char *), argc);
        *argv = cmdbuf;
        cmdbuf += (strlen(cmdbuf) + 1);
        while(index < argc)
        {
          while((*cmdbuf == ' ') || (*cmdbuf == '\t') || (*cmdbuf == '\n'))
            cmdbuf++;
          *(argv + index) = cmdbuf;
          cmdbuf += (strlen(cmdbuf) + 1);
          index++;
        }
        #ifdef _WIN32
          RegRec.pExceptionHandler = _seh;
          _SetExceptionHandler(&RegRec);
          SetConsoleCtrlHandler(_ceh, 1);
        #elif API32
          RegRec.pLink = 0;
          RegRec.pSysEH = __seh;
          DosSetExceptionHandler((PEXCEPTIONREGISTRATIONRECORD) &RegRec);
          DosSetSignalExceptionFocus(SIG_SETFOCUS, &ulTimes);
    #endif
      }
  }
}
