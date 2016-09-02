
#include <graph.h>
#include <math.h>
#include <stdlib.h>
#include <motorola.h>
#include <equates.h>
#include <fixpt.h>

typedef struct {
    short curx, cury;
    short clipx1, clipy1, clipx2, clipy2;
} _graph_t;

extern _graph_t _graph;

extern unsigned char _pset1_set[8];
extern unsigned char _pset1_clr[8];
extern unsigned char _pset2_set[4][4];
extern unsigned char _pset2_clr[4];
extern unsigned char _chr_set[2][2];
extern unsigned char _chr_clr[2][2];

