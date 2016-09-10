
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <equates.h>
#include <system.h>

void system_init_coco(void);
void system_init_dragon(void);

#ifdef __COCO__
#include <coco/cb_equates.h>
#define _CRUNCHLINE         $B821
#define _PROCESSCOMMAND     $ADC6

//#define JSR_CLS         _JSR($a928)
//#define JSR_CLS_B       _JSR($a928-12)
#define JSR_SOUND       _JSR($a951)

#endif

#ifdef __DRAGON__
#include <coco/dragon_equivs.h>
#define _CRUNCHLINE         $8F67
#define _PROCESSCOMMAND     $84DC

//#define JSR_CLS         _JSR($ba77)
//#define JSR_CLS_B       _JSR($ba77-12)
#define JSR_SOUND       _JSR($baa0)

#endif


