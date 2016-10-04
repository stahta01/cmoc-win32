/*---------------------------------------------------------------------------*/
/* perror() - print a user defined string and error message                  */
/*---------------------------------------------------------------------------*/
#include <errno.h>
#include <stdio.h>
#include <string.h>

void perror(const char *string)
{
  fprintf(stderr, "%s: %s\n", string, strerror(errno));
}
