/*---------------------------------------------------------------------------*/
/* puts() - write a string to the standard output stream                     */
/*---------------------------------------------------------------------------*/
#include <io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int puts(const char *string)
{
  int rc;
  rc = write(_STDOUT, (char *)string, (unsigned int)strlen(string));
  if(rc != -1)
  {
    rc = write(_STDOUT, "\n", 1);
  }
  if(rc != -1) rc = 0;
  return(rc);
}
