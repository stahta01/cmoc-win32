
#ifndef _BASIC_DEFS_H
#define _BASIC_DEFS_H

#include <basic.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fix6.h>
#include <cmoc.h>
#include <coco.h>
#include <disk.h>
#include <unistd.h>
#include <fcntl.h>
#include <system.h>
#include <graph.h>
#include <time.h>
#include <disk.h>

extern int _filedesc[FOPEN_MAX];

extern byte _chr_set[2][2];
extern byte _chr_clr[2][2];

void SCREENSETUP(void);

#endif

