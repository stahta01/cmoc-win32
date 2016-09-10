
#ifndef _SYSTEM_H
#define _SYSTEM_H

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
       sysptr_crunch, sysptr_execute;

void system_init(void);
char system_polcat(void);
void system_chrout(char c);
void system_putchr(char c, char devnum);
char system_getchr(char devnum);
void system_joyin(void);
void system_sound(void);
void system_line(void);

#endif

