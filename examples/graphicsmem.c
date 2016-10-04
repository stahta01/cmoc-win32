
// The graphics mem can be an extra 2K without a disk system. Use this pragma to
// test. Warning: Expanding the 6K graphics memory to 8K will trash BASIC
// programs/strings.

#pragma options -nodos

// This is an example of allocating graphics memory. There is 6K of memory which is
// wasted if you dont use graphics. Note: Disk systems move the graphics memory by 2K,
// which means, on non-disk systems, there is an extra 2K after the graphics memory.
// It is possible to use this extra 2K with gmalloc functions. I have provided
// an example below.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <equates.h>
#include <gmalloc.h>

#pragma options -machine=cocous

bool check_graphics_memory(size_t size)
{
    // Check for graphics memory.
    // 6140 bytes is the max we can allocate from a 6144 byte heap.
    void* grp = gmalloc(size);
    if (grp) {
        memset(grp, -1, _msize(grp));
        cwritef("\n%u BYTES OF GMEM AVALIABLE\n\n", _msize(grp));
        free(grp);
        return true;
    }
    cwritef("\n%u MEMORY NOT AVALIABLE\n", size);
    return false;
}

void allocate_some_data(void)
{
#define STRING_COUNT 15
    char* strings[STRING_COUNT];
    for (int i = 0; i < STRING_COUNT; i++) {
        char s[100];
        swritef(s, "DATA#%d", i);
        strings[i] = (char*)gmalloc(strlen(s) + 1);
        if (strings[i]) {
            strcpy(strings[i], s);
        }
    }
    for (int i = 0; i < STRING_COUNT; i++) {
        if (strings[i]) {
            cwritef("%s ", strings[i]);
            // You can use a standard free() command with all memory allocated in the first
            // 32K. ie: Everything except far (banked) memory.
            free(strings[i]);
        }
    }
    cputc('\n');
}

int main(void)
{
    clrscr();

    cputs("GRAPHICS MEMORY MANAGEMENT\n\n");

    // SAM graphic pages are 512 bytes each
    // BASIC allocates graphic pages in blocks of 3 = 1536 bytes
    // PMODE 4 requires 4 BASIC pages = 4 x 1536 = 6144 bytes
    // Extended BASIC allocates 4 pages by default (even on 16K machines)
    // Disk basic moves these 4 pages forward by 2K.
    //
    // Therfore, the default graphics memory is:
    // Ext  BASIC: 1536..7680 = 6144 bytes
    // Disk BASIC: 3584..9728 = 6144 bytes
    //
    // You can find out these addresses using _grpram & _txttab. Note: _grpram only contains
    // the MSB of the start of graphics.

    cwritef("%u..%u = %u BYTES\n", ((word)_grpram << 8), _txttab - 1,
            _txttab - ((word)_grpram << 8) - 1);

    // The current graphics page can be found using _beggrp & _endgrp

    cwritef("%u..%u = %u BYTES\n", _beggrp, _endgrp, _endgrp - _beggrp);

    // The start address of CMOC programs is $2800 (10240) which gives enough space for
    // disk basic, 4 graphics pages and a little bit for BASIC.

    // If you want to use the graphics memory for storage, use gmalloc.h functions, which
    // will give you access to an extra 6K of managed memory.

    // Note: Using cwritef() & swritef() will also reduce your binary size. These are
    // small versions of cprintf() & sprintf(). They dont support floats/longs or field
    // formating, so that code wont be linked into your bin. Only supports i/s/c/u.

    check_graphics_memory(6140);
    allocate_some_data();
    check_graphics_memory(6140);
    cputs("WOULD YOU LIKE TO TRY FOR 8K?");
    if (getch() == 'Y') {
        cputc('\n');
        // Expand the default gmalloc heap.
        // This assumes the origin is $2800 (DEFAULT)
        heap_init(gheap(), 0x2800 - (int)gheap());
        if (check_graphics_memory(8192 - 4)) {
            allocate_some_data();
            cputs("NOW TRY TO LIST BASIC PROG\n");
        } else {
            cputs("8K GMEM NOT AVALIABLE.\nMUST BE DISK A SYSTEM\n");
        }
    }
    cputs("\nBACK TO BASIC\n");

    return 0;
}

