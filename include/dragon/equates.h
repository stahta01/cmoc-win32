#ifndef _DRAGON_EQUATES_H
#define _DRAGON_EQUATES_H

// BACKSPACE (Compatible with CoCo)
#ifndef _BS
#define _BS 8
#endif

// ENTER KEY (Compatible with CoCo)
#ifndef _CR
#define _CR 13
#endif

// ESCAPE CODE (Compatible with CoCo)
#ifndef _ESC
#define _ESC 27
#endif

// LINE FEED (Compatible with CoCo)
#ifndef _LF
#define _LF 10
#endif

// FORM FEED (Compatible with CoCo)
#ifndef _FORMF
#define _FORMF 12
#endif

// SPACE (BLANK) (Compatible with CoCo)
#ifndef _SPACE
#define _SPACE 32
#endif

// TEMPORARY POINTER (Compatible with CoCo)
#ifndef _TEMPTR
#define _TEMPTR 15
#endif
#ifndef _temptr
#define _temptr (*(unsigned*)_TEMPTR)
#endif

// PV CURSOR LOCATION (Compatible with CoCo)
#ifndef _CURPOS
#define _CURPOS 136
#endif
#ifndef _curpos
#define _curpos (*(unsigned*)_CURPOS)
#endif

// TV TONE VALUE FOR SOUND COMMAND (Compatible with CoCo)
#ifndef _SNDTON
#define _SNDTON 140
#endif
#ifndef _sndton
#define _sndton (*(unsigned char*)_SNDTON)
#endif

// TV DURATION VALUE FOR SOUND COMMAND (Compatible with CoCo)
#ifndef _SNDDUR
#define _SNDDUR 141
#endif
#ifndef _snddur
#define _snddur (*(unsigned*)_SNDDUR)
#endif

// PV TRACE FLAG 0=OFF ELSE=ON (Compatible with CoCo)
#ifndef _TRCFLG
#define _TRCFLG 175
#endif
#ifndef _trcflg
#define _trcflg (*(unsigned char*)_TRCFLG)
#endif

// PV ADDRESS OF THE START OF USR VECTORS (Compatible with CoCo)
#ifndef _USRADR
#define _USRADR 176
#endif
#ifndef _usradr
#define _usradr (*(unsigned*)_USRADR)
#endif

// PV FOREGROUND COLOR (Compatible with CoCo)
#ifndef _FORCOL
#define _FORCOL 178
#endif
#ifndef _forcol
#define _forcol (*(unsigned char*)_FORCOL)
#endif

// PV BACKGROUND COLOR (Compatible with CoCo)
#ifndef _BAKCOL
#define _BAKCOL 179
#endif
#ifndef _bakcol
#define _bakcol (*(unsigned char*)_BAKCOL)
#endif

// TV WORKING COLOR BEING USED BY EX BASIC (Compatible with CoCo)
#ifndef _WCOLOR
#define _WCOLOR 180
#endif
#ifndef _wcolor
#define _wcolor (*(unsigned char*)_WCOLOR)
#endif

// TV ALL PIXELS IN THIS BYTE SET TO COLOR OF VB3 (Compatible with CoCo)
#ifndef _ALLCOL
#define _ALLCOL 181
#endif
#ifndef _allcol
#define _allcol (*(unsigned char*)_ALLCOL)
#endif

// PV PMODE'S MODE ARGUMENT (Compatible with CoCo)
#ifndef _PMODE
#define _PMODE 182
#endif
#ifndef _pmode
#define _pmode (*(unsigned char*)_PMODE)
#endif

// PV END OF CURRENT GRAPHIC PAGE (Compatible with CoCo)
#ifndef _ENDGRP
#define _ENDGRP 183
#endif
#ifndef _endgrp
#define _endgrp (*(unsigned*)_ENDGRP)
#endif

// PV NUMBER OF BYTES/HORIZONTAL GRAPHIC LINE (Compatible with CoCo)
#ifndef _HORBYT
#define _HORBYT 185
#endif
#ifndef _horbyt
#define _horbyt (*(unsigned char*)_HORBYT)
#endif

// PV START OF CURRENT GRAPHIC PAGE (Compatible with CoCo)
#ifndef _BEGGRP
#define _BEGGRP 186
#endif
#ifndef _beggrp
#define _beggrp (*(unsigned*)_BEGGRP)
#endif

// PV START OF GRAPHIC RAM (MS BYTE) (Compatible with CoCo)
#ifndef _GRPRAM
#define _GRPRAM 188
#endif
#ifndef _grpram
#define _grpram (*(unsigned char*)_GRPRAM)
#endif

// DV* *PV HORIZ COORD - START POINT (Compatible with CoCo)
#ifndef _HORBEG
#define _HORBEG 189
#endif
#ifndef _horbeg
#define _horbeg (*(unsigned*)_HORBEG)
#endif

// DV* *PV VERT COORD - START POINT (Compatible with CoCo)
#ifndef _VERBEG
#define _VERBEG 191
#endif
#ifndef _verbeg
#define _verbeg (*(unsigned*)_VERBEG)
#endif

// PV SCREEN'S COLOR SET ARGUMENT (Compatible with CoCo)
#ifndef _CSSVAL
#define _CSSVAL 193
#endif
#ifndef _cssval
#define _cssval (*(unsigned char*)_CSSVAL)
#endif

// PV PRESET/PSET FLAG: 0=PRESET, 1=PSET (Compatible with CoCo)
#ifndef _SETFLG
#define _SETFLG 194
#endif
#ifndef _setflg
#define _setflg (*(unsigned char*)_SETFLG)
#endif

// DV* *PV HORIZ COORD - ENDING POINT (Compatible with CoCo)
#ifndef _HOREND
#define _HOREND 195
#endif
#ifndef _horend
#define _horend (*(unsigned*)_HOREND)
#endif

// DV* *PV VERT COORD - ENDING POINT (Compatible with CoCo)
#ifndef _VEREND
#define _VEREND 197
#endif
#ifndef _verend
#define _verend (*(unsigned*)_VEREND)
#endif

// PV HORIZ COORD - DEFAULT COORD (Compatible with CoCo)
#ifndef _HORDEF
#define _HORDEF 199
#endif
#ifndef _hordef
#define _hordef (*(unsigned*)_HORDEF)
#endif

// PV VERT COORD - DEFAULT COORD (Compatible with CoCo)
#ifndef _VERDEF
#define _VERDEF 201
#endif
#ifndef _verdef
#define _verdef (*(unsigned*)_VERDEF)
#endif

// (Compatible with CoCo)
#ifndef _TIMVAL
#define _TIMVAL 274
#endif

// LEFT VERTICAL JOYSTICK DATA (Compatible with CoCo)
#ifndef _POTVAL
#define _POTVAL 346
#endif
#ifndef _potval
#define _potval (*(unsigned char*)_POTVAL)
#endif

// VIDEO DISPLAY AREA (Compatible with CoCo)
#ifndef _VIDRAM
#define _VIDRAM 1024
#endif
#ifndef _vidram
#define _vidram ((char*)_VIDRAM)
#endif


#endif
