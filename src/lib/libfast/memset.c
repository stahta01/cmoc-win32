
#define LOAD1
#define SAVE1   sta ,x+
#define LOAD2
#define SAVE2   std ,x++

#define ADST    2,s
#define ACHR    4,s
#define ANUM    6,s

void asm memset(void* dst, int c, unsigned n)
{
#include "fastloop.h"
}

