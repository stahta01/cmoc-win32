
#ifndef _ASM_H
#define _ASM_H

#define _asm_romoff()   asm{ orcc #$50} asm{ sta $ffdf}
#define _asm_romon()    asm{ sta $ffde} asm{ andcc #$af}

#endif

