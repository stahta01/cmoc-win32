
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <sys/dev.h>

#define SYSTEM_CMDLINE ((char*)0x2dd)

// 3 bits for the machine

#define SYSTEM_MAC_UNKNOWN        0
#define SYSTEM_MAC_COCO1          1
#define SYSTEM_MAC_COCO2          2
#define SYSTEM_MAC_COCO3          3
#define SYSTEM_MAC_DRAGON32       4
#define SYSTEM_MAC_DRAGON64       5
#define SYSTEM_MAC_RESERVED       6
#define SYSTEM_MAC_VECTREX        7

#define SYSTEM_FLG_EXT            8

// 3 bits for the memory size (blocks of 16K)

#define SYSTEM_RAM_XXK            0
#define SYSTEM_RAM_16K            16
#define SYSTEM_RAM_32K            32
#define SYSTEM_RAM_48K            48
#define SYSTEM_RAM_64K            64
#define SYSTEM_RAM_PAG            80

#define SYSTEM_FLG_DOS            128

unsigned char get_ostype(void);

// OS type collected by system_init().
extern unsigned char _get_ostype;

extern unsigned sysptr_polcat, sysptr_chrout, sysptr_csrdon, sysptr_blkin, sysptr_blkout,
       sysptr_joyin, sysptr_wrtldr, sysptr_line, sysptr_getchr, sysptr_putchr, sysptr_sound,
       sysptr_crunch, sysptr_execute, sysptr_screen;

void system_init(void);
int system_polcat(void);
void system_chrout(int c);
void system_putchr(int c, dev_t dev);
int system_getchr(dev_t dev);
void system_joyin(void);
void system_sound(void);
void system_line(void);
void system_screen(int mode);
char* system_crunch(char* cmd);
int system_execute(char* cmd);

#endif

