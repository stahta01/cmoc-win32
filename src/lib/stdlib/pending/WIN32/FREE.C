/*---------------------------------------------------------------------------*/
/* free() - free a previosly allocated memory block                          */
/*---------------------------------------------------------------------------*/
#include <win32.h>

void free(void *memblock)
{
  GlobalFree((HGLOBAL)memblock);
}
