
#include <graph.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <equates.h>
#include <system.h>
#include <pixel.h>
#include <fix6.h>

typedef struct {
    int curx, cury;
    int clipx1, clipy1, clipx2, clipy2;
    int visualpage;
} _graph_t;

extern _graph_t _graph;
extern struct _fontinfo fontinfo;

void _setpixel1(int x, int y, byte c);
void _setpixel2(int x, int y, byte c);

byte _getpixel1(int x, int y);
byte _getpixel2(int x, int y);


