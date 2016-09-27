/*---------------------------------------------------------------------------*/
/* rand() return a pseudo random number from 0 to RAND_MAX                   */
/*---------------------------------------------------------------------------*/
#include <llmath.h>
#include <stdlib.h>

int rand(void)
{
  _crt_base->_rand_next = _mul32(_crt_base->_rand_next, 1103515245L) + 12345L;
  return (unsigned int)(_crt_base->_rand_next / 65536) % (RAND_MAX + 1);
}

void srand(unsigned int seed)
{
  _crt_base->_rand_next = seed;
}

