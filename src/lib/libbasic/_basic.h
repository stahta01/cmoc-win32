
#ifndef _BASIC_DEFS_H
#define _BASIC_DEFS_H

#include <basic.h>
#include <cmoc.h>
#include <coco.h>
#include <disk.h>

extern struct FileDesc _filedesc[5];

extern byte _pset1_set[8];
extern byte _pset1_clr[8];
extern byte _pset2_set[4][4];
extern byte _pset2_clr[4];
extern byte _chr_set[2][2];
extern byte _chr_clr[2][2];

void SCREENSETUP(void);

#endif

