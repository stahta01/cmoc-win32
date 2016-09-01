
// This file was created by the WinCMOC compiler
// Created: 1/09/2016 11:49:21
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "equates.asm"
//
// This file is in the public domain

#ifndef _DRAGON_COCO_EQUATES_H
#define _DRAGON_COCO_EQUATES_H

// Decimal 8 (0x8/$8) [Constant] - BACKSPACE (Compatible with CoCo)
#ifndef _BS
#define _BS 8
#endif

// Decimal 13 (0xD/$D) [Constant] - ENTER KEY (Compatible with CoCo)
#ifndef _CR
#define _CR 13
#endif

// Decimal 27 (0x1B/$1B) [Constant] - ESCAPE CODE (Compatible with CoCo)
#ifndef _ESC
#define _ESC 27
#endif

// Decimal 10 (0xA/$A) [Constant] - LINE FEED (Compatible with CoCo)
#ifndef _LF
#define _LF 10
#endif

// Decimal 12 (0xC/$C) [Constant] - FORM FEED (Compatible with CoCo)
#ifndef _FORMF
#define _FORMF 12
#endif

// Decimal 32 (0x20/$20) [Constant] - SPACE (BLANK) (Compatible with CoCo)
#ifndef _SPACE
#define _SPACE 32
#endif

// Decimal 15 (0xF/$F) [Word] - TEMPORARY POINTER (Compatible with CoCo)
#ifndef _TEMPTR
#define _TEMPTR 15
#endif
#ifndef _temptr
#define _temptr (*(unsigned*)_TEMPTR)
#endif

// Decimal 25 (0x19/$19) [Word] - PV BEGINNING OF BASIC PROGRAM (Compatible with CoCo)
#ifndef _TXTTAB
#define _TXTTAB 25
#endif
#ifndef _txttab
#define _txttab (*(unsigned*)_TXTTAB)
#endif

// Decimal 27 (0x1B/$1B) [Word] - PV START OF VARIABLES (Compatible with CoCo)
#ifndef _VARTAB
#define _VARTAB 27
#endif
#ifndef _vartab
#define _vartab (*(unsigned*)_VARTAB)
#endif

// Decimal 29 (0x1D/$1D) [Word] - PV START OF ARRAYS (Compatible with CoCo)
#ifndef _ARYTAB
#define _ARYTAB 29
#endif
#ifndef _arytab
#define _arytab (*(unsigned*)_ARYTAB)
#endif

// Decimal 31 (0x1F/$1F) [Word] - PV END OF ARRAYS (+1) (Compatible with CoCo)
#ifndef _ARYEND
#define _ARYEND 31
#endif
#ifndef _aryend
#define _aryend (*(unsigned*)_ARYEND)
#endif

// Decimal 33 (0x21/$21) [Word] - PV START OF STRING STORAGE (TOP OF FREE RAM) (Compatible with CoCo)
#ifndef _FRETOP
#define _FRETOP 33
#endif
#ifndef _fretop
#define _fretop (*(unsigned*)_FRETOP)
#endif

// Decimal 35 (0x23/$23) [Word] - PV START OF STRING VARIABLES (Compatible with CoCo)
#ifndef _STRTAB
#define _STRTAB 35
#endif
#ifndef _strtab
#define _strtab (*(unsigned*)_STRTAB)
#endif

// Decimal 37 (0x25/$25) [Word] - UTILITY STRING POINTER (Compatible with CoCo)
#ifndef _FRESPC
#define _FRESPC 37
#endif
#ifndef _frespc
#define _frespc (*(unsigned*)_FRESPC)
#endif

// Decimal 39 (0x27/$27) [Word] - PV TOP OF STRING SPACE (Compatible with CoCo)
#ifndef _MEMSIZ
#define _MEMSIZ 39
#endif
#ifndef _memsiz
#define _memsiz (*(unsigned*)_MEMSIZ)
#endif

// Decimal 41 (0x29/$29) [Word] - SAVED LINE NUMBER DURING A "STOP" (Compatible with CoCo)
#ifndef _OLDTXT
#define _OLDTXT 41
#endif
#ifndef _oldtxt
#define _oldtxt (*(unsigned*)_OLDTXT)
#endif

// Decimal 43 (0x2B/$2B) [Word] - BINARY VALUE OF A CONVERTED LINE NUMBER (Compatible with CoCo)
#ifndef _BINVAL
#define _BINVAL 43
#endif
#ifndef _binval
#define _binval (*(unsigned*)_BINVAL)
#endif

// Decimal 45 (0x2D/$2D) [Word] - SAVED INPUT PTR DURING A "STOP" (Compatible with CoCo)
#ifndef _OLDPTR
#define _OLDPTR 45
#endif
#ifndef _oldptr
#define _oldptr (*(unsigned*)_OLDPTR)
#endif

// Decimal 47 (0x2F/$2F) [Word] - TEMPORARY INPUT POINTER STORAGE (Compatible with CoCo)
#ifndef _TINPTR
#define _TINPTR 47
#endif
#ifndef _tinptr
#define _tinptr (*(unsigned*)_TINPTR)
#endif

// Decimal 49 (0x31/$31) [Word] - PV 'DATA' STATEMENT LINE NUMBER POINTER (Compatible with CoCo)
#ifndef _DATTXT
#define _DATTXT 49
#endif
#ifndef _dattxt
#define _dattxt (*(unsigned*)_DATTXT)
#endif

// Decimal 51 (0x33/$33) [Word] - PV 'DATA' STATEMENT ADDRESS POINTER (Compatible with CoCo)
#ifndef _DATPTR
#define _DATPTR 51
#endif
#ifndef _datptr
#define _datptr (*(unsigned*)_DATPTR)
#endif

// Decimal 53 (0x35/$35) [Word] - DATA POINTER FOR 'INPUT' & 'READ' (Compatible with CoCo)
#ifndef _DATTMP
#define _DATTMP 53
#endif
#ifndef _dattmp
#define _dattmp (*(unsigned*)_DATTMP)
#endif

// Decimal 55 (0x37/$37) [Word] - TV TEMP STORAGE FOR A VARIABLE NAME (Compatible with CoCo)
#ifndef _VARNAM
#define _VARNAM 55
#endif
#ifndef _varnam
#define _varnam (*(unsigned*)_VARNAM)
#endif

// Decimal 57 (0x39/$39) [Word] - TV POINTER TO A VARIABLE DESCRIPTOR (Compatible with CoCo)
#ifndef _VARPTR
#define _VARPTR 57
#endif
#ifndef _varptr
#define _varptr (*(unsigned*)_VARPTR)
#endif

// Decimal 59 (0x3B/$3B) [Word] - TEMP POINTER TO A VARIABLE DESCRIPTOR (Compatible with CoCo)
#ifndef _VARDES
#define _VARDES 59
#endif
#ifndef _vardes
#define _vardes (*(unsigned*)_VARDES)
#endif

// Decimal 104 (0x68/$68) [Word] - PV CURRENT LINE # OF BASIC PROGRAM, $FFFF = DIRECT (Compatible with CoCo)
#ifndef _CURLIN
#define _CURLIN 104
#endif
#ifndef _curlin
#define _curlin (*(unsigned*)_CURLIN)
#endif

// Decimal 107 (0x6B/$6B) [Byte] - TV TAB ZONE (Compatible with CoCo)
#ifndef _DEVLCF
#define _DEVLCF 107
#endif
#ifndef _devlcf
#define _devlcf (*(unsigned char*)_DEVLCF)
#endif

// Decimal 108 (0x6C/$6C) [Byte] - TV PRINT POSITION (Compatible with CoCo)
#ifndef _DEVPOS
#define _DEVPOS 108
#endif
#ifndef _devpos
#define _devpos (*(unsigned char*)_DEVPOS)
#endif

// Decimal 109 (0x6D/$6D) [Byte] - TV PRINT WIDTH (Compatible with CoCo)
#ifndef _DEVWID
#define _DEVWID 109
#endif
#ifndef _devwid
#define _devwid (*(unsigned char*)_DEVWID)
#endif

// Decimal 111 (0x6F/$6F) [Byte] - PV DEVICE NUMBER: -3=DLOAD, -2=PRINTER, (Compatible with CoCo)
#ifndef _DEVNUM
#define _DEVNUM 111
#endif
#ifndef _devnum
#define _devnum (*(unsigned char*)_DEVNUM)
#endif

// Decimal 113 (0x71/$71) [Byte] - PV WARM START FLAG: $55=WARM, OTHER=COLD (Compatible with CoCo)
#ifndef _RSTFLG
#define _RSTFLG 113
#endif
#ifndef _rstflg
#define _rstflg (*(unsigned char*)_RSTFLG)
#endif

// Decimal 114 (0x72/$72) [Word] - PV WARM START VECTOR - JUMP ADDRESS FOR WARM START (Compatible with CoCo)
#ifndef _RSTVEC
#define _RSTVEC 114
#endif
#ifndef _rstvec
#define _rstvec (*(unsigned*)_RSTVEC)
#endif

// Decimal 116 (0x74/$74) [Word] - PV TOP OF RAM (Compatible with CoCo)
#ifndef _TOPRAM
#define _TOPRAM 116
#endif
#ifndef _topram
#define _topram (*(unsigned*)_TOPRAM)
#endif

// Decimal 120 (0x78/$78) [Byte] - PV FILE STATUS FLAG: 0=CLOSED, 1=INPUT, 2=OUTPUT (Compatible with CoCo)
#ifndef _FILSTA
#define _FILSTA 120
#endif
#ifndef _filsta
#define _filsta (*(unsigned char*)_FILSTA)
#endif

// Decimal 121 (0x79/$79) [Byte] - PV CONSOLE IN BUFFER CHAR COUNTER (Compatible with CoCo)
#ifndef _CINCTR
#define _CINCTR 121
#endif
#ifndef _cinctr
#define _cinctr (*(unsigned char*)_CINCTR)
#endif

// Decimal 122 (0x7A/$7A) [Word] - PV CONSOLE IN BUFFER POINTER (Compatible with CoCo)
#ifndef _CINPTR
#define _CINPTR 122
#endif
#ifndef _cinptr
#define _cinptr (*(unsigned*)_CINPTR)
#endif

// Decimal 124 (0x7C/$7C) [Byte] - TV CASS BLOCK TYPE: 0=HEADER, 1=DATA, $FF=EOF (Compatible with CoCo)
#ifndef _BLKTYP
#define _BLKTYP 124
#endif
#ifndef _blktyp
#define _blktyp (*(unsigned char*)_BLKTYP)
#endif

// Decimal 125 (0x7D/$7D) [Byte] - TV CASSETTE BYTE COUNT (Compatible with CoCo)
#ifndef _BLKLEN
#define _BLKLEN 125
#endif
#ifndef _blklen
#define _blklen (*(unsigned char*)_BLKLEN)
#endif

// Decimal 136 (0x88/$88) [Word] - PV CURSOR LOCATION (Compatible with CoCo)
#ifndef _CURPOS
#define _CURPOS 136
#endif
#ifndef _curpos
#define _curpos (*(unsigned*)_CURPOS)
#endif

// Decimal 140 (0x8C/$8C) [Byte] - TV TONE VALUE FOR SOUND COMMAND (Compatible with CoCo)
#ifndef _SNDTON
#define _SNDTON 140
#endif
#ifndef _sndton
#define _sndton (*(unsigned char*)_SNDTON)
#endif

// Decimal 141 (0x8D/$8D) [Word] - TV DURATION VALUE FOR SOUND COMMAND (Compatible with CoCo)
#ifndef _SNDDUR
#define _SNDDUR 141
#endif
#ifndef _snddur
#define _snddur (*(unsigned*)_SNDDUR)
#endif

// Decimal 157 (0x9D/$9D) [Word] - LB4AA *PV JUMP ADDRESS FOR EXEC COMMAND (Compatible with CoCo)
#ifndef _EXECJP
#define _EXECJP 157
#endif
#ifndef _execjp
#define _execjp (*(unsigned*)_EXECJP)
#endif

// Decimal 159 (0x9F/$9F) [Array] - (Compatible with CoCo)
#ifndef _GETNCH
#define _GETNCH 159
#endif
#ifndef _getnch
#define _getnch ((unsigned char*)_GETNCH)
#endif

// Decimal 166 (0xA6/$A6) [Word] - PV THESE 2 BYTES CONTAIN ADDRESS OF THE CURRENT (Compatible with CoCo)
#ifndef _CHARAD
#define _CHARAD 166
#endif
#ifndef _charad
#define _charad (*(unsigned*)_CHARAD)
#endif

// Decimal 175 (0xAF/$AF) [Byte] - PV TRACE FLAG 0=OFF ELSE=ON (Compatible with CoCo)
#ifndef _TRCFLG
#define _TRCFLG 175
#endif
#ifndef _trcflg
#define _trcflg (*(unsigned char*)_TRCFLG)
#endif

// Decimal 176 (0xB0/$B0) [Word] - PV ADDRESS OF THE START OF USR VECTORS (Compatible with CoCo)
#ifndef _USRADR
#define _USRADR 176
#endif
#ifndef _usradr
#define _usradr (*(unsigned*)_USRADR)
#endif

// Decimal 178 (0xB2/$B2) [Byte] - PV FOREGROUND COLOR (Compatible with CoCo)
#ifndef _FORCOL
#define _FORCOL 178
#endif
#ifndef _forcol
#define _forcol (*(unsigned char*)_FORCOL)
#endif

// Decimal 179 (0xB3/$B3) [Byte] - PV BACKGROUND COLOR (Compatible with CoCo)
#ifndef _BAKCOL
#define _BAKCOL 179
#endif
#ifndef _bakcol
#define _bakcol (*(unsigned char*)_BAKCOL)
#endif

// Decimal 180 (0xB4/$B4) [Byte] - TV WORKING COLOR BEING USED BY EX BASIC (Compatible with CoCo)
#ifndef _WCOLOR
#define _WCOLOR 180
#endif
#ifndef _wcolor
#define _wcolor (*(unsigned char*)_WCOLOR)
#endif

// Decimal 181 (0xB5/$B5) [Byte] - TV ALL PIXELS IN THIS BYTE SET TO COLOR OF VB3 (Compatible with CoCo)
#ifndef _ALLCOL
#define _ALLCOL 181
#endif
#ifndef _allcol
#define _allcol (*(unsigned char*)_ALLCOL)
#endif

// Decimal 182 (0xB6/$B6) [Byte] - PV PMODE'S MODE ARGUMENT (Compatible with CoCo)
#ifndef _PMODE
#define _PMODE 182
#endif
#ifndef _pmode
#define _pmode (*(unsigned char*)_PMODE)
#endif

// Decimal 183 (0xB7/$B7) [Word] - PV END OF CURRENT GRAPHIC PAGE (Compatible with CoCo)
#ifndef _ENDGRP
#define _ENDGRP 183
#endif
#ifndef _endgrp
#define _endgrp (*(unsigned*)_ENDGRP)
#endif

// Decimal 185 (0xB9/$B9) [Byte] - PV NUMBER OF BYTES/HORIZONTAL GRAPHIC LINE (Compatible with CoCo)
#ifndef _HORBYT
#define _HORBYT 185
#endif
#ifndef _horbyt
#define _horbyt (*(unsigned char*)_HORBYT)
#endif

// Decimal 186 (0xBA/$BA) [Word] - PV START OF CURRENT GRAPHIC PAGE (Compatible with CoCo)
#ifndef _BEGGRP
#define _BEGGRP 186
#endif
#ifndef _beggrp
#define _beggrp (*(unsigned*)_BEGGRP)
#endif

// Decimal 188 (0xBC/$BC) [Byte] - PV START OF GRAPHIC RAM (MS BYTE) (Compatible with CoCo)
#ifndef _GRPRAM
#define _GRPRAM 188
#endif
#ifndef _grpram
#define _grpram (*(unsigned char*)_GRPRAM)
#endif

// Decimal 189 (0xBD/$BD) [Word] - DV* *PV HORIZ COORD - START POINT (Compatible with CoCo)
#ifndef _HORBEG
#define _HORBEG 189
#endif
#ifndef _horbeg
#define _horbeg (*(unsigned*)_HORBEG)
#endif

// Decimal 191 (0xBF/$BF) [Word] - DV* *PV VERT COORD - START POINT (Compatible with CoCo)
#ifndef _VERBEG
#define _VERBEG 191
#endif
#ifndef _verbeg
#define _verbeg (*(unsigned*)_VERBEG)
#endif

// Decimal 193 (0xC1/$C1) [Byte] - PV SCREEN'S COLOR SET ARGUMENT (Compatible with CoCo)
#ifndef _CSSVAL
#define _CSSVAL 193
#endif
#ifndef _cssval
#define _cssval (*(unsigned char*)_CSSVAL)
#endif

// Decimal 194 (0xC2/$C2) [Byte] - PV PRESET/PSET FLAG: 0=PRESET, 1=PSET (Compatible with CoCo)
#ifndef _SETFLG
#define _SETFLG 194
#endif
#ifndef _setflg
#define _setflg (*(unsigned char*)_SETFLG)
#endif

// Decimal 195 (0xC3/$C3) [Word] - DV* *PV HORIZ COORD - ENDING POINT (Compatible with CoCo)
#ifndef _HOREND
#define _HOREND 195
#endif
#ifndef _horend
#define _horend (*(unsigned*)_HOREND)
#endif

// Decimal 197 (0xC5/$C5) [Word] - DV* *PV VERT COORD - ENDING POINT (Compatible with CoCo)
#ifndef _VEREND
#define _VEREND 197
#endif
#ifndef _verend
#define _verend (*(unsigned*)_VEREND)
#endif

// Decimal 199 (0xC7/$C7) [Word] - PV HORIZ COORD - DEFAULT COORD (Compatible with CoCo)
#ifndef _HORDEF
#define _HORDEF 199
#endif
#ifndef _hordef
#define _hordef (*(unsigned*)_HORDEF)
#endif

// Decimal 201 (0xC9/$C9) [Word] - PV VERT COORD - DEFAULT COORD (Compatible with CoCo)
#ifndef _VERDEF
#define _VERDEF 201
#endif
#ifndef _verdef
#define _verdef (*(unsigned*)_VERDEF)
#endif

// Decimal 274 (0x112/$112) [Constant] - (Compatible with CoCo)
#ifndef _TIMVAL
#define _TIMVAL 274
#endif

// Decimal 346 (0x15A/$15A) [Byte] - LEFT VERTICAL JOYSTICK DATA (Compatible with CoCo)
#ifndef _POTVAL
#define _POTVAL 346
#endif
#ifndef _potval
#define _potval (*(unsigned char*)_POTVAL)
#endif

// Decimal 732 (0x2DC/$2DC) [Constant] - +1 BASIC LINE INPUT BUFFER (Compatible with CoCo)
#ifndef _LINBUF
#define _LINBUF 732
#endif
#ifndef _linbuf
#define _linbuf ((unsigned char*)_LINBUF)
#endif

// Decimal 1024 (0x400/$400) [Array] - VIDEO DISPLAY AREA (Compatible with CoCo)
#ifndef _VIDRAM
#define _VIDRAM 1024
#endif
#ifndef _vidram
#define _vidram ((unsigned char*)_VIDRAM)
#endif


#endif
