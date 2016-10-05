
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <graph.h>
#include <equates.h>
#include <charset.h>
#include <system.h>
#include <ascii.h>
#include <vt52.h>

#include <sys/handle.h>

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
    handle_t movetextposition;
} conio_t;

extern conio_t _conio;

#define isvidram() (_curpos < 0x600)
#define isgrpram() (_curpos < _endgrp && _curpos >= _beggrp)
