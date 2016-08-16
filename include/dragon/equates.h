#ifndef _DRAGON_EQUATES_H
#define _DRAGON_EQUATES_H

// BACKSPACE
#ifndef _BS
#define _BS 8
#endif

// ENTER KEY
#ifndef _CR
#define _CR 13
#endif

// ESCAPE CODE
#ifndef _ESC
#define _ESC 27
#endif

// LINE FEED
#ifndef _LF
#define _LF 10
#endif

// FORM FEED
#ifndef _FORMF
#define _FORMF 12
#endif

// SPACE (BLANK)
#ifndef _SPACE
#define _SPACE 32
#endif

// TEMPORARY POINTER
#ifndef _TEMPTR
#define _TEMPTR 15
#endif
#ifndef _temptr
#define _temptr (*(unsigned*)_TEMPTR)
#endif

// PV CURSOR LOCATION
#ifndef _CURPOS
#define _CURPOS 136
#endif
#ifndef _curpos
#define _curpos (*(unsigned*)_CURPOS)
#endif

// TV TONE VALUE FOR SOUND COMMAND
#ifndef _SNDTON
#define _SNDTON 140
#endif
#ifndef _sndton
#define _sndton (*(unsigned char*)_SNDTON)
#endif

// TV DURATION VALUE FOR SOUND COMMAND
#ifndef _SNDDUR
#define _SNDDUR 141
#endif
#ifndef _snddur
#define _snddur (*(unsigned*)_SNDDUR)
#endif

#ifndef _TIMVAL
#define _TIMVAL 274
#endif

// LEFT VERTICAL JOYSTICK DATA
#ifndef _POTVAL
#define _POTVAL 346
#endif
#ifndef _potval
#define _potval (*(unsigned char*)_POTVAL)
#endif

// VIDEO DISPLAY AREA
#ifndef _VIDRAM
#define _VIDRAM 1024
#endif
#ifndef _vidram
#define _vidram ((char*)_VIDRAM)
#endif


#endif
