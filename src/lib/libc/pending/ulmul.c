/*---------------------------------------------------------------------------*/
/* _aFulmul() - multiply unsigned long integers                              */
/*---------------------------------------------------------------------------*/
unsigned long _aFumul(unsigned short n1, unsigned short n2);

unsigned long ulmul(unsigned long n1, unsigned long n2)
{
  unsigned long result;
  unsigned short n1a, n1b;
  unsigned short n2a, n2b;

  n1a = (unsigned short)(n1 >> 16);
  n1b = (unsigned short)(n1 - (n1a << 16));
  n2a = (unsigned short)(n2 >> 16);
  n2b = (unsigned short)(n2 - (n2a << 16));
  result = _aFumul(n2b, n1b);
  result += (_aFumul(n2b, n1a)) << 16;
  result += (_aFumul(n2a, n1b)) << 16;
  return(result);
}
