
#include <graph.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <motorola.h>
#include <equates.h>
#include <fixpt.h>

typedef struct {
    int curx, cury;
    int clipx1, clipy1, clipx2, clipy2;
} _graph_t;

extern _graph_t _graph;
extern struct _fontinfo fontinfo;

extern unsigned char _pset1_set[8];
extern unsigned char _pset1_clr[8];
extern unsigned char _pset2_set[4][4];
extern unsigned char _pset2_clr[4];
extern unsigned char _pset2_all[4];

void _setpixel1(int x, int y, unsigned char c);
void _setpixel2(int x, int y, unsigned char c);

unsigned char _getpixel1(int x, int y);
unsigned char _getpixel2(int x, int y);


