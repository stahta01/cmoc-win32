
#ifndef _MOTOROLA_6847_H
#define _MOTOROLA_6847_H

#include <motorola/types.h>

#define VDG_BLACK       0
#define VDG_GREEN       1
#define VDG_YELLOW      2
#define VDG_BLUE        3
#define VDG_RED         4
#define VDG_BUFF        5
#define VDG_CYAN        6
#define VDG_MAGENTA     7
#define VDG_ORANGE      8

#define _VDG_SEMIG_4C0      _MAKEWORD(0,  0)
#define _VDG_SEMIG_4C1      _MAKEWORD(0,  1)

#define _VDG_SEMIG_6C0      _MAKEWORD(0,  2)
#define _VDG_SEMIG_6C1      _MAKEWORD(0,  3)

#define _VDG_SEMIG_12C0     _MAKEWORD(1,  0)
#define _VDG_SEMIG_12C1     _MAKEWORD(1,  1)

#define _VDG_SEMIG_8C0      _MAKEWORD(2,  0)
#define _VDG_SEMIG_8C1      _MAKEWORD(2,  1)

#define _VDG_SEMIG_24C0     _MAKEWORD(3,  0)
#define _VDG_SEMIG_24C1     _MAKEWORD(3,  1)

// Note working in xroar
#define _VDG_GRAPH_1C0      _MAKEWORD(1, 16)
#define _VDG_GRAPH_1C1      _MAKEWORD(1, 17)
#define _VDG_GRAPH_1R0      _MAKEWORD(1, 18)
#define _VDG_GRAPH_1R1      _MAKEWORD(1, 19)


#define _VDG_GRAPH_2C0      _MAKEWORD(2, 20)
#define _VDG_GRAPH_2C1      _MAKEWORD(2, 21)
#define _VDG_GRAPH_2R0      _MAKEWORD(3, 22)
#define _VDG_GRAPH_2R1      _MAKEWORD(3, 23)

#define _VDG_GRAPH_3C0      _MAKEWORD(4, 24)
#define _VDG_GRAPH_3C1      _MAKEWORD(4, 25)
#define _VDG_GRAPH_3R0      _MAKEWORD(5, 26)
#define _VDG_GRAPH_3R1      _MAKEWORD(5, 27)

#define _VDG_GRAPH_6C0      _MAKEWORD(6, 28)
#define _VDG_GRAPH_6C1      _MAKEWORD(6, 29)
#define _VDG_GRAPH_6R0      _MAKEWORD(6, 30)
#define _VDG_GRAPH_6R1      _MAKEWORD(6, 31)

#endif



