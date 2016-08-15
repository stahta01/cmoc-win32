
/*  assert.h - Assert macro for CMOC

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.
*/

#ifndef _ASSERT_H
#define _ASSERT_H

#include <stdio.h>

#ifdef NDEBUG
#define assert(cond)
#else
#define assert(cond) if (!(cond)) {\
    printf("\nASSERT FAILED!\n\nFILE:%s\nLINE:%d\nCOND:%s\n", __FILE__, __LINE__, #cond); exit(-1); }
#endif

#endif  /* _ASSERT_H */

