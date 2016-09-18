
#ifndef _STDBOOL_H
#define _STDBOOL_H

// WinCMOC now auto defines bool/true/false
#ifndef bool
#define bool _Bool
typedef unsigned char _Bool;
#endif

#ifndef false
#define false 0
#endif

#ifndef true
#define true  1
#endif

#define __bool_true_false_are_defined 1

#endif

