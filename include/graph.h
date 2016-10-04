
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _GRAPH_H
#define _GRAPH_H

struct xycoord {                                // structure for pixel position
    int   xcoord;
    int   ycoord;
};

struct rccoord {                                // structure for text position
    int   row;
    int   col;
};

struct videoconfig {                            // structure for _getvideoconfig
    int   numxpixels;
    int   numypixels;
    int   numtextcols;
    int   numtextrows;
    int   numcolors;
    int   bitsperpixel;
    int   numvideopages;
    int   mode;
    int   adapter;
    int   monitor;
    int   memory;
};

struct textsettings {                           // structure for _gettextsettings
    int   basevectorx;
    int   basevectory;
    int   txpath;
    int   height;
    int   width;
    int   spacing;
    int   horizalign;
    int   vertalign;
};

struct _fontinfo {                              // structure for _getfontinfo
    byte   type;                                // 0=unpacked 1=packed
    word   base;
    byte*  data;
};


// Video Setup and Query Functions

void _setvideomode(int mode, int css);
struct videoconfig* _getvideoconfig(struct videoconfig*);
//int _setvideomoderows(int, int);
//int _grstatus(void);
int _setactivepage(int page);
int _getactivepage(void);
int _setvisualpage(int page);
int _getvisualpage(void);

/*
#define _MAXRESMODE     (-3)                    // graphics mode with highest res.
#define _MAXCOLORMODE   (-2)                    // graphics mode with most colours
#define _DEFAULTMODE    (-1)                    // restore screen to original mode
#define _TEXTBW40       0                       // 40 x 25 text, 16 grey
#define _TEXTC40        1                       // 40 x 25 text, 16/8 color
#define _TEXTBW80       2                       // 80 x 25 text, 16 grey
#define _TEXTC80        3                       // 80 x 25 text, 16/8 color
#define _MRES4COLOR     4                       // 320 x 200, 4 color
#define _MRESNOCOLOR    5                       // 320 x 200, 4 grey
#define _HRESBW         6                       // 640 x 200, BW
#define _TEXTMONO       7                       // 80 x 25 text, BW
#define _HERCMONO       11                      // 720 x 350, BW
#define _MRES16COLOR    13                      // 320 x 200, 16 color
#define _HRES16COLOR    14                      // 640 x 200, 16 color
#define _ERESNOCOLOR    15                      // 640 x 350, BW
#define _ERESCOLOR      16                      // 640 x 350, 4 or 16 color
#define _VRES2COLOR     17                      // 640 x 480, BW
#define _VRES16COLOR    18                      // 640 x 480, 16 color
#define _SVRES16COLOR   0x102                   // 800 x 600, 16 color
#define _XRES16COLOR    0x104                   // 1024 x 768, 16 color
#define _YRES16COLOR    0x106                   // 1280 x 1024, 16 color
#define _SVTEXTC80X60   0x108                   // 80 x 60 text
#define _SVTEXTC132X25  0x109                   // 132 x 25 text
#define _SVTEXTC132X43  0x10A                   // 132 x 43 text
#define _SVTEXTC132X50  0x10B                   // 132 x 50 text
#define _SVTEXTC132X60  0x10C                   // 132 x 60 text
*/

#define _NODISPLAY      (-1)                    // no display device
#define _UNKNOWN        0                       // unknown adapter/monitor type

// These will match the bits per pixel
#define _MONO           1                       // regular monochrome
#define _COLOR          2                       // regular color

#define _GROK                   0               // no error
#define _GRERROR                (-1)            // graphics error
#define _GRMODENOTSUPPORTED     (-2)            // video mode not supported
#define _GRNOTINPROPERMODE      (-3)            // function n/a in this mode
#define _GRINVALIDPARAMETER     (-4)            // invalid parameter(s)
#define _GRINSUFFICIENTMEMORY   (-5)            // out of memory
#define _GRFONTFILENOTFOUND     (-6)            // can't open font file
#define _GRINVALIDFONTFILE      (-7)            // font file has invalid format
#define _GRNOOUTPUT             1               // nothing was done
#define _GRCLIPPED              2               // output clipped

// Colour Setting and Query Functions

void _setcolor(int);
int _getcolor(void);
int _setbkcolor(int);
int _getbkcolor(void);
//void _remappalette(int, long);
//int _remapallpalette(long*);
int _selectpalette(int);

// Palette #0

#define P0_GREEN        0
#define P0_YELLOW       1
#define P0_BLUE         2
#define P0_RED          3

// Palette #1

#define P1_BUFF         0
#define P1_CYAN         1
#define P1_MAGENTA      2
#define P1_ORANGE       3

// Palette #2

#define P2_BLACK        0
#define P2_BLUE         1
#define P2_ORANGE       2
#define P2_WHITE        3

/*
#define _RED            0x00002aL
#define _MAGENTA        0x2a002aL
#define _BROWN          0x00152aL
#define _WHITE          0x2a2a2aL
#define _GRAY           0x151515L
#define _LIGHTBLUE      0x3F1515L
#define _LIGHTGREEN     0x153f15L
#define _LIGHTCYAN      0x3f3f15L
#define _LIGHTRED       0x15153fL
#define _LIGHTMAGENTA   0x3f153fL
#define _YELLOW         0x153f3fL
#define _BRIGHTWHITE    0x3f3f3fL
#define _LIGHTYELLOW    _YELLOW
*/

// Shape and Curve Drawing Functions

void _moveto(int x, int y);
void _lineto(int x, int y);
void _line(int x1, int y1, int x2, int y2);
void _rectangle(int x1, int y1, int x2, int y2);
//void _arc(int, int, int, int, int, int, int, int); // WATCOM
void _arc(int x, int y, int w, int h, int s, int e); // CMOC

void _ellipse(int, int, int, int, int);
void _pie(int, int, int, int, int, int, int, int, int);
void _polygon(int, int, struct xycoord*);
//void _floodfill(int, int, int);
void _setpixel(int x, int y);
int _getpixel(int x, int y);
//void _getarcinfo(struct xycoord*, struct xycoord*, struct xycoord*);

// Position Determination Functions

//struct xycoord _getcurrentposition(void);
//struct _wxycoord _getcurrentposition_w(void);
//struct xycoord _getviewcoord(int, int);
//struct xycoord _getviewcoord_wxy(struct _wxycoord*);
//struct xycoord _getphyscoord(int, int);
//struct _wxycoord _getwindowcoord(int, int);
//struct xycoord _setvieworg(int, int);

#define _getlogcoord    _getviewcoord           // for compatibility
#define _setlogorg      _setvieworg

// Output Determination Functions

//void _setfillmask(byte*);
//byte* _getfillmask(byte*);
//void _setlinestyle(unsigned);
//unsigned _getlinestyle(void);
//int _setplotaction(int);
//int _getplotaction(void);

//#define _setwritemode   _setplotaction          // for compatibility
//#define _getwritemode   _getplotaction

enum {                                          // plotting action
    _GOR, _GAND, _GPRESET, _GPSET, _GXOR
};

// Screen Manipulation Functions

void _clearscreen(int);
void _setviewport(int, int, int, int);
void _setcliprgn(int, int, int, int);
void _getcliprgn(int*, int*, int*, int*);
//int _displaycursor(int);
//int _wrapon(int);

#define _GCLEARSCREEN   0
#define _GVIEWPORT      1
#define _GWINDOW        2

#define _GBORDER        2
#define _GFILLINTERIOR  3

enum {                                          // cursor display
    _GCURSOROFF, _GCURSORON
};

enum {                                          // text wrapping
    _GWRAPOFF, _GWRAPON
};

// Graphics Text Manipulation Functions and Constants

//struct textsettings* _gettextsettings(struct textsettings*);
//void _gettextextent(int, int, char*, struct xycoord*, struct xycoord*);
//void _setcharsize(int, int);
//void _settextalign(int, int);
//void _settextpath(int);
//void _settextorient(int, int);
//void _setcharspacing(int);
int _grtext(int, int, char*);

enum {                                          // horizontal alignment
    _NORMAL, _LEFT, _CENTER, _RIGHT
};

enum {                                          // vertical alignment
    _TOP=1, _CAP, _HALF, _BASE, _BOTTOM
};

enum {                                          // text path
    _PATH_RIGHT, _PATH_LEFT, _PATH_UP, _PATH_DOWN
};

// Text Manipulation Functions

#define _GSCROLLUP      1
#define _GSCROLLDOWN    (-1)
#define _MAXTEXTROWS    (-1)

//void _settextwindow(int, int, int, int);
void _outchar(int);                             // CMOC
void _outtext(char*);
//int _settextcolor(int);
//int _gettextcolor(void);
void _settextposition(int row, int col);        // Note: x & y reversed (WATCOM style)
void _settextpositionx(int x);                  // CMOC
void _settextpositiony(int y);                  // CMOC
int _gettextpositionx(void);                    // CMOC
int _gettextpositiony(void);                    // CMOC

void _scrolltextwindow(int);
//void _gettextwindow(int*, int*, int*, int*);
//int _gettextcursor(void);
//int _settextcursor(int);
//void _outmem(unsigned char*, int);
//int _settextrows(int);

// Image Manipulation Functions

//void _getimage(int, int, int, int, char*);
//void _putimage(int, int, char*, int);
//long _imagesize(int, int, int, int);

// Font Manipulation Functions

//int _registerfonts(char*);
//void _unregisterfonts(void);
void _setcharset(int type, int base, byte* data); //CMOC

//int _setfont(char*);
struct _fontinfo* _getfontinfo(void);
void _outgtext(char*);
int _getgtextextent(char*);
//struct xycoord _setgtextvector(int, int);
//struct xycoord _getgtextvector(void);

// X/Y reversed to match _settextposition() which is defined by WATCOM
void _textscreensize(int* rows, int* cols);     // CMOC

#define _GMOVEUP      1
#define _GMOVEDOWN    2
#define _GMOVELEFT    3
#define _GMOVERIGHT   4

void _movetextposition(int direction);          // CMOC

#endif

