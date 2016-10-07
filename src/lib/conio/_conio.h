
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <graph.h>
#include <bank.h>
#include <equates.h>
#include <charset.h>
#include <system.h>
#include <dev.h>
#include <vt52.h>
#include <ascii.h>
#include <machine.h>

#include <coco/super.h>
#include <sys/handle.h>

#define _is_coco3_mode (machine.typ == MAC_TYP_COCO3 && *(byte*)_HRWIDTH)

void coco3_gotoxy(int x, int y);

typedef struct {
    bool cursor;
    bool revers;
    int bordercolor;

    // Late binding handles for libgraph.
    handle_t outchar;
    handle_t scrolltextwindow;
    handle_t clearscreen;
    handle_t settextposition;
    handle_t settextpositionx;
    handle_t settextpositiony;
    handle_t getfontinfo;
    handle_t settextpositionat;
    handle_t gettextpositionat;
} conio_t;

extern conio_t _conio;

#define isvidram() (_curpos < 0x600)

