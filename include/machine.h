
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

#ifndef _MACHINE_H
#define _MACHINE_H

// Copyright strings

#define MAC_COLBAS_COPYRIGHT        ((char*)0xa147)
#define MAC_EXTBAS_COPYRIGHT        ((char*)0x80e8)
#define MAC_DSKEXT_COPYRIGHT        ((char*)0xc139)

// Version numbers. Returns integers.

#define MAC_COLBAS_MAJOR            (MAC_COLBAS_COPYRIGHT[12]-'0')
#define MAC_COLBAS_MINOR            (MAC_COLBAS_COPYRIGHT[14]-'0')
#define MAC_EXTBAS_MAJOR            (MAC_EXTBAS_COPYRIGHT[21]-'0')
#define MAC_EXTBAS_MINOR            (MAC_EXTBAS_COPYRIGHT[23]-'0')
#define MAC_DSKEXT_MAJOR            (MAC_DSKEXT_COPYRIGHT[26]-'0')
#define MAC_DSKEXT_MINOR            (MAC_DSKEXT_COPYRIGHT[28]-'0')

// Checks for Color/Extended & Disk ROM's

#define MAC_HAS_COLBAS              (MAC_COLBAS_COPYRIGHT[0] == 'C' && MAC_COLBAS_COPYRIGHT[1] == 'O')
#define MAC_HAS_EXTBAS              (MAC_EXTBAS_COPYRIGHT[0] == 'E' && MAC_EXTBAS_COPYRIGHT[1] == 'X')
#define MAC_HAS_DSKEXT              (MAC_DSKEXT_COPYRIGHT[0] == 'D' && MAC_DSKEXT_COPYRIGHT[1] == 'I')
#define MAC_HAS_SUPBAS              (MAC_HAS_EXTBAS && MAC_EXTBAS_MAJOR >= 2)

// Check for a running DOS system. This checks the start of graphics memory, which is moved
// by DOS. Since it might be possible to disable DOS on a DOS system, this wil return false,
// while MAC_HAS_DSKEXT returns true.

#define MAC_HAS_DOS                 (*(byte*)0xbc > 6)

// Generic checks for CoCo systems

#define MAC_IS_COCO                 MAC_HAS_COLBAS
#define MAC_IS_COCO1                (MAC_IS_COCO && MAC_COLBAS_MINOR <  2)
#define MAC_IS_COCO2                (MAC_IS_COCO && MAC_COLBAS_MINOR >= 2)
#define MAC_IS_COCO3                MAC_HAS_SUPBAS

// Checks for Dragon systems

#define MAC_IS_DRAGON               (*(word*)0x8000 == 0x7ebb)
#define MAC_IS_DRAGON32             (MAC_IS_DRAGON && *(byte*)0x8002 != 0x3c)
#define MAC_IS_DRAGON64             (MAC_IS_DRAGON && *(byte*)0x8002 == 0x3c)

// Settings for the machine_t structure

#define MAC_TYP_UNKNOWN         0
#define MAC_TYP_COCO1           1
#define MAC_TYP_COCO2           2
#define MAC_TYP_COCO3           3
#define MAC_TYP_DRAGON32        4
#define MAC_TYP_DRAGON64        5
#define MAC_TYP_RESERVED        6
#define MAC_TYP_VECTREX         7

#define MAC_ROM_UNKNOWN         0
#define MAC_ROM_STANDARD        1
#define MAC_ROM_EXTENDED        2
#define MAC_ROM_SUPER           3

typedef struct system_t {
    byte    typ;
    byte    rom;
    bool    dos;
    word    ram;                                // kb
} machine_t;

void machine_init(void);

extern machine_t _machine;

#endif

