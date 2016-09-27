/*---------------------------------------------------------------------------*/
/* _assert() - assert expression                                             */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <process.h>

void _assert(char *exp, void *file, unsigned int line)
{
  fprintf(stderr,
          "Assertion failed: %s, file %s, line %u\n", exp, file, line);
  abort();
}
