
// This file was created by the WinCMOC compiler
// Created: 1/09/2016 10:53:12
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "cocodefs.asm"
//
// This file is in the public domain

#ifndef _COCO_DEFS_H
#define _COCO_DEFS_H

// 32-column VDG screen @1024-1535
#ifndef _VDGSCR
#define _VDGSCR 1024
#endif

// used by BLKOUT
#ifndef _BLKTYP
#define _BLKTYP 124
#endif

// used by BLKOUT
#ifndef _BLKLEN
#define _BLKLEN 125
#endif

// used by BLKOUT
#ifndef _CBUFAD
#define _CBUFAD 126
#endif

// used by CHROUT
#ifndef _DEVNUM
#define _DEVNUM 111
#endif

// used by JOYIN
#ifndef _POTVAL
#define _POTVAL 346
#endif

// Polls Keyboard for a Character
#ifndef _POLCAT
#define _POLCAT 40960
#endif

// Outputs a Character to Device
#ifndef _CHROUT
#define _CHROUT 40962
#endif

// Starts Cassette
#ifndef _CSRDON
#define _CSRDON 40964
#endif

// Reads a Block from Cassette
#ifndef _BLKIN
#define _BLKIN 40966
#endif

// Writes a Block to Cassette
#ifndef _BLKOUT
#define _BLKOUT 40968
#endif

// Samples Joystick Pots
#ifndef _JOYIN
#define _JOYIN 40970
#endif

// Turns Cassette On and Writes a Leader
#ifndef _WRTLDR
#define _WRTLDR 40972
#endif

// Convert USR Argument to Integer
#ifndef _INTCNV
#define _INTCNV 46061
#endif

// Return .d as the Result of USR
#ifndef _GIVABF
#define _GIVABF 46324
#endif

#ifndef _NAMBLK
#define _NAMBLK 0
#endif

#ifndef _DATBLK
#define _DATBLK 1
#endif

#ifndef _EOFBLK
#define _EOFBLK 255
#endif

// BASIC program
#ifndef _BASFIL
#define _BASFIL 0
#endif

// Data
#ifndef _DATFIL
#define _DATFIL 1
#endif

// Machine language
#ifndef _MACFIL
#define _MACFIL 2
#endif

// Binary
#ifndef _BINFLG
#define _BINFLG 0
#endif

// ASCII
#ifndef _ASCFLG
#define _ASCFLG 255
#endif

// Continuous
#ifndef _CONFLG
#define _CONFLG 0
#endif

// Gaps
#ifndef _GAPFLG
#define _GAPFLG 255
#endif

// PIA 1 side A data register
#ifndef _PIA0AD
#define _PIA0AD 65280
#endif

// PIA 1 side A control register
#ifndef _PIA0AC
#define _PIA0AC 65281
#endif

// PIA 1 side A data register
#ifndef _PIA0BD
#define _PIA0BD 65282
#endif

// PIA 1 side A control register
#ifndef _PIA0BC
#define _PIA0BC 65283
#endif

// PIA 1 side A data register
#ifndef _PIA1AD
#define _PIA1AD 65312
#endif

// PIA 1 side A control register
#ifndef _PIA1AC
#define _PIA1AC 65313
#endif

// PIA 1 side A data register
#ifndef _PIA1BD
#define _PIA1BD 65314
#endif

// PIA 1 side A control register
#ifndef _PIA1BC
#define _PIA1BC 65315
#endif

// video display mode
#ifndef _SAMVDG
#define _SAMVDG 65472
#endif

#ifndef _SAM_V0
#define _SAM_V0 65472
#endif

#ifndef _SAM_V1
#define _SAM_V1 65474
#endif

#ifndef _SAM_V2
#define _SAM_V2 65476
#endif

// display address offset
#ifndef _SAMDIS
#define _SAMDIS 65478
#endif

#ifndef _SAM_F0
#define _SAM_F0 65478
#endif

#ifndef _SAM_F1
#define _SAM_F1 65480
#endif

#ifndef _SAM_F2
#define _SAM_F2 65482
#endif

#ifndef _SAM_F3
#define _SAM_F3 65484
#endif

#ifndef _SAM_F4
#define _SAM_F4 65486
#endif

#ifndef _SAM_F5
#define _SAM_F5 65488
#endif

#ifndef _SAM_F6
#define _SAM_F6 65490
#endif

// page #1
#ifndef _SAMPAG
#define _SAMPAG 65492
#endif

#ifndef _SAM_P1
#define _SAM_P1 65492
#endif

// cpu rate
#ifndef _SAMRAT
#define _SAMRAT 65494
#endif

#ifndef _SAM_R0
#define _SAM_R0 65494
#endif

#ifndef _SAM_R1
#define _SAM_R1 65496
#endif

// memory size
#ifndef _SAMSIZ
#define _SAMSIZ 65498
#endif

#ifndef _SAM_M0
#define _SAM_M0 65498
#endif

#ifndef _SAM_M1
#define _SAM_M1 65500
#endif

// memory map type
#ifndef _SAMTYP
#define _SAMTYP 65502
#endif

#ifndef _SAM_TY
#define _SAM_TY 65502
#endif

// cassette motor control bit
#ifndef _CASMOT
#define _CASMOT 8
#endif

#ifndef _ACTIND
#define _ACTIND 1535
#endif

#ifndef _IRQ
#define _IRQ 16
#endif

#ifndef _FIRQ
#define _FIRQ 64
#endif


#endif
