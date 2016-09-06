
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <graph.h>
#include <equates.h>
#include <charset.h>

typedef struct {
    unsigned char cursor;
    unsigned char revers;
    unsigned char bordercolor;
} _conio_t;

extern _conio_t _conio;
//extern int ungetch_buf;

#define isvidram() (_curpos < 0x600 && _curpos >= 0x400)
#define isgrpram() (_curpos < _endgrp && _curpos >= _beggrp)

