
#ifndef _ASM_H
#define _ASM_H

//#define CLI   ANDCC #%10101111
//#define SEI   ORCC  #%01010000

#define _asm_romoff()   asm{ orcc #$50} asm{ sta $ffdf}
#define _asm_romon()    asm{ sta $ffde} asm{ andcc #$af}

#endif

