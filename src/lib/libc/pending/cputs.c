/*---------------------------------------------------------------------------*/
/* cputs() - write a string directly to the console                          */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <stdio.h>
#include <string.h>

int cputs(const char *string)
{
  int rc = 0;
  USIZE slen;
  USIZE bytes = 0;
  slen = strlen(string);
  if(slen)
  {
    #ifdef _WIN32
      rc = WriteFile(GetStdHandle(STD_OUTPUT_HANDLE),
                     (void *)string, slen, &bytes, NULL);
      if(rc)
      {
        rc = 0;
      } else {
        rc = (int)GetLastError();
      }
    #else
      rc = DosWrite(_STDIN, (void *)string, slen, &bytes);
    #endif
  }
  if((rc) || (bytes != slen))
  {
    return(EOF);
  } else {
    return(0);
  }
}
