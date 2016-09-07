
#ifndef _BASIC_DEFS_H
#define _BASIC_DEFS_H

#include <basic.h>
#include <fixpt.h>
#include <cmoc.h>
#include <coco.h>
#include <disk.h>
#include <unistd.h>
#include <fcntl.h>
#include <system.h>

extern int _filedesc[FOPEN_MAX];

extern byte _chr_set[2][2];
extern byte _chr_clr[2][2];

void SCREENSETUP(void);

#endif

