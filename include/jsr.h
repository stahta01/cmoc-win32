
#ifndef _ROM_H
#define _ROM_H

#define _JSR(A) jsr A

#if defined(__COCO__)
#define JSR_POLCAT      _JSR([$A000])
#define JSR_CHROUT      _JSR([$A002])
#define JSR_CLRSCR      _JSR($A928)
#else

#if defined(__DRAGON__)
#define JSR_POLCAT      _JSR([$A000])
#define JSR_CHROUT      _JSR([$A002])
#define JSR_CLRSCR      _JSR($BA77)
#else

#error Unknown target

#endif
#endif

#endif


