
#ifndef _GRAPH_H
#define _GRAPH_H

struct xycoord {                        // structure for pixel position
    int   xcoord;
    int   ycoord;
};

struct rccoord {                        // structure for text position
    int   row;
    int   col;
};

struct videoconfig {                    // structure for _getvideoconfig
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

struct textsettings {                   // structure for _gettextsettings
    int   basevectorx;
    int   basevectory;
    int   txpath;
    int   height;
    int   width;
    int   spacing;
    int   horizalign;
    int   vertalign;
};

struct _fontinfo {                      // structure for _getfontinfo
    unsigned char   type;               // 0=unpacked 1=packed
    unsigned char   base;
    unsigned char*  data;
};


// Video Setup and Query Functions

int _setvideomode(int);
//int _setvideomoderows(int, int);
//struct videoconfig* _getvideoconfig(struct videoconfig*);
//int _grstatus(void);
int _setactivepage(int);
int _getactivepage(void);
int _setvisualpage(int);
int _getvisualpage(void);

#define _MAXRESMODE     (-3)            // graphics mode with highest res.
#define _MAXCOLORMODE   (-2)            // graphics mode with most colours
#define _DEFAULTMODE    (-1)            // restore screen to original mode
#define _TEXTBW40       0               // 40 x 25 text, 16 grey
#define _TEXTC40        1               // 40 x 25 text, 16/8 color
#define _TEXTBW80       2               // 80 x 25 text, 16 grey
#define _TEXTC80        3               // 80 x 25 text, 16/8 color
#define _MRES4COLOR     4               // 320 x 200, 4 color
#define _MRESNOCOLOR    5               // 320 x 200, 4 grey
#define _HRESBW         6               // 640 x 200, BW
#define _TEXTMONO       7               // 80 x 25 text, BW
#define _HERCMONO       11              // 720 x 350, BW
#define _MRES16COLOR    13              // 320 x 200, 16 color
#define _HRES16COLOR    14              // 640 x 200, 16 color
#define _ERESNOCOLOR    15              // 640 x 350, BW
#define _ERESCOLOR      16              // 640 x 350, 4 or 16 color
#define _VRES2COLOR     17              // 640 x 480, BW
#define _VRES16COLOR    18              // 640 x 480, 16 color
#define _MRES256COLOR   19              // 320 x 200, 256 color
#define _URES256COLOR   0x100           // 640 x 400, 256 color
#define _VRES256COLOR   0x101           // 640 x 480, 256 color
#define _SVRES16COLOR   0x102           // 800 x 600, 16 color
#define _SVRES256COLOR  0x103           // 800 x 600, 256 color
#define _XRES16COLOR    0x104           // 1024 x 768, 16 color
#define _XRES256COLOR   0x105           // 1024 x 768, 256 color
#define _YRES16COLOR    0x106           // 1280 x 1024, 16 color
#define _YRES256COLOR   0x107           // 1280 x 1024, 256 color
#define _SVTEXTC80X60   0x108           // 80 x 60 text
#define _SVTEXTC132X25  0x109           // 132 x 25 text
#define _SVTEXTC132X43  0x10A           // 132 x 43 text
#define _SVTEXTC132X50  0x10B           // 132 x 50 text
#define _SVTEXTC132X60  0x10C           // 132 x 60 text
#define _MRES32KCOLOR   0x10D           // 320 x 200, 32K color
#define _MRES64KCOLOR   0x10E           // 320 x 200, 64K color
#define _MRESTRUECOLOR  0x10F           // 320 x 200, TRUE color
#define _VRES32KCOLOR   0x110           // 640 x 480, 32K color
#define _VRES64KCOLOR   0x111           // 640 x 480, 64K color
#define _VRESTRUECOLOR  0x112           // 640 x 480, 16.8M color
#define _SVRES32KCOLOR  0x113           // 800 x 600, 32K color
#define _SVRES64KCOLOR  0x114           // 800 x 600, 64K color
#define _SVRESTRUECOLOR 0x115           // 800 x 600, 16.8M color
#define _XRES32KCOLOR   0x116           // 1024 x 768, 32K color
#define _XRES64KCOLOR   0x117           // 1024 x 768, 64K color
#define _XRESTRUECOLOR  0x118           // 1024 x 768, 16.8M color
#define _YRES32KCOLOR   0x119           // 1280 x 1024, 32K color
#define _YRES64KCOLOR   0x11A           // 1280 x 1024, 64K color
#define _YRESTRUECOLOR  0x11B           // 1280 x 1024, 16.8M color
#define _ZRES256COLOR   0x11C           // 1600 x 1200, 256 color
#define _ZRES32KCOLOR   0x11D           // 1600 x 1200, 32K color
#define _ZRES64KCOLOR   0x11E           // 1600 x 1200, 64K color
#define _ZRESTRUECOLOR  0x11F           // 1600 x 1200, 16.8M color

#define _NODISPLAY      (-1)            // no display device
#define _UNKNOWN        0               // unknown adapter/monitor type

#define _MDPA           1               // monochrome display/printer adapter
#define _CGA            2               // colour/graphics monitor adapter
#define _HERCULES       3               // Hercules monochrome adapter card
#define _MCGA           4               // PS/2 Model 30 monitor
#define _EGA            5               // enhanced graphics adapter
#define _VGA            6               // vector graphics array
#define _SVGA           7               // super VGA
#define _HGC            _HERCULES

#define _MONO           1               // regular monochrome
#define _COLOR          2               // regular color
#define _ENHANCED       3               // enhanced color
#define _ANALOGMONO     5               // analog monochrome
#define _ANALOGCOLOR    6               // analog color

#define _GROK                   0       // no error
#define _GRERROR                (-1)    // graphics error
#define _GRMODENOTSUPPORTED     (-2)    // video mode not supported
#define _GRNOTINPROPERMODE      (-3)    // function n/a in this mode
#define _GRINVALIDPARAMETER     (-4)    // invalid parameter(s)
#define _GRINSUFFICIENTMEMORY   (-5)    // out of memory
#define _GRFONTFILENOTFOUND     (-6)    // can't open font file
#define _GRINVALIDFONTFILE      (-7)    // font file has invalid format
#define _GRNOOUTPUT             1       // nothing was done
#define _GRCLIPPED              2       // output clipped

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

void _lineto(int, int);
void _rectangle(int, int, int, int, int);
//void _arc(int, int, int, int, int, int, int, int); // WATCOM Version
void _arc(int x, int y, int w, int h, int s, int e);

void _ellipse(int, int, int, int, int);
void _pie(int, int, int, int, int, int, int, int, int);
void _polygon(int, int, struct xycoord*);
//void _floodfill(int, int, int);
void _setpixel(int, int);
int _getpixel(int, int);
//void _getarcinfo(struct xycoord*, struct xycoord*, struct xycoord*);

// Position Determination Functions

//struct xycoord _getcurrentposition(void);
//struct _wxycoord _getcurrentposition_w(void);
//struct xycoord _getviewcoord(int, int);
//struct xycoord _getviewcoord_wxy(struct _wxycoord*);
//struct xycoord _getphyscoord(int, int);
//struct _wxycoord _getwindowcoord(int, int);
void _moveto(int, int);
//struct xycoord _setvieworg(int, int);

#define _getlogcoord    _getviewcoord   // for compatibility
#define _setlogorg      _setvieworg

// Output Determination Functions

void _setfillmask(unsigned char*);
unsigned char* _getfillmask(unsigned char*);
void _setlinestyle(unsigned int);
unsigned int _getlinestyle(void);
int _setplotaction(int);
int _getplotaction(void);

#define _setwritemode   _setplotaction  // for compatibility
#define _getwritemode   _getplotaction

enum {                                  // plotting action
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

enum {                                  // cursor display
    _GCURSOROFF, _GCURSORON
};

enum {                                  // text wrapping
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

enum {                                  // horizontal alignment
    _NORMAL, _LEFT, _CENTER, _RIGHT
};

enum {                                  // vertical alignment
    _TOP=1, _CAP, _HALF, _BASE, _BOTTOM
};

enum {                                  // text path
    _PATH_RIGHT, _PATH_LEFT, _PATH_UP, _PATH_DOWN
};

// Text Manipulation Functions

#define _GSCROLLUP      1
#define _GSCROLLDOWN    (-1)
#define _MAXTEXTROWS    (-1)

//void _settextwindow(int, int, int, int);
void _outchar(int);
void _outtext(char*);
//int _settextcolor(int);
//int _gettextcolor(void);
//struct rccoord _settextposition(int, int);
//struct rccoord _gettextposition(void);
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
void _setcharset(int type, int base, unsigned char* data);

//int _setfont(char*);
struct _fontinfo* _getfontinfo(void);
void _outgtext(char*);
int _getgtextextent(char*);
//struct xycoord _setgtextvector(int, int);
//struct xycoord _getgtextvector(void);

#endif

