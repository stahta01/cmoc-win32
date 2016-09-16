
/*  assert.h - Assert macro for CMOC

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.
*/

#ifndef _ASSERT_H
#define _ASSERT_H

void _assert(char* message, char* filename, unsigned line);

#ifdef NDEBUG
#define assert(cond)
#else
#define assert(cond) if (!(cond)) _assert(#cond, __FILE__, __LINE__);
#endif

#endif

