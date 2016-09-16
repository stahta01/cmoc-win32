
//#define IS_COPY
#define LOAD1
#define SAVE1 sta ,x++
#define LOAD2
#define SAVE2 std ,x++

void asm memset(void* dst, int c, unsigned n)
{
#include "fastloop.h"
}

