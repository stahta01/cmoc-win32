
#ifndef _EQUATES_H
#define _EQUATES_H

#define _JSR(A) jsr A

#define JSR_POLCAT      _JSR([$a000])
#define JSR_CHROUT      _JSR([$a002])

#if defined(__COCO__)

#include <coco/equates.h>

#define JSR_CLRSCR      _JSR($a928)
#define JSR_SOUND       _JSR($a951)

#else

#if defined(__DRAGON__)

#include <dragon/equates.h>

#define JSR_CLRSCR      _JSR($ba77)
#define JSR_SOUND       _JSR($baa0)

#else

#error unknown target

#endif
#endif

#endif


