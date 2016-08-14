#ifndef _EQUATES_H
#define _EQUATES_H

#ifndef _EXBAS
#define _EXBAS 32768
#endif

#ifndef _BASIC
#define _BASIC 40960
#endif

/* BACKSPACE */
#ifndef _BS
#define _BS 8
#endif

/* ENTER KEY */
#ifndef _CR
#define _CR 13
#endif

/* ESCAPE CODE */
#ifndef _ESC
#define _ESC 27
#endif

/* LINE FEED */
#ifndef _LF
#define _LF 10
#endif

/* FORM FEED */
#ifndef _FORMF
#define _FORMF 12
#endif

/* SPACE (BLANK) */
#ifndef _SPACE
#define _SPACE 32
#endif

/* STACK BUFFER ROOM */
#ifndef _STKBUF
#define _STKBUF 58
#endif

/* DEBOUNCE DELAY */
#ifndef _DEBDEL
#define _DEBDEL 1118
#endif

/* MAX NUMBER OF CHARS IN A BASIC LINE */
#ifndef _LBUFMX
#define _LBUFMX 250
#endif

/* MAXIMUM MS BYTE OF LINE NUMBER */
#ifndef _MAXLIN
#define _MAXLIN 250
#endif

/* RAM LOAD LOCATION FOR THE DOS COMMAND */
#ifndef _DOSBUF
#define _DOSBUF 9728
#endif

/* NUMBER OF BYTES IN DIRECTORY ENTRY */
#ifndef _DIRLEN
#define _DIRLEN 32
#endif

/* LENGTH OF SECTOR IN BYTES */
#ifndef _SECLEN
#define _SECLEN 256
#endif

/* MAXIMUM NUMBER OF SECTORS PER TRACK */
#ifndef _SECMAX
#define _SECMAX 18
#endif

/* LENGTH OF TRACK IN BYTES */
#ifndef _TRKLEN
#define _TRKLEN 4608
#endif

/* MAX NUMBER OF TRACKS */
#ifndef _TRKMAX
#define _TRKMAX 35
#endif

/* FILE ALLOCATION TABLE LENGTH */
#ifndef _FATLEN
#define _FATLEN 74
#endif

/* MAXIMUM NUMBER OF GRANULES */
#ifndef _GRANMX
#define _GRANMX 68
#endif

/* FILE CONTROL BLOCK LENGTH */
#ifndef _FCBLEN
#define _FCBLEN 281
#endif

/* INPUT FILE TYPE */
#ifndef _INPFIL
#define _INPFIL 16
#endif

/* OUTPUT FILE TYPE */
#ifndef _OUTFIL
#define _OUTFIL 32
#endif

/* RANDOM/DIRECT FILE TYPE */
#ifndef _RANFIL
#define _RANFIL 64
#endif

/* OP CODE OF BRN — SKIP ONE BYTE */
#ifndef _SKP1
#define _SKP1 33
#endif

/* OP CODE OF CMPX # - SKIP TWO BYTES */
#ifndef _SKP2
#define _SKP2 140
#endif

/* OP CODE OF LDA # - SKIP THE NEXT BYTE */
#ifndef _SKP1LD
#define _SKP1LD 134
#endif

/* STOP/END FLAG: POSITIVE=STOP, NEG=END */
#ifndef _ENDFLG
#define _ENDFLG 0
#endif
#ifndef _endflg
#define _endflg *((unsigned char*)_ENDFLG)
#endif

/* TERMINATOR FLAG 1 */
#ifndef _CHARAC
#define _CHARAC 1
#endif
#ifndef _charac
#define _charac *((unsigned char*)_CHARAC)
#endif

/* TERMINATOR FLAG 2 */
#ifndef _ENDCHR
#define _ENDCHR 2
#endif
#ifndef _endchr
#define _endchr *((unsigned char*)_ENDCHR)
#endif

/* SCRATCH VARIABLE */
#ifndef _TMPLOC
#define _TMPLOC 3
#endif
#ifndef _tmploc
#define _tmploc *((unsigned char*)_TMPLOC)
#endif

/* IF COUNTER - HOW MANY IF STATEMENTS IN A LINE */
#ifndef _IFCTR
#define _IFCTR 4
#endif
#ifndef _ifctr
#define _ifctr *((unsigned char*)_IFCTR)
#endif

/* DV* ARRAY FLAG 0=EVALUATE, 1=DIMENSIONING */
#ifndef _DIMFLG
#define _DIMFLG 5
#endif
#ifndef _dimflg
#define _dimflg *((unsigned char*)_DIMFLG)
#endif

/* DV* *PV TYPE FLAG: 0=NUMERIC, $FF=STRING */
#ifndef _VALTYP
#define _VALTYP 6
#endif
#ifndef _valtyp
#define _valtyp *((unsigned char*)_VALTYP)
#endif

/* TV STRING SPACE HOUSEKEEPING FLAG */
#ifndef _GARBFL
#define _GARBFL 7
#endif
#ifndef _garbfl
#define _garbfl *((unsigned char*)_GARBFL)
#endif

/* DISABLE ARRAY SEARCH: 00=ALLOW SEARCH */
#ifndef _ARYDIS
#define _ARYDIS 8
#endif
#ifndef _arydis
#define _arydis *((unsigned char*)_ARYDIS)
#endif

/* TV INPUT FLAG: READ=0, INPUT<>0 */
#ifndef _INPFLG
#define _INPFLG 9
#endif
#ifndef _inpflg
#define _inpflg *((unsigned char*)_INPFLG)
#endif

/* TV RELATIONAL OPERATOR FLAG */
#ifndef _RELFLG
#define _RELFLG 10
#endif
#ifndef _relflg
#define _relflg *((unsigned char*)_RELFLG)
#endif

/* PV TEMPORARY STRING STACK POINTER */
#ifndef _TEMPPT
#define _TEMPPT 11
#endif
#ifndef _temppt
#define _temppt *((unsigned*)_TEMPPT)
#endif

/* PV ADDR OF LAST USED STRING STACK ADDRESS */
#ifndef _LASTPT
#define _LASTPT 13
#endif
#ifndef _lastpt
#define _lastpt *((unsigned*)_LASTPT)
#endif

/* TEMPORARY POINTER */
#ifndef _TEMPTR
#define _TEMPTR 15
#endif
#ifndef _temptr
#define _temptr *((unsigned*)_TEMPTR)
#endif

/* TEMPORARY DESCRIPTOR STORAGE (STACK SEARCH) */
#ifndef _TMPTR1
#define _TMPTR1 17
#endif
#ifndef _tmptr1
#define _tmptr1 *((unsigned*)_TMPTR1)
#endif

/* FLOATING POINT ACCUMULATOR #2 MANTISSA */
#ifndef _FPA2
#define _FPA2 19
#endif
#ifndef _fpa2
#define _fpa2 ((char*)_FPA2)
#endif

/* BOTTOM OF STACK AT LAST CHECK */
#ifndef _BOTSTK
#define _BOTSTK 23
#endif
#ifndef _botstk
#define _botstk *((unsigned*)_BOTSTK)
#endif

/* PV BEGINNING OF BASIC PROGRAM */
#ifndef _TXTTAB
#define _TXTTAB 25
#endif
#ifndef _txttab
#define _txttab *((unsigned*)_TXTTAB)
#endif

/* PV START OF VARIABLES */
#ifndef _VARTAB
#define _VARTAB 27
#endif
#ifndef _vartab
#define _vartab *((unsigned*)_VARTAB)
#endif

/* PV START OF ARRAYS */
#ifndef _ARYTAB
#define _ARYTAB 29
#endif
#ifndef _arytab
#define _arytab *((unsigned*)_ARYTAB)
#endif

/* PV END OF ARRAYS (+1) */
#ifndef _ARYEND
#define _ARYEND 31
#endif
#ifndef _aryend
#define _aryend *((unsigned*)_ARYEND)
#endif

/* PV START OF STRING STORAGE (TOP OF FREE RAM) */
#ifndef _FRETOP
#define _FRETOP 33
#endif
#ifndef _fretop
#define _fretop *((unsigned*)_FRETOP)
#endif

/* PV START OF STRING VARIABLES */
#ifndef _STRTAB
#define _STRTAB 35
#endif
#ifndef _strtab
#define _strtab *((unsigned*)_STRTAB)
#endif

/* UTILITY STRING POINTER */
#ifndef _FRESPC
#define _FRESPC 37
#endif
#ifndef _frespc
#define _frespc *((unsigned*)_FRESPC)
#endif

/* PV TOP OF STRING SPACE */
#ifndef _MEMSIZ
#define _MEMSIZ 39
#endif
#ifndef _memsiz
#define _memsiz *((unsigned*)_MEMSIZ)
#endif

/* SAVED LINE NUMBER DURING A "STOP" */
#ifndef _OLDTXT
#define _OLDTXT 41
#endif
#ifndef _oldtxt
#define _oldtxt *((unsigned*)_OLDTXT)
#endif

/* BINARY VALUE OF A CONVERTED LINE NUMBER */
#ifndef _BINVAL
#define _BINVAL 43
#endif
#ifndef _binval
#define _binval *((unsigned*)_BINVAL)
#endif

/* SAVED INPUT PTR DURING A "STOP" */
#ifndef _OLDPTR
#define _OLDPTR 45
#endif
#ifndef _oldptr
#define _oldptr *((unsigned*)_OLDPTR)
#endif

/* TEMPORARY INPUT POINTER STORAGE */
#ifndef _TINPTR
#define _TINPTR 47
#endif
#ifndef _tinptr
#define _tinptr *((unsigned*)_TINPTR)
#endif

/* PV 'DATA' STATEMENT LINE NUMBER POINTER */
#ifndef _DATTXT
#define _DATTXT 49
#endif
#ifndef _dattxt
#define _dattxt *((unsigned*)_DATTXT)
#endif

/* PV 'DATA' STATEMENT ADDRESS POINTER */
#ifndef _DATPTR
#define _DATPTR 51
#endif
#ifndef _datptr
#define _datptr *((unsigned*)_DATPTR)
#endif

/* DATA POINTER FOR 'INPUT' & 'READ' */
#ifndef _DATTMP
#define _DATTMP 53
#endif
#ifndef _dattmp
#define _dattmp *((unsigned*)_DATTMP)
#endif

/* TV TEMP STORAGE FOR A VARIABLE NAME */
#ifndef _VARNAM
#define _VARNAM 55
#endif
#ifndef _varnam
#define _varnam *((unsigned*)_VARNAM)
#endif

/* TV POINTER TO A VARIABLE DESCRIPTOR */
#ifndef _VARPTR
#define _VARPTR 57
#endif
#ifndef _varptr
#define _varptr *((unsigned*)_VARPTR)
#endif

/* TEMP POINTER TO A VARIABLE DESCRIPTOR */
#ifndef _VARDES
#define _VARDES 59
#endif
#ifndef _vardes
#define _vardes *((unsigned*)_VARDES)
#endif

/* POINTER TO RELATIONAL OPERATOR PROCESSING ROUTINE */
#ifndef _RELPTR
#define _RELPTR 61
#endif
#ifndef _relptr
#define _relptr *((unsigned*)_RELPTR)
#endif

/* TEMPORARY RELATIONAL OPERATOR FLAG BYTE */
#ifndef _TRELFL
#define _TRELFL 63
#endif
#ifndef _trelfl
#define _trelfl *((unsigned char*)_TRELFL)
#endif

#ifndef _V40
#define _V40 64
#endif
#ifndef _v40
#define _v40 *((unsigned char*)_V40)
#endif

#ifndef _V41
#define _V41 65
#endif
#ifndef _v41
#define _v41 *((unsigned char*)_V41)
#endif

#ifndef _V42
#define _V42 66
#endif
#ifndef _v42
#define _v42 *((unsigned char*)_V42)
#endif

#ifndef _V43
#define _V43 67
#endif
#ifndef _v43
#define _v43 *((unsigned char*)_V43)
#endif

#ifndef _V44
#define _V44 68
#endif
#ifndef _v44
#define _v44 *((unsigned char*)_V44)
#endif

#ifndef _V45
#define _V45 69
#endif
#ifndef _v45
#define _v45 *((unsigned char*)_V45)
#endif

#ifndef _V46
#define _V46 70
#endif
#ifndef _v46
#define _v46 *((unsigned char*)_V46)
#endif

#ifndef _V47
#define _V47 71
#endif
#ifndef _v47
#define _v47 *((unsigned char*)_V47)
#endif

#ifndef _V48
#define _V48 72
#endif
#ifndef _v48
#define _v48 *((unsigned*)_V48)
#endif

#ifndef _V4A
#define _V4A 74
#endif
#ifndef _v4a
#define _v4a *((unsigned char*)_V4A)
#endif

#ifndef _V4B
#define _V4B 75
#endif
#ifndef _v4b
#define _v4b *((unsigned*)_V4B)
#endif

#ifndef _V4D
#define _V4D 77
#endif
#ifndef _v4d
#define _v4d *((unsigned*)_V4D)
#endif

/* PV FLOATING POINT ACCUMULATOR #0 EXPONENT */
#ifndef _FP0EXP
#define _FP0EXP 79
#endif
#ifndef _fp0exp
#define _fp0exp *((unsigned char*)_FP0EXP)
#endif

/* PV FLOATING POINT ACCUMULATOR #0 MANTISSA */
#ifndef _FPA0
#define _FPA0 80
#endif
#ifndef _fpa0
#define _fpa0 ((char*)_FPA0)
#endif

/* PV FLOATING POINT ACCUMULATOR #0 SIGN */
#ifndef _FP0SGN
#define _FP0SGN 84
#endif
#ifndef _fp0sgn
#define _fp0sgn *((unsigned char*)_FP0SGN)
#endif

/* POLYNOMIAL COEFFICIENT COUNTER */
#ifndef _COEFCT
#define _COEFCT 85
#endif
#ifndef _coefct
#define _coefct *((unsigned char*)_COEFCT)
#endif

/* TEMPORARY STRING DESCRIPTOR */
#ifndef _STRDES
#define _STRDES 86
#endif
#ifndef _strdes
#define _strdes ((char*)_STRDES)
#endif

/* FLOATING POINT CARRY BYTE */
#ifndef _FPCARY
#define _FPCARY 91
#endif
#ifndef _fpcary
#define _fpcary *((unsigned char*)_FPCARY)
#endif

/* PV FLOATING POINT ACCUMULATOR #1 EXPONENT */
#ifndef _FP1EXP
#define _FP1EXP 92
#endif
#ifndef _fp1exp
#define _fp1exp *((unsigned char*)_FP1EXP)
#endif

/* PV FLOATING POINT ACCUMULATOR #1 MANTISSA */
#ifndef _FPA1
#define _FPA1 93
#endif
#ifndef _fpa1
#define _fpa1 ((char*)_FPA1)
#endif

/* PV FLOATING POINT ACCUMULATOR #1 SIGN */
#ifndef _FP1SGN
#define _FP1SGN 97
#endif
#ifndef _fp1sgn
#define _fp1sgn *((unsigned char*)_FP1SGN)
#endif

/* SIGN OF RESULT OF FLOATING POINT OPERATION */
#ifndef _RESSGN
#define _RESSGN 98
#endif
#ifndef _ressgn
#define _ressgn *((unsigned char*)_RESSGN)
#endif

/* FLOATING POINT SUB BYTE (FIFTH BYTE) */
#ifndef _FPSBYT
#define _FPSBYT 99
#endif
#ifndef _fpsbyt
#define _fpsbyt *((unsigned char*)_FPSBYT)
#endif

/* POLYNOMIAL COEFFICIENT POINTER */
#ifndef _COEFPT
#define _COEFPT 100
#endif
#ifndef _coefpt
#define _coefpt *((unsigned*)_COEFPT)
#endif

/* CURRENT LINE POINTER DURING LIST */
#ifndef _LSTTXT
#define _LSTTXT 102
#endif
#ifndef _lsttxt
#define _lsttxt *((unsigned*)_LSTTXT)
#endif

/* PV CURRENT LINE # OF BASIC PROGRAM, $FFFF = DIRECT */
#ifndef _CURLIN
#define _CURLIN 104
#endif
#ifndef _curlin
#define _curlin *((unsigned*)_CURLIN)
#endif

/* TV TAB FIELD WIDTH */
#ifndef _DEVCFW
#define _DEVCFW 106
#endif
#ifndef _devcfw
#define _devcfw *((unsigned char*)_DEVCFW)
#endif

/* TV TAB ZONE */
#ifndef _DEVLCF
#define _DEVLCF 107
#endif
#ifndef _devlcf
#define _devlcf *((unsigned char*)_DEVLCF)
#endif

/* TV PRINT POSITION */
#ifndef _DEVPOS
#define _DEVPOS 108
#endif
#ifndef _devpos
#define _devpos *((unsigned char*)_DEVPOS)
#endif

/* TV PRINT WIDTH */
#ifndef _DEVWID
#define _DEVWID 109
#endif
#ifndef _devwid
#define _devwid *((unsigned char*)_DEVWID)
#endif

/* TV PRINT DEVICE: 0=NOT CASSETTE, -1=CASSETTE */
#ifndef _PRTDEV
#define _PRTDEV 110
#endif
#ifndef _prtdev
#define _prtdev *((unsigned char*)_PRTDEV)
#endif

/* PV DEVICE NUMBER: -3=DLOAD, -2=PRINTER, */
#ifndef _DEVNUM
#define _DEVNUM 111
#endif
#ifndef _devnum
#define _devnum *((unsigned char*)_DEVNUM)
#endif

/* PV CONSOLE IN BUFFER FLAG: 00=NOT EMPTY, $FF=EMPTY */
#ifndef _CINBFL
#define _CINBFL 112
#endif
#ifndef _cinbfl
#define _cinbfl *((unsigned char*)_CINBFL)
#endif

/* PV WARM START FLAG: $55=WARM, OTHER=COLD */
#ifndef _RSTFLG
#define _RSTFLG 113
#endif
#ifndef _rstflg
#define _rstflg *((unsigned char*)_RSTFLG)
#endif

/* PV WARM START VECTOR - JUMP ADDRESS FOR WARM START */
#ifndef _RSTVEC
#define _RSTVEC 114
#endif
#ifndef _rstvec
#define _rstvec *((unsigned*)_RSTVEC)
#endif

/* PV TOP OF RAM */
#ifndef _TOPRAM
#define _TOPRAM 116
#endif
#ifndef _topram
#define _topram *((unsigned*)_TOPRAM)
#endif

/* PV FILE STATUS FLAG: 0=CLOSED, 1=INPUT, 2=OUTPUT */
#ifndef _FILSTA
#define _FILSTA 120
#endif
#ifndef _filsta
#define _filsta *((unsigned char*)_FILSTA)
#endif

/* PV CONSOLE IN BUFFER CHAR COUNTER */
#ifndef _CINCTR
#define _CINCTR 121
#endif
#ifndef _cinctr
#define _cinctr *((unsigned char*)_CINCTR)
#endif

/* PV CONSOLE IN BUFFER POINTER */
#ifndef _CINPTR
#define _CINPTR 122
#endif
#ifndef _cinptr
#define _cinptr *((unsigned*)_CINPTR)
#endif

/* TV CASS BLOCK TYPE: 0=HEADER, 1=DATA, $FF=EOF */
#ifndef _BLKTYP
#define _BLKTYP 124
#endif
#ifndef _blktyp
#define _blktyp *((unsigned char*)_BLKTYP)
#endif

/* TV CASSETTE BYTE COUNT */
#ifndef _BLKLEN
#define _BLKLEN 125
#endif
#ifndef _blklen
#define _blklen *((unsigned char*)_BLKLEN)
#endif

/* TV CASSETTE LOAD BUFFER POINTER */
#ifndef _CBUFAD
#define _CBUFAD 126
#endif
#ifndef _cbufad
#define _cbufad *((unsigned*)_CBUFAD)
#endif

/* TV CASSETTE CHECKSUM BYTE */
#ifndef _CCKSUM
#define _CCKSUM 128
#endif
#ifndef _ccksum
#define _ccksum *((unsigned char*)_CCKSUM)
#endif

/* TV ERROR FLAG/CHARACTER COUNT */
#ifndef _CSRERR
#define _CSRERR 129
#endif
#ifndef _csrerr
#define _csrerr *((unsigned char*)_CSRERR)
#endif

/* TV PULSE WIDTH COUNT */
#ifndef _CPULWD
#define _CPULWD 130
#endif
#ifndef _cpulwd
#define _cpulwd *((unsigned char*)_CPULWD)
#endif

/* TV BIT COUNTER */
#ifndef _CPERTM
#define _CPERTM 131
#endif
#ifndef _cpertm
#define _cpertm *((unsigned char*)_CPERTM)
#endif

/* TV BIT PHASE FLAG */
#ifndef _CBTPHA
#define _CBTPHA 132
#endif
#ifndef _cbtpha
#define _cbtpha *((unsigned char*)_CBTPHA)
#endif

/* TV LAST SINE TABLE ENTRY */
#ifndef _CLSTSN
#define _CLSTSN 133
#endif
#ifndef _clstsn
#define _clstsn *((unsigned char*)_CLSTSN)
#endif

/* TV GRAPHIC BLOCK VALUE FOR SET, RESET AND POINT */
#ifndef _GRBLOK
#define _GRBLOK 134
#endif
#ifndef _grblok
#define _grblok *((unsigned char*)_GRBLOK)
#endif

/* TV INKEY$ RAM IMAGE */
#ifndef _IKEYIM
#define _IKEYIM 135
#endif
#ifndef _ikeyim
#define _ikeyim *((unsigned char*)_IKEYIM)
#endif

/* PV CURSOR LOCATION */
#ifndef _CURPOS
#define _CURPOS 136
#endif
#ifndef _curpos
#define _curpos *((unsigned*)_CURPOS)
#endif

/* PV DUMMY - THESE TWO BYTES ARE ALWAYS ZERO */
#ifndef _ZERO
#define _ZERO 138
#endif
#ifndef _zero
#define _zero *((unsigned*)_ZERO)
#endif

/* TV TONE VALUE FOR SOUND COMMAND */
#ifndef _SNDTON
#define _SNDTON 140
#endif
#ifndef _sndton
#define _sndton *((unsigned char*)_SNDTON)
#endif

/* TV DURATION VALUE FOR SOUND COMMAND */
#ifndef _SNDDUR
#define _SNDDUR 141
#endif
#ifndef _snddur
#define _snddur *((unsigned*)_SNDDUR)
#endif

/* 18      *PV 1200/2400 HERTZ PARTITION */
#ifndef _CMPMID
#define _CMPMID 143
#endif
#ifndef _cmpmid
#define _cmpmid *((unsigned char*)_CMPMID)
#endif

/* 24      *PV UPPER LIMIT OF 1200 HERTZ PERIOD */
#ifndef _CMP0
#define _CMP0 144
#endif
#ifndef _cmp0
#define _cmp0 *((unsigned char*)_CMP0)
#endif

/* 10      *PV UPPER LIMIT OF 2400 HERTZ PERIOD */
#ifndef _CMP1
#define _CMP1 145
#endif
#ifndef _cmp1
#define _cmp1 *((unsigned char*)_CMP1)
#endif

/* 128     *PV NUMBER OF $55'S TO CASSETTE LEADER */
#ifndef _SYNCLN
#define _SYNCLN 146
#endif
#ifndef _syncln
#define _syncln *((unsigned*)_SYNCLN)
#endif

/* 11      *PV CURSOR BLINK DELAY */
#ifndef _BLKCNT
#define _BLKCNT 148
#endif
#ifndef _blkcnt
#define _blkcnt *((unsigned char*)_BLKCNT)
#endif

/* 88      *PV BAUD RATE CONSTANT (600) */
#ifndef _LPTBTD
#define _LPTBTD 149
#endif
#ifndef _lptbtd
#define _lptbtd *((unsigned*)_LPTBTD)
#endif

/* 1       *PV PRINTER CARRIAGE RETURN DELAY */
#ifndef _LPTLND
#define _LPTLND 151
#endif
#ifndef _lptlnd
#define _lptlnd *((unsigned*)_LPTLND)
#endif

/* 16      *PV TAB FIELD WIDTH */
#ifndef _LPTCFW
#define _LPTCFW 153
#endif
#ifndef _lptcfw
#define _lptcfw *((unsigned char*)_LPTCFW)
#endif

/* 112     *PV LAST TAB ZONE */
#ifndef _LPTLCF
#define _LPTLCF 154
#endif
#ifndef _lptlcf
#define _lptlcf *((unsigned char*)_LPTLCF)
#endif

/* 132     *PV PRINTER WIDTH */
#ifndef _LPTWID
#define _LPTWID 155
#endif
#ifndef _lptwid
#define _lptwid *((unsigned char*)_LPTWID)
#endif

/* 0       *PV LINE PRINTER POSITION */
#ifndef _LPTPOS
#define _LPTPOS 156
#endif
#ifndef _lptpos
#define _lptpos *((unsigned char*)_LPTPOS)
#endif

/* LB4AA   *PV JUMP ADDRESS FOR EXEC COMMAND */
#ifndef _EXECJP
#define _EXECJP 157
#endif
#ifndef _execjp
#define _execjp *((unsigned*)_EXECJP)
#endif

#ifndef _GETNCH
#define _GETNCH 159
#endif
#ifndef _getnch
#define _getnch ((char*)_GETNCH)
#endif

/* PV OP CODE OF LDA EXTENDED */
#ifndef _GETCCH
#define _GETCCH 165
#endif
#ifndef _getcch
#define _getcch *((unsigned char*)_GETCCH)
#endif

/* PV THESE 2 BYTES CONTAIN ADDRESS OF THE CURRENT */
#ifndef _CHARAD
#define _CHARAD 166
#endif
#ifndef _charad
#define _charad *((unsigned*)_CHARAD)
#endif

/* = LOW ORDER FOUR BYTES OF THE PRODUCT */
#ifndef _VAB
#define _VAB 171
#endif
#ifndef _vab
#define _vab *((unsigned char*)_VAB)
#endif

/* = OF A FLOATING POINT MULTIPLICATION */
#ifndef _VAC
#define _VAC 172
#endif
#ifndef _vac
#define _vac *((unsigned char*)_VAC)
#endif

/* = THESE BYTES ARE USE AS RANDOM DATA */
#ifndef _VAD
#define _VAD 173
#endif
#ifndef _vad
#define _vad *((unsigned char*)_VAD)
#endif

/* = BY THE RND STATEMENT */
#ifndef _VAE
#define _VAE 174
#endif
#ifndef _vae
#define _vae *((unsigned char*)_VAE)
#endif

/* PV TRACE FLAG 0=OFF ELSE=ON */
#ifndef _TRCFLG
#define _TRCFLG 175
#endif
#ifndef _trcflg
#define _trcflg *((unsigned char*)_TRCFLG)
#endif

/* PV ADDRESS OF THE START OF USR VECTORS */
#ifndef _USRADR
#define _USRADR 176
#endif
#ifndef _usradr
#define _usradr *((unsigned*)_USRADR)
#endif

/* PV FOREGROUND COLOR */
#ifndef _FORCOL
#define _FORCOL 178
#endif
#ifndef _forcol
#define _forcol *((unsigned char*)_FORCOL)
#endif

/* PV BACKGROUND COLOR */
#ifndef _BAKCOL
#define _BAKCOL 179
#endif
#ifndef _bakcol
#define _bakcol *((unsigned char*)_BAKCOL)
#endif

/* TV WORKING COLOR BEING USED BY EX BASIC */
#ifndef _WCOLOR
#define _WCOLOR 180
#endif
#ifndef _wcolor
#define _wcolor *((unsigned char*)_WCOLOR)
#endif

/* TV ALL PIXELS IN THIS BYTE SET TO COLOR OF VB3 */
#ifndef _ALLCOL
#define _ALLCOL 181
#endif
#ifndef _allcol
#define _allcol *((unsigned char*)_ALLCOL)
#endif

/* PV PMODE'S MODE ARGUMENT */
#ifndef _PMODE
#define _PMODE 182
#endif
#ifndef _pmode
#define _pmode *((unsigned char*)_PMODE)
#endif

/* PV END OF CURRENT GRAPHIC PAGE */
#ifndef _ENDGRP
#define _ENDGRP 183
#endif
#ifndef _endgrp
#define _endgrp *((unsigned*)_ENDGRP)
#endif

/* PV NUMBER OF BYTES/HORIZONTAL GRAPHIC LINE */
#ifndef _HORBYT
#define _HORBYT 185
#endif
#ifndef _horbyt
#define _horbyt *((unsigned char*)_HORBYT)
#endif

/* PV START OF CURRENT GRAPHIC PAGE */
#ifndef _BEGGRP
#define _BEGGRP 186
#endif
#ifndef _beggrp
#define _beggrp *((unsigned*)_BEGGRP)
#endif

/* PV START OF GRAPHIC RAM (MS BYTE) */
#ifndef _GRPRAM
#define _GRPRAM 188
#endif
#ifndef _grpram
#define _grpram *((unsigned char*)_GRPRAM)
#endif

/* DV* *PV HORIZ COORD - START POINT */
#ifndef _HORBEG
#define _HORBEG 189
#endif
#ifndef _horbeg
#define _horbeg *((unsigned*)_HORBEG)
#endif

/* DV* *PV VERT COORD - START POINT */
#ifndef _VERBEG
#define _VERBEG 191
#endif
#ifndef _verbeg
#define _verbeg *((unsigned*)_VERBEG)
#endif

/* PV SCREEN'S COLOR SET ARGUMENT */
#ifndef _CSSVAL
#define _CSSVAL 193
#endif
#ifndef _cssval
#define _cssval *((unsigned char*)_CSSVAL)
#endif

/* PV PRESET/PSET FLAG: 0=PRESET, 1=PSET */
#ifndef _SETFLG
#define _SETFLG 194
#endif
#ifndef _setflg
#define _setflg *((unsigned char*)_SETFLG)
#endif

/* DV* *PV HORIZ COORD - ENDING POINT */
#ifndef _HOREND
#define _HOREND 195
#endif
#ifndef _horend
#define _horend *((unsigned*)_HOREND)
#endif

/* DV* *PV VERT COORD - ENDING POINT */
#ifndef _VEREND
#define _VEREND 197
#endif
#ifndef _verend
#define _verend *((unsigned*)_VEREND)
#endif

/* PV HORIZ COORD - DEFAULT COORD */
#ifndef _HORDEF
#define _HORDEF 199
#endif
#ifndef _hordef
#define _hordef *((unsigned*)_HORDEF)
#endif

/* PV VERT COORD - DEFAULT COORD */
#ifndef _VERDEF
#define _VERDEF 201
#endif
#ifndef _verdef
#define _verdef *((unsigned*)_VERDEF)
#endif

#ifndef _VCB
#define _VCB 203
#endif
#ifndef _vcb
#define _vcb *((unsigned*)_VCB)
#endif

#ifndef _VCD
#define _VCD 205
#endif
#ifndef _vcd
#define _vcd *((unsigned*)_VCD)
#endif

#ifndef _VCF
#define _VCF 207
#endif
#ifndef _vcf
#define _vcf *((unsigned*)_VCF)
#endif

#ifndef _VD1
#define _VD1 209
#endif
#ifndef _vd1
#define _vd1 *((unsigned*)_VD1)
#endif

#ifndef _VD3
#define _VD3 211
#endif
#ifndef _vd3
#define _vd3 *((unsigned char*)_VD3)
#endif

#ifndef _VD4
#define _VD4 212
#endif
#ifndef _vd4
#define _vd4 *((unsigned char*)_VD4)
#endif

#ifndef _VD5
#define _VD5 213
#endif
#ifndef _vd5
#define _vd5 *((unsigned char*)_VD5)
#endif

#ifndef _VD6
#define _VD6 214
#endif
#ifndef _vd6
#define _vd6 *((unsigned char*)_VD6)
#endif

#ifndef _VD7
#define _VD7 215
#endif
#ifndef _vd7
#define _vd7 *((unsigned char*)_VD7)
#endif

#ifndef _VD8
#define _VD8 216
#endif
#ifndef _vd8
#define _vd8 *((unsigned char*)_VD8)
#endif

#ifndef _VD9
#define _VD9 217
#endif
#ifndef _vd9
#define _vd9 *((unsigned char*)_VD9)
#endif

#ifndef _VDA
#define _VDA 218
#endif
#ifndef _vda
#define _vda *((unsigned char*)_VDA)
#endif

/* TV FLAG TO INDICATE IF GRAPHIC DATA HAS BEEN CHANGED */
#ifndef _CHGFLG
#define _CHGFLG 219
#endif
#ifndef _chgflg
#define _chgflg *((unsigned char*)_CHGFLG)
#endif

/* TV STACK POINTER STORAGE DURING PAINT */
#ifndef _TMPSTK
#define _TMPSTK 220
#endif
#ifndef _tmpstk
#define _tmpstk *((unsigned*)_TMPSTK)
#endif

/* PV OCTAVE VALUE (PLAY) */
#ifndef _OCTAVE
#define _OCTAVE 222
#endif
#ifndef _octave
#define _octave *((unsigned char*)_OCTAVE)
#endif

/* DV* *PV VOLUME HIGH VALUE (PLAY) */
#ifndef _VOLHI
#define _VOLHI 223
#endif
#ifndef _volhi
#define _volhi *((unsigned char*)_VOLHI)
#endif

/* DV* *PV VOLUME LOW VALUE (PLAY) */
#ifndef _VOLLOW
#define _VOLLOW 224
#endif
#ifndef _vollow
#define _vollow *((unsigned char*)_VOLLOW)
#endif

/* PV NOTE LENGTH (PLAY) */
#ifndef _NOTELN
#define _NOTELN 225
#endif
#ifndef _noteln
#define _noteln *((unsigned char*)_NOTELN)
#endif

/* PV TEMPO VALUE (PLAY) */
#ifndef _TEMPO
#define _TEMPO 226
#endif
#ifndef _tempo
#define _tempo *((unsigned char*)_TEMPO)
#endif

/* TV TIMER FOR THE PLAY COMMAND */
#ifndef _PLYTMR
#define _PLYTMR 227
#endif
#ifndef _plytmr
#define _plytmr *((unsigned*)_PLYTMR)
#endif

/* TV DOTTED NOTE TIMER SCALE FACTOR */
#ifndef _DOTVAL
#define _DOTVAL 229
#endif
#ifndef _dotval
#define _dotval *((unsigned char*)_DOTVAL)
#endif

#ifndef _HRMODE
#define _HRMODE 230
#endif

/* DV* *PV DLOAD BAUD RATE CONSTANT $B0=300, $2C=1200 */
#ifndef _DLBAUD
#define _DLBAUD 230
#endif
#ifndef _dlbaud
#define _dlbaud *((unsigned char*)_DLBAUD)
#endif

#ifndef _HRWIDTH
#define _HRWIDTH 231
#endif

/* DV* *PV DLOAD TIMEOUT CONSTANT */
#ifndef _TIMOUT
#define _TIMOUT 231
#endif
#ifndef _timout
#define _timout *((unsigned char*)_TIMOUT)
#endif

/* DV* *PV ANGLE VALUE (DRAW) */
#ifndef _ANGLE
#define _ANGLE 232
#endif
#ifndef _angle
#define _angle *((unsigned char*)_ANGLE)
#endif

/* DV* *PV SCALE VALUE (DRAW) */
#ifndef _SCALE
#define _SCALE 233
#endif
#ifndef _scale
#define _scale *((unsigned char*)_SCALE)
#endif

/* PV DSKCON OPERATION CODE 0-3 */
#ifndef _DCOPC
#define _DCOPC 234
#endif
#ifndef _dcopc
#define _dcopc *((unsigned char*)_DCOPC)
#endif

/* PV DSKCON DRIVE NUMBER 0—3 */
#ifndef _DCDRV
#define _DCDRV 235
#endif
#ifndef _dcdrv
#define _dcdrv *((unsigned char*)_DCDRV)
#endif

/* PV DSKCON TRACK NUMBER 0—34 */
#ifndef _DCTRK
#define _DCTRK 236
#endif
#ifndef _dctrk
#define _dctrk *((unsigned char*)_DCTRK)
#endif

/* PV DSKCON SECTOR NUMBER 1-18 */
#ifndef _DSEC
#define _DSEC 237
#endif
#ifndef _dsec
#define _dsec *((unsigned char*)_DSEC)
#endif

/* PV DSKCON DATA POINTER */
#ifndef _DCBPT
#define _DCBPT 238
#endif
#ifndef _dcbpt
#define _dcbpt *((unsigned*)_DCBPT)
#endif

/* PV DSKCON STATUS BYTE */
#ifndef _DCSTA
#define _DCSTA 240
#endif
#ifndef _dcsta
#define _dcsta *((unsigned char*)_DCSTA)
#endif

/* TEMPORARY FCB POINTER */
#ifndef _FCBTMP
#define _FCBTMP 241
#endif
#ifndef _fcbtmp
#define _fcbtmp *((unsigned*)_FCBTMP)
#endif

/* $XXXX $XXXX $3B3B SWI3 VECTOR */
#ifndef _SW3VEC
#define _SW3VEC 256
#endif
#ifndef _sw3vec
#define _sw3vec ((char*)_SW3VEC)
#endif

/* $XXXX $XXXX $3B3B SWI2 VECTOR */
#ifndef _SW2VEC
#define _SW2VEC 259
#endif
#ifndef _sw2vec
#define _sw2vec ((char*)_SW2VEC)
#endif

/* $XXXX $XXXX $XXXX SWI VECTOR */
#ifndef _SWIVEC
#define _SWIVEC 262
#endif
#ifndef _swivec
#define _swivec ((char*)_SWIVEC)
#endif

/* $XXXX $XXXX $D7AE NMI VECTOR */
#ifndef _NMIVEC
#define _NMIVEC 265
#endif
#ifndef _nmivec
#define _nmivec ((char*)_NMIVEC)
#endif

/* $A9B3 $894C $D7BC IRQ VECTOR */
#ifndef _IRQVEC
#define _IRQVEC 268
#endif
#ifndef _irqvec
#define _irqvec ((char*)_IRQVEC)
#endif

/* $A0F6 $A0F6 $A0F6 FIRQ VECTOR */
#ifndef _FRQVEC
#define _FRQVEC 271
#endif
#ifndef _frqvec
#define _frqvec ((char*)_FRQVEC)
#endif

#ifndef _TIMVAL
#define _TIMVAL 274
#endif

/* JUMP ADDRESS FOR BASIC'S USR FUNCTION */
#ifndef _USRJMP
#define _USRJMP 274
#endif
#ifndef _usrjmp
#define _usrjmp ((char*)_USRJMP)
#endif

/* FLOATING POINT RANDOM NUMBER SEED EXPONENT */
#ifndef _RVSEED
#define _RVSEED 277
#endif
#ifndef _rvseed
#define _rvseed *((unsigned char*)_RVSEED)
#endif

/* UPPER CASE/LOWER CASE FLAG: $FF=UPPER, 0=LOWER */
#ifndef _CASFLG
#define _CASFLG 282
#endif
#ifndef _casflg
#define _casflg *((unsigned char*)_CASFLG)
#endif

/* KEYBOARD DEBOUNCE DELAY (SET TO $45E) */
#ifndef _DEBVAL
#define _DEBVAL 283
#endif
#ifndef _debval
#define _debval *((unsigned*)_DEBVAL)
#endif

/* JUMP ADDRESS FOR EXPONENTIATION */
#ifndef _EXPJMP
#define _EXPJMP 285
#endif
#ifndef _expjmp
#define _expjmp ((char*)_EXPJMP)
#endif

/* BASIC'S TABLE */
#ifndef _COMVEC
#define _COMVEC 288
#endif
#ifndef _comvec
#define _comvec ((char*)_COMVEC)
#endif

/* USR 0 VECTOR */
#ifndef _USR0
#define _USR0 318
#endif
#ifndef _usr0
#define _usr0 *((unsigned*)_USR0)
#endif

/* KEYBOARD MEMORY BUFFER */
#ifndef _KEYBUF
#define _KEYBUF 338
#endif
#ifndef _keybuf
#define _keybuf ((char*)_KEYBUF)
#endif

/* LEFT VERTICAL JOYSTICK DATA */
#ifndef _POTVAL
#define _POTVAL 346
#endif
#ifndef _potval
#define _potval *((unsigned char*)_POTVAL)
#endif

/* $A5F6       $C426 $C44B OPEN COMMAND */
#ifndef _RVEC0
#define _RVEC0 350
#endif
#ifndef _rvec0
#define _rvec0 ((char*)_RVEC0)
#endif

/* $A5B9       $C838 $C888 DEVICE NUMBER VALIDITY CHECK */
#ifndef _RVEC1
#define _RVEC1 353
#endif
#ifndef _rvec1
#define _rvec1 ((char*)_RVEC1)
#endif

/* $A35F       $C843 $C893 SET PRINT PARAMETERS */
#ifndef _RVEC2
#define _RVEC2 356
#endif
#ifndef _rvec2
#define _rvec2 ((char*)_RVEC2)
#endif

/* $A282 $8273 $CB4A $CC1C CONSOLE OUT */
#ifndef _RVEC3
#define _RVEC3 359
#endif
#ifndef _rvec3
#define _rvec3 ((char*)_RVEC3)
#endif

/* $A176 $8CF1 $C58F $C5BC CONSOLE IN */
#ifndef _RVEC4
#define _RVEC4 362
#endif
#ifndef _rvec4
#define _rvec4 ((char*)_RVEC4)
#endif

/* $A3ED       $C818 $C848 INPUT DEVICE NUMBER CHECK */
#ifndef _RVEC5
#define _RVEC5 365
#endif
#ifndef _rvec5
#define _rvec5 ((char*)_RVEC5)
#endif

/* $A406       $C81B $C84B PRINT DEVICE NUMBER CHECK */
#ifndef _RVEC6
#define _RVEC6 368
#endif
#ifndef _rvec6
#define _rvec6 ((char*)_RVEC6)
#endif

/* $A426       $CA3B $CAE9 CLOSE ALL FILES */
#ifndef _RVEC7
#define _RVEC7 371
#endif
#ifndef _rvec7
#define _rvec7 ((char*)_RVEC7)
#endif

/* $A42D $8286 $CA4B $CAF9 CLOSE ONE FILE */
#ifndef _RVEC8
#define _RVEC8 374
#endif
#ifndef _rvec8
#define _rvec8 ((char*)_RVEC8)
#endif

/* $B918 $8E90 $8E90 $8E90 PRINT */
#ifndef _RVEC9
#define _RVEC9 377
#endif
#ifndef _rvec9
#define _rvec9 ((char*)_RVEC9)
#endif

/* $B061       $CC5B $CD35 INPUT */
#ifndef _RVEC10
#define _RVEC10 380
#endif
#ifndef _rvec10
#define _rvec10 ((char*)_RVEC10)
#endif

/* $A549       $C859 $C8A9 BREAK CHECK */
#ifndef _RVEC11
#define _RVEC11 383
#endif
#ifndef _rvec11
#define _rvec11 ((char*)_RVEC11)
#endif

/* $A390       $C6B7 $C6E4 INPUTTING A BASIC LINE */
#ifndef _RVEC12
#define _RVEC12 386
#endif
#ifndef _rvec12
#define _rvec12 ((char*)_RVEC12)
#endif

/* $A4BF       $CA36 $CAE4 TERMINATING BASIC LINE INPUT */
#ifndef _RVEC13
#define _RVEC13 389
#endif
#ifndef _rvec13
#define _rvec13 ((char*)_RVEC13)
#endif

/* $A5CE       $CA60 $C90C EOF COMMAND */
#ifndef _RVEC14
#define _RVEC14 392
#endif
#ifndef _rvec14
#define _rvec14 ((char*)_RVEC14)
#endif

/* $B223 $8846 $CDF6 $CED2 EVALUATE AN EXPRESSION */
#ifndef _RVEC15
#define _RVEC15 395
#endif
#ifndef _rvec15
#define _rvec15 ((char*)_RVEC15)
#endif

/* $AC46       $C6B7 $C6E4 RESERVED FOR ON ERROR GOTO COMMAND */
#ifndef _RVEC16
#define _RVEC16 398
#endif
#ifndef _rvec16
#define _rvec16 ((char*)_RVEC16)
#endif

/* $AC49 $88F0 $C24D $C265 ERROR DRIVER */
#ifndef _RVEC17
#define _RVEC17 401
#endif
#ifndef _rvec17
#define _rvec17 ((char*)_RVEC17)
#endif

/* $AE75 $829C $C990 $CA3E RUN */
#ifndef _RVEC18
#define _RVEC18 404
#endif
#ifndef _rvec18
#define _rvec18 ((char*)_RVEC18)
#endif

/* $BD22 $87EF             ASCII TO FLOATING POINT CONVERSION */
#ifndef _RVEC19
#define _RVEC19 407
#endif
#ifndef _rvec19
#define _rvec19 ((char*)_RVEC19)
#endif

/* $AD9E $82B9       $C8B0 BASIC'S COMMAND INTERPRETATION LOOP */
#ifndef _RVEC20
#define _RVEC20 410
#endif
#ifndef _rvec20
#define _rvec20 ((char*)_RVEC20)
#endif

/* $A8C4                   RESET/SET/POINT COMMANDS */
#ifndef _RVEC21
#define _RVEC21 413
#endif
#ifndef _rvec21
#define _rvec21 ((char*)_RVEC21)
#endif

/* $A910                   CLS */
#ifndef _RVEC22
#define _RVEC22 416
#endif
#ifndef _rvec22
#define _rvec22 ((char*)_RVEC22)
#endif

/* $B821 $8304             CRUNCH BASIC LINE */
#ifndef _RVEC23
#define _RVEC23 419
#endif
#ifndef _rvec23
#define _rvec23 ((char*)_RVEC23)
#endif

/* $B7C2                   UNCRUNCH BASIC LINE */
#ifndef _RVEC24
#define _RVEC24 422
#endif
#ifndef _rvec24
#define _rvec24 ((char*)_RVEC24)
#endif

/* 5     STRING DESCRIPTOR STACK */
#ifndef _STRSTK
#define _STRSTK 425
#endif
#ifndef _strstk
#define _strstk ((char*)_STRSTK)
#endif

/* CASSETTE FILE NAME BUFFER */
#ifndef _CFNBUF
#define _CFNBUF 465
#endif
#ifndef _cfnbuf
#define _cfnbuf ((char*)_CFNBUF)
#endif

/* CASSETTE FILE DATA BUFFER */
#ifndef _CASBUF
#define _CASBUF 474
#endif
#ifndef _casbuf
#define _casbuf ((char*)_CASBUF)
#endif

/* LINE INPUT BUFFER HEADER */
#ifndef _LINHDR
#define _LINHDR 730
#endif
#ifndef _linhdr
#define _linhdr *((unsigned*)_LINHDR)
#endif

/* +1        BASIC LINE INPUT BUFFER */
#ifndef _LINBUF
#define _LINBUF 732
#endif
#ifndef _linbuf
#define _linbuf ((char*)_LINBUF)
#endif

/* STRING BUFFER */
#ifndef _STRBUF
#define _STRBUF 983
#endif
#ifndef _strbuf
#define _strbuf ((char*)_STRBUF)
#endif

/* VIDEO DISPLAY AREA */
#ifndef _VIDRAM
#define _VIDRAM 1024
#endif
#ifndef _vidram
#define _vidram ((char*)_VIDRAM)
#endif

/* I/O BUFFER #0 */
#ifndef _DBUF0
#define _DBUF0 1536
#endif
#ifndef _dbuf0
#define _dbuf0 ((char*)_DBUF0)
#endif

/* I/O BUFFER #1 */
#ifndef _DBUF1
#define _DBUF1 1792
#endif
#ifndef _dbuf1
#define _dbuf1 ((char*)_DBUF1)
#endif

/* FILE ALLOCATION TABLE - DRIVE 0 */
#ifndef _FATBL0
#define _FATBL0 2048
#endif
#ifndef _fatbl0
#define _fatbl0 ((char*)_FATBL0)
#endif

/* FILE ALLOCATION TABLE - DRIVE 1 */
#ifndef _FATBL1
#define _FATBL1 2122
#endif
#ifndef _fatbl1
#define _fatbl1 ((char*)_FATBL1)
#endif

/* FILE ALLOCATION TABLE - DRIVE 2 */
#ifndef _FATBL2
#define _FATBL2 2196
#endif
#ifndef _fatbl2
#define _fatbl2 ((char*)_FATBL2)
#endif

/* FILE ALLOCATION TABLE - DRIVE 3 */
#ifndef _FATBL3
#define _FATBL3 2270
#endif
#ifndef _fatbl3
#define _fatbl3 ((char*)_FATBL3)
#endif

/* 2    FILE BUFFER VECTORS (15 USER, 1 SYSTEM) */
#ifndef _FCBV1
#define _FCBV1 2344
#endif
#ifndef _fcbv1
#define _fcbv1 ((char*)_FCBV1)
#endif

/* START OF FREE RANDOM FILE BUFFER AREA */
#ifndef _RNBFAD
#define _RNBFAD 2376
#endif
#ifndef _rnbfad
#define _rnbfad *((unsigned*)_RNBFAD)
#endif

/* START OF FILE CONTROL BLOCKS */
#ifndef _FCBADR
#define _FCBADR 2378
#endif
#ifndef _fcbadr
#define _fcbadr *((unsigned*)_FCBADR)
#endif

/* DISK FILE NAME BUFFER */
#ifndef _DNAMBF
#define _DNAMBF 2380
#endif
#ifndef _dnambf
#define _dnambf ((char*)_DNAMBF)
#endif

/* DISK FILE EXTENSION NAME BUFFER */
#ifndef _DEXTBF
#define _DEXTBF 2388
#endif
#ifndef _dextbf
#define _dextbf ((char*)_DEXTBF)
#endif

/* DV* DISK FILE TYPE: 0=BASIC, 1=DATA, 2=MACHINE */
#ifndef _DFLTYP
#define _DFLTYP 2391
#endif
#ifndef _dfltyp
#define _dfltyp *((unsigned char*)_DFLTYP)
#endif

/* DV* ASCII FLAG: 0=CRUNCHED OR BINARY, $FF=ASCII */
#ifndef _DASCFL
#define _DASCFL 2392
#endif
#ifndef _dascfl
#define _dascfl *((unsigned char*)_DASCFL)
#endif

/* RUN FLAG: (IF BIT 1=1 THEN RUN, IF BIT 0=1, THEN CLOSE */
#ifndef _DRUNFL
#define _DRUNFL 2393
#endif
#ifndef _drunfl
#define _drunfl *((unsigned char*)_DRUNFL)
#endif

/* DEFAULT DRIVE NUMBER */
#ifndef _DEFDRV
#define _DEFDRV 2394
#endif
#ifndef _defdrv
#define _defdrv *((unsigned char*)_DEFDRV)
#endif

/* NUMBER OF FCBS ACTIVE */
#ifndef _FCBACT
#define _FCBACT 2395
#endif
#ifndef _fcbact
#define _fcbact *((unsigned char*)_FCBACT)
#endif

/* RESET FLAG: <>0 WILL CAUSE A 'NEW' & SHUT DOWN ALL FCBS */
#ifndef _DRESFL
#define _DRESFL 2396
#endif
#ifndef _dresfl
#define _dresfl *((unsigned char*)_DRESFL)
#endif

/* LOAD FLAG: CAUSE A 'NEW' FOLLOWING A LOAD ERROR */
#ifndef _DLODFL
#define _DLODFL 2397
#endif
#ifndef _dlodfl
#define _dlodfl *((unsigned char*)_DLODFL)
#endif

/* MERGE FLAG: 0=N0 MERGE, $FF=MERGE */
#ifndef _DMRGFL
#define _DMRGFL 2398
#endif
#ifndef _dmrgfl
#define _dmrgfl *((unsigned char*)_DMRGFL)
#endif

/* DISK BASIC USR COMMAND VECTORS */
#ifndef _DUSRVC
#define _DUSRVC 2399
#endif
#ifndef _dusrvc
#define _dusrvc ((char*)_DUSRVC)
#endif

/* SECTOR NUMBER */
#ifndef _V973
#define _V973 2419
#endif
#ifndef _v973
#define _v973 *((unsigned char*)_V973)
#endif

/* RAM DIRECTORY IMAGE ADDRESS */
#ifndef _V974
#define _V974 2420
#endif
#ifndef _v974
#define _v974 *((unsigned*)_V974)
#endif

/* FIRST GRANULE NUMBER */
#ifndef _V976
#define _V976 2422
#endif
#ifndef _v976
#define _v976 *((unsigned char*)_V976)
#endif

/* SECTOR NUMBER */
#ifndef _V977
#define _V977 2423
#endif
#ifndef _v977
#define _v977 *((unsigned char*)_V977)
#endif

/* RAM DIRECTORY IMAGE ADDRESS */
#ifndef _V978
#define _V978 2424
#endif
#ifndef _v978
#define _v978 *((unsigned*)_V978)
#endif

/* WRITE FAT VALUE: NUMBER OF FREE GRANULES WHICH MUST BE TAKEN */
#ifndef _WFATVL
#define _WFATVL 2426
#endif
#ifndef _wfatvl
#define _wfatvl *((unsigned*)_WFATVL)
#endif

/* DIRECT ACCESS FILE RECORD LENGTH */
#ifndef _DFFLEN
#define _DFFLEN 2428
#endif
#ifndef _dfflen
#define _dfflen *((unsigned*)_DFFLEN)
#endif

/* CURRENT TRACK NUMBER, DRIVES 0,1,2,3 */
#ifndef _DR0TRK
#define _DR0TRK 2430
#endif
#ifndef _dr0trk
#define _dr0trk ((char*)_DR0TRK)
#endif

/* NMI FLAG: 0=DON'T VECTOR <>0=YECTOR OUT */
#ifndef _NMIFLG
#define _NMIFLG 2434
#endif
#ifndef _nmiflg
#define _nmiflg *((unsigned char*)_NMIFLG)
#endif

/* NMI VECTOR: WHERE TO JUMP FOLLOWING AN NMI */
#ifndef _DNMIVC
#define _DNMIVC 2435
#endif
#ifndef _dnmivc
#define _dnmivc *((unsigned*)_DNMIVC)
#endif

/* MOTOR TURN OFF TIMER */
#ifndef _RDYTMR
#define _RDYTMR 2437
#endif
#ifndef _rdytmr
#define _rdytmr *((unsigned char*)_RDYTMR)
#endif

/* RAM IMAGE OF DSKREG ($FF40) */
#ifndef _DRGRAM
#define _DRGRAM 2438
#endif
#ifndef _drgram
#define _drgram *((unsigned char*)_DRGRAM)
#endif

/* VERIFY FLAG: 0=OFF, $FF=ON */
#ifndef _DVERFL
#define _DVERFL 2439
#endif
#ifndef _dverfl
#define _dverfl *((unsigned char*)_DVERFL)
#endif

/* READ/WRITE ATTEMPT COUNTER: NUMBER OF TIMES THE */
#ifndef _ATTCTR
#define _ATTCTR 2440
#endif
#ifndef _attctr
#define _attctr *((unsigned char*)_ATTCTR)
#endif

/* INITIALIZED TO SECLEN BY DISKBAS */
#ifndef _DFLBUF
#define _DFLBUF 2441
#endif
#ifndef _dflbuf
#define _dflbuf ((char*)_DFLBUF)
#endif

#ifndef _ROMPAK
#define _ROMPAK 49152
#endif

/* DISK BASIC ROM/ENHANCED BASIC INIT CODE */
#ifndef _DOSBAS
#define _DOSBAS 49152
#endif
#ifndef _dosbas
#define _dosbas ((char*)_DOSBAS)
#endif

/* PERIPHERAL INTERFACE ADAPTER ONE */
#ifndef _PIA0
#define _PIA0 65280
#endif
#ifndef _pia0
#define _pia0 ((char*)_PIA0)
#endif

#ifndef _DA
#define _DA 65312
#endif

/* PERIPHERAL INTERFACE ADAPTER TWO */
#ifndef _PIA1
#define _PIA1 65312
#endif
#ifndef _pia1
#define _pia1 ((char*)_PIA1)
#endif

#ifndef _PIA2
#define _PIA2 65344
#endif

/* DISK CONTROL REGISTER */
#ifndef _DSKREG
#define _DSKREG 65344
#endif
#ifndef _dskreg
#define _dskreg *((unsigned char*)_DSKREG)
#endif

/* STATUS/COMMAND REGISTER */
#ifndef _FDCREG
#define _FDCREG 65352
#endif
#ifndef _fdcreg
#define _fdcreg *((unsigned char*)_FDCREG)
#endif

/* INITIALIZATION REGISTER 0 */
#ifndef _INIT0
#define _INIT0 65424
#endif
#ifndef _init0
#define _init0 *((unsigned char*)_INIT0)
#endif

/* INITIALIZATION REGISTER 1 */
#ifndef _INIT1
#define _INIT1 65425
#endif
#ifndef _init1
#define _init1 *((unsigned char*)_INIT1)
#endif

/* IRQ INTERRUPT ENABLE REGISTER */
#ifndef _IRQENR
#define _IRQENR 65426
#endif
#ifndef _irqenr
#define _irqenr *((unsigned char*)_IRQENR)
#endif

/* FIRQ INTERRUPT ENABLE REGISTER */
#ifndef _FIRQENR
#define _FIRQENR 65427
#endif
#ifndef _firqenr
#define _firqenr *((unsigned char*)_FIRQENR)
#endif

/* TIMER REGISTER */
#ifndef _V_TIMER
#define _V_TIMER 65428
#endif
#ifndef _v_timer
#define _v_timer *((unsigned*)_V_TIMER)
#endif

/* VIDEO MODE REGISTER */
#ifndef _VIDEOMOD
#define _VIDEOMOD 65432
#endif
#ifndef _videomod
#define _videomod *((unsigned char*)_VIDEOMOD)
#endif

/* VIDEO MODE REGISTER */
#ifndef _VIDEORES
#define _VIDEORES 65433
#endif
#ifndef _videores
#define _videores *((unsigned char*)_VIDEORES)
#endif

/* BORDER REGISTER */
#ifndef _V_BORDER
#define _V_BORDER 65434
#endif
#ifndef _v_border
#define _v_border *((unsigned char*)_V_BORDER)
#endif

/* VERTICAL SCROLL REGISTER */
#ifndef _V_SCROLL
#define _V_SCROLL 65436
#endif
#ifndef _v_scroll
#define _v_scroll *((unsigned char*)_V_SCROLL)
#endif

/* VERTICAL OFFSET 1 REGISTER */
#ifndef _V_OFSET1
#define _V_OFSET1 65437
#endif
#ifndef _v_ofset1
#define _v_ofset1 *((unsigned char*)_V_OFSET1)
#endif

/* VERTICAL OFFSET 0 REGISTER */
#ifndef _V_OFSET0
#define _V_OFSET0 65438
#endif
#ifndef _v_ofset0
#define _v_ofset0 *((unsigned char*)_V_OFSET0)
#endif

/* HORIZONTAL OFFSET 0 REGISTER */
#ifndef _H_OFSET0
#define _H_OFSET0 65439
#endif
#ifndef _h_ofset0
#define _h_ofset0 *((unsigned char*)_H_OFSET0)
#endif

/* MEMORY MANAGEMENT UNIT REGISTERS (6 BITS) */
#ifndef _MMUREG
#define _MMUREG 65440
#endif
#ifndef _mmureg
#define _mmureg ((char*)_MMUREG)
#endif

/* COLOR PALETTE REGISTERS (6 BITS) */
#ifndef _PALETREG
#define _PALETREG 65456
#endif
#ifndef _paletreg
#define _paletreg ((char*)_PALETREG)
#endif

/* SAM CONTROL REGISTERS */
#ifndef _SAMREG
#define _SAMREG 65472
#endif

/* CLEAR COCO GRAPHICS MODE V0 */
#ifndef _V0CLR
#define _V0CLR 65472
#endif
#ifndef _v0clr
#define _v0clr *((unsigned char*)_V0CLR)
#endif

/* SET COCO GRAPHICS MODE V0 */
#ifndef _V0SET
#define _V0SET 65473
#endif
#ifndef _v0set
#define _v0set *((unsigned char*)_V0SET)
#endif

/* CLEAR COCO GRAPHICS MODE V1 */
#ifndef _V1CLR
#define _V1CLR 65474
#endif
#ifndef _v1clr
#define _v1clr *((unsigned char*)_V1CLR)
#endif

/* SET COCO GRAPHICS MODE V1 */
#ifndef _V1SET
#define _V1SET 65475
#endif
#ifndef _v1set
#define _v1set *((unsigned char*)_V1SET)
#endif

/* CLEAR COCO GRAPHICS MODE V2 */
#ifndef _V2CLR
#define _V2CLR 65476
#endif
#ifndef _v2clr
#define _v2clr *((unsigned char*)_V2CLR)
#endif

/* SET COCO GRAPHICS MODE V2 */
#ifndef _V2SET
#define _V2SET 65477
#endif
#ifndef _v2set
#define _v2set *((unsigned char*)_V2SET)
#endif

/* CLEAR COCO GRAPHICS OFFSET F0 */
#ifndef _F0CLR
#define _F0CLR 65478
#endif
#ifndef _f0clr
#define _f0clr *((unsigned char*)_F0CLR)
#endif

/* SET COCO GRAPHICS OFFSET F0 */
#ifndef _F0SET
#define _F0SET 65479
#endif
#ifndef _f0set
#define _f0set *((unsigned char*)_F0SET)
#endif

/* CLEAR COCO GRAPHICS OFFSET F1 */
#ifndef _F1CLR
#define _F1CLR 65480
#endif
#ifndef _f1clr
#define _f1clr *((unsigned char*)_F1CLR)
#endif

/* SET COCO GRAPHICS OFFSET F1 */
#ifndef _F1SET
#define _F1SET 65481
#endif
#ifndef _f1set
#define _f1set *((unsigned char*)_F1SET)
#endif

/* CLEAR COCO GRAPHICS OFFSET F2 */
#ifndef _F2CLR
#define _F2CLR 65482
#endif
#ifndef _f2clr
#define _f2clr *((unsigned char*)_F2CLR)
#endif

/* SET COCO GRAPHICS OFFSET F2 */
#ifndef _F2SET
#define _F2SET 65483
#endif
#ifndef _f2set
#define _f2set *((unsigned char*)_F2SET)
#endif

/* CLEAR COCO GRAPHICS OFFSET F3 */
#ifndef _F3CLR
#define _F3CLR 65484
#endif
#ifndef _f3clr
#define _f3clr *((unsigned char*)_F3CLR)
#endif

/* SET COCO GRAPHICS OFFSET F3 */
#ifndef _F3SET
#define _F3SET 65485
#endif
#ifndef _f3set
#define _f3set *((unsigned char*)_F3SET)
#endif

/* CLEAR COCO GRAPHICS OFFSET F4 */
#ifndef _F4CLR
#define _F4CLR 65486
#endif
#ifndef _f4clr
#define _f4clr *((unsigned char*)_F4CLR)
#endif

/* SET COCO GRAPHICS OFFSET F4 */
#ifndef _F4SET
#define _F4SET 65487
#endif
#ifndef _f4set
#define _f4set *((unsigned char*)_F4SET)
#endif

/* CLEAR COCO GRAPHICS OFFSET F5 */
#ifndef _F5CLR
#define _F5CLR 65488
#endif
#ifndef _f5clr
#define _f5clr *((unsigned char*)_F5CLR)
#endif

/* SET COCO GRAPHICS OFFSET F5 */
#ifndef _F5SET
#define _F5SET 65489
#endif
#ifndef _f5set
#define _f5set *((unsigned char*)_F5SET)
#endif

/* CLEAR COCO GRAPHICS OFFSET F6 */
#ifndef _F6CLR
#define _F6CLR 65490
#endif
#ifndef _f6clr
#define _f6clr *((unsigned char*)_F6CLR)
#endif

/* SET COCO GRAPHICS OFFSET F6 */
#ifndef _F6SET
#define _F6SET 65491
#endif
#ifndef _f6set
#define _f6set *((unsigned char*)_F6SET)
#endif

/* CLEAR CPU RATE, (0.89 MHz) */
#ifndef _R1CLR
#define _R1CLR 65496
#endif
#ifndef _r1clr
#define _r1clr *((unsigned char*)_R1CLR)
#endif

/* SET CPU RATE, (1.78 MHz) */
#ifndef _R1SET
#define _R1SET 65497
#endif
#ifndef _r1set
#define _r1set *((unsigned char*)_R1SET)
#endif

/* ROM DISABLED */
#ifndef _ROMCLR
#define _ROMCLR 65502
#endif
#ifndef _romclr
#define _romclr *((unsigned char*)_ROMCLR)
#endif

/* ROM ENABLED */
#ifndef _ROMSET
#define _ROMSET 65503
#endif
#ifndef _romset
#define _romset *((unsigned char*)_ROMSET)
#endif

#ifndef _SWI3
#define _SWI3 65522
#endif
#ifndef _swi3
#define _swi3 *((unsigned*)_SWI3)
#endif

#ifndef _SWI2
#define _SWI2 65524
#endif
#ifndef _swi2
#define _swi2 *((unsigned*)_SWI2)
#endif

#ifndef _FIRQ
#define _FIRQ 65526
#endif
#ifndef _firq
#define _firq *((unsigned*)_FIRQ)
#endif

#ifndef _IRQ
#define _IRQ 65528
#endif
#ifndef _irq
#define _irq *((unsigned*)_IRQ)
#endif

#ifndef _SWI
#define _SWI 65530
#endif
#ifndef _swi
#define _swi *((unsigned*)_SWI)
#endif

#ifndef _NMI
#define _NMI 65532
#endif
#ifndef _nmi
#define _nmi *((unsigned*)_NMI)
#endif

#ifndef _RESETV
#define _RESETV 65534
#endif
#ifndef _resetv
#define _resetv *((unsigned*)_RESETV)
#endif


#endif
