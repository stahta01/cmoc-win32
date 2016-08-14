/*---------------------------------------------------------------------------*/
/* _cstart() - Initialize the C runtime environment and start a C program    */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <crt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if(defined(_WIN32) || defined(API32))
  #include <except.h>
#endif

typedef void (*PFV) (void);

int _cinit(void);
void main(int argc, char *argv[]);

void _cstart(void)
{
  int rc;
  int cmdlen;
  int argc = 0;
  int index = 1;
  char **argv;
  char *cmdptr, *cmdbuf;
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
        main(argc, &(*argv));
		/* * *
		 *  fix: atexit function stack code moved into the exit() function
		 *       so that it will be executed when a program is terminated with
		 *       a call to exit as per the ANSI standard spec - Roger Scudder 05/24/99
		 *       Note: closeall function call also moved to exit() function.
		 * * */
	  } else {
        rc = ERROR_NOT_ENOUGH_MEMORY;
      }
  }
  exit(rc);
}
