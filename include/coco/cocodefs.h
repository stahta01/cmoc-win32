
// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)
//
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "cocodefs.asm"
//
// This file is in the public domain

#ifndef _COCO_DEFS_H
#define _COCO_DEFS_H

// Decimal 1024 (0x400) [Value] - 32-column VDG screen @1024-1535
#ifndef _VDGSCR
#define _VDGSCR 1024
#endif

// Decimal 124 (0x7C) [Value] - used by BLKOUT
#ifndef _BLKTYP
#define _BLKTYP 124
#endif

// Decimal 125 (0x7D) [Value] - used by BLKOUT
#ifndef _BLKLEN
#define _BLKLEN 125
#endif

// Decimal 126 (0x7E) [Value] - used by BLKOUT
#ifndef _CBUFAD
#define _CBUFAD 126
#endif

// Decimal 111 (0x6F) [Value] - used by CHROUT
#ifndef _DEVNUM
#define _DEVNUM 111
#endif

// Decimal 346 (0x15A) [Value] - used by JOYIN
#ifndef _POTVAL
#define _POTVAL 346
#endif

// Decimal 40960 (0xA000) [Value] - Polls Keyboard for a Character
#ifndef _POLCAT
#define _POLCAT 40960
#endif

// Decimal 40962 (0xA002) [Value] - Outputs a Character to Device
#ifndef _CHROUT
#define _CHROUT 40962
#endif

// Decimal 40964 (0xA004) [Value] - Starts Cassette
#ifndef _CSRDON
#define _CSRDON 40964
#endif

// Decimal 40966 (0xA006) [Value] - Reads a Block from Cassette
#ifndef _BLKIN
#define _BLKIN 40966
#endif

// Decimal 40968 (0xA008) [Value] - Writes a Block to Cassette
#ifndef _BLKOUT
#define _BLKOUT 40968
#endif

// Decimal 40970 (0xA00A) [Value] - Samples Joystick Pots
#ifndef _JOYIN
#define _JOYIN 40970
#endif

// Decimal 40972 (0xA00C) [Value] - Turns Cassette On and Writes a Leader
#ifndef _WRTLDR
#define _WRTLDR 40972
#endif

// Decimal 46061 (0xB3ED) [Value] - Convert USR Argument to Integer
#ifndef _INTCNV
#define _INTCNV 46061
#endif

// Decimal 46324 (0xB4F4) [Value] - Return .d as the Result of USR
#ifndef _GIVABF
#define _GIVABF 46324
#endif

// Decimal 0 (0x0) [Value]
#ifndef _NAMBLK
#define _NAMBLK 0
#endif

// Decimal 1 (0x1) [Value]
#ifndef _DATBLK
#define _DATBLK 1
#endif

// Decimal 255 (0xFF) [Value]
#ifndef _EOFBLK
#define _EOFBLK 255
#endif

// Decimal 0 (0x0) [Value] - BASIC program
#ifndef _BASFIL
#define _BASFIL 0
#endif

// Decimal 1 (0x1) [Value] - Data
#ifndef _DATFIL
#define _DATFIL 1
#endif

// Decimal 2 (0x2) [Value] - Machine language
#ifndef _MACFIL
#define _MACFIL 2
#endif

// Decimal 0 (0x0) [Value] - Binary
#ifndef _BINFLG
#define _BINFLG 0
#endif

// Decimal 255 (0xFF) [Value] - ASCII
#ifndef _ASCFLG
#define _ASCFLG 255
#endif

// Decimal 0 (0x0) [Value] - Continuous
#ifndef _CONFLG
#define _CONFLG 0
#endif

// Decimal 255 (0xFF) [Value] - Gaps
#ifndef _GAPFLG
#define _GAPFLG 255
#endif

// Decimal 65280 (0xFF00) [Value] - PIA 1 side A data register
#ifndef _PIA0AD
#define _PIA0AD 65280
#endif

// Decimal 65281 (0xFF01) [Value] - PIA 1 side A control register
#ifndef _PIA0AC
#define _PIA0AC 65281
#endif

// Decimal 65282 (0xFF02) [Value] - PIA 1 side A data register
#ifndef _PIA0BD
#define _PIA0BD 65282
#endif

// Decimal 65283 (0xFF03) [Value] - PIA 1 side A control register
#ifndef _PIA0BC
#define _PIA0BC 65283
#endif

// Decimal 65312 (0xFF20) [Value] - PIA 1 side A data register
#ifndef _PIA1AD
#define _PIA1AD 65312
#endif

// Decimal 65313 (0xFF21) [Value] - PIA 1 side A control register
#ifndef _PIA1AC
#define _PIA1AC 65313
#endif

// Decimal 65314 (0xFF22) [Value] - PIA 1 side A data register
#ifndef _PIA1BD
#define _PIA1BD 65314
#endif

// Decimal 65315 (0xFF23) [Value] - PIA 1 side A control register
#ifndef _PIA1BC
#define _PIA1BC 65315
#endif

// Decimal 65472 (0xFFC0) [Value] - video display mode
#ifndef _SAMVDG
#define _SAMVDG 65472
#endif

// Decimal 65472 (0xFFC0) [Value]
#ifndef _SAM_V0
#define _SAM_V0 65472
#endif

// Decimal 65474 (0xFFC2) [Value]
#ifndef _SAM_V1
#define _SAM_V1 65474
#endif

// Decimal 65476 (0xFFC4) [Value]
#ifndef _SAM_V2
#define _SAM_V2 65476
#endif

// Decimal 65478 (0xFFC6) [Value] - display address offset
#ifndef _SAMDIS
#define _SAMDIS 65478
#endif

// Decimal 65478 (0xFFC6) [Value]
#ifndef _SAM_F0
#define _SAM_F0 65478
#endif

// Decimal 65480 (0xFFC8) [Value]
#ifndef _SAM_F1
#define _SAM_F1 65480
#endif

// Decimal 65482 (0xFFCA) [Value]
#ifndef _SAM_F2
#define _SAM_F2 65482
#endif

// Decimal 65484 (0xFFCC) [Value]
#ifndef _SAM_F3
#define _SAM_F3 65484
#endif

// Decimal 65486 (0xFFCE) [Value]
#ifndef _SAM_F4
#define _SAM_F4 65486
#endif

// Decimal 65488 (0xFFD0) [Value]
#ifndef _SAM_F5
#define _SAM_F5 65488
#endif

// Decimal 65490 (0xFFD2) [Value]
#ifndef _SAM_F6
#define _SAM_F6 65490
#endif

// Decimal 65492 (0xFFD4) [Value] - page #1
#ifndef _SAMPAG
#define _SAMPAG 65492
#endif

// Decimal 65492 (0xFFD4) [Value]
#ifndef _SAM_P1
#define _SAM_P1 65492
#endif

// Decimal 65494 (0xFFD6) [Value] - cpu rate
#ifndef _SAMRAT
#define _SAMRAT 65494
#endif

// Decimal 65494 (0xFFD6) [Value]
#ifndef _SAM_R0
#define _SAM_R0 65494
#endif

// Decimal 65496 (0xFFD8) [Value]
#ifndef _SAM_R1
#define _SAM_R1 65496
#endif

// Decimal 65498 (0xFFDA) [Value] - memory size
#ifndef _SAMSIZ
#define _SAMSIZ 65498
#endif

// Decimal 65498 (0xFFDA) [Value]
#ifndef _SAM_M0
#define _SAM_M0 65498
#endif

// Decimal 65500 (0xFFDC) [Value]
#ifndef _SAM_M1
#define _SAM_M1 65500
#endif

// Decimal 65502 (0xFFDE) [Value] - memory map type
#ifndef _SAMTYP
#define _SAMTYP 65502
#endif

// Decimal 65502 (0xFFDE) [Value]
#ifndef _SAM_TY
#define _SAM_TY 65502
#endif

// Decimal 8 (0x8) [Value] - cassette motor control bit
#ifndef _CASMOT
#define _CASMOT 8
#endif

// Decimal 1535 (0x5FF) [Value]
#ifndef _ACTIND
#define _ACTIND 1535
#endif

// Decimal 16 (0x10) [Value]
#ifndef _IRQ
#define _IRQ 16
#endif

// Decimal 64 (0x40) [Value]
#ifndef _FIRQ
#define _FIRQ 64
#endif


#endif
