/*---------------------------------------------------------------------------*/
/* localeconv() - return a pointer to a structure describing the             */
/*                current locale                                             */
/*---------------------------------------------------------------------------*/
#include <crt.h>
struct lconv *localeconv(void)
{
  return(&_crt_base->_crt_lcbuffer);
}
