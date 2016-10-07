
#ifndef _COCO_SUPER_H
#define _COCO_SUPER_H

// These locations are copies of _HRMODE & _HRWIDTH.
// Note: These values overlap CoCo2's _DLBAUD & _TIMOUT, which means they are only valid
// for CoCo3's. I guess the CoCo3 either moved or removed _DLBAUD/_TIMOUT, therefore
// _DLBAUD & _TIMOUT are not portable. I'll look into removing them from other headers.

#define _H_MODE     230                         //
#define _H_WIDTH    231                         // 1=WIDTH40, 2=WIDTH80

// Additional variables used by super extended basic

#define _H_CRSLOC   65024                       // WORD  CURRENT LOCATION OF CURSOR
#define _H_CURSX    65026                       // BYTE  X POSITION OF CURSOR
#define _H_CURSY    65027                       // BYTE  Y POSITION OF CURSOR
#define _H_COLUMN   65028                       // BYTE  COLUMNS ON HI-RES ALPHA SCREEN
#define _H_ROW      65029                       // BYTE  ROWS ON HI-RES ALPHA SCREEN
#define _H_DISPEN   65030                       // WORD  END OF HI-RES DISPLAY SCREEN
#define _H_CRSATT   65032                       // BYTE  CURRENT CURSOR'S ATTRIBUTES
#define _H_UNUSED   65033                       // BYTE  UNUSED
#define _H_FCOLOR   65034                       // BYTE  FOREGROUND COLOR
#define _H_BCOLOR   65035                       // BYTE  BACKGROUND COLOR
#define _H_ONBRK    65036                       // WORD  ON BRK GOTO LINE NUMBER
#define _H_ONERR    65038                       // WORD  ON ERR GOTO LINE NUMBER
#define _H_ERROR    65040                       // BYTE  ERROR NUMBER ENCOUNTERED OR $FF (NO ERROR)
#define _H_ONERRS   65041                       // WORD  ON ERR SOURCE LINE NUMBER
#define _H_ERLINE   65043                       // WORD  LINE NUMBER WHERE ERROR OCCURRED
#define _H_ONBRKS   65045                       // WORD  ON BRK SOURCE LINE NUMBER
#define _H_ERRBRK   65047                       // BYTE  STILL UNKNOWN, HAS TO DO WITH ERR, BRK
#define _H_PCOUNT   65048                       // BYTE  PRINT COUNT, CHARACTERS TO BE HPRINTED
#define _H_PBUF     65049                       // BYTS PRINT BUFFER, HPRINT CHARS. STORED HERE

#define _h_mode     (*(byte*)_H_MODE)
#define _h_width    (*(byte*)_H_WIDTH)

#define _h_crsloc   (*(word*)_H_CRSLOC)
#define _h_cursx    (*(byte*)_H_CURSX)
#define _h_cursy    (*(byte*)_H_CURSY)
#define _h_column   (*(byte*)_H_COLUMN)
#define _h_row      (*(byte*)_H_ROW)
#define _h_dispen   (*(word*)_H_DISPEN)
#define _h_crsatt   (*(byte*)_H_CRSATT)
#define _h_unused   (*(byte*)_H_UNUSED)
#define _h_fcolor   (*(byte*)_H_FCOLOR)
#define _h_bcolor   (*(byte*)_H_BCOLOR)
#define _h_onbrk    (*(word*)_H_ONBRK)
#define _h_onerr    (*(word*)_H_ONERR)
#define _h_error    (*(byte*)_H_ERROR)
#define _h_onerrs   (*(word*)_H_ONERRS)
#define _h_erline   (*(word*)_H_ERLINE)
#define _h_onbrks   (*(word*)_H_ONBRKS)
#define _h_errbrk   (*(byte*)_H_ERRBRK)
#define _h_pcount   (*(byte*)_H_PCOUNT)

#endif

