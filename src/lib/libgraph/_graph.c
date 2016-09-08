
#include "_graph.h"

_graph_t _graph = {0, 0, 0, 0, 256, 192};
struct _fontinfo fontinfo;

unsigned char _pset1_set[8] = {128, 64, 32, 16, 8, 4, 2, 1};
unsigned char _pset1_clr[8] = {127, 191, 223, 239, 247, 251, 253, 254};

unsigned char _pset2_set[4][4] = {
    {0x00,0x00,0x00,0x00},
    {0x40,0x10,0x04,0x01},
    {0x80,0x20,0x08,0x02},
    {0xC0,0x30,0x0C,0x03}
};

unsigned char _pset2_clr[4] = {0x3F, 0xCF, 0xF3, 0xFC};
unsigned char _pset2_all[4] = {0x00, 0x55, 0xAA, 0xFF};


