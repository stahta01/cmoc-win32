
#include <graph.h>
#include <math.h>
#include <stdlib.h>
#include <motorola.h>
#include <equates.h>
#include <fixpt.h>

typedef struct {
    int curx, cury;
    int clipx1, clipy1, clipx2, clipy2;
    byte color;
} _graph_t;

extern _graph_t _graph;

extern byte _pset1_set[8];
extern byte _pset1_clr[8];
extern byte _pset2_set[4][4];
extern byte _pset2_clr[4];
extern byte _chr_set[2][2];
extern byte _chr_clr[2][2];

void _setpixel1(int x, int y, byte c);
void _setpixel2(int x, int y, byte c);

byte _getpixel1(int x, int y);
byte _getpixel2(int x, int y);


