
#include "basicdefs.h"

TBASIC _basic;

byte _pset1_set[8] = {128, 64, 32, 16, 8, 4, 2, 1};
byte _pset1_clr[8] = {127, 191, 223, 239, 247, 251, 253, 254};

byte _chr_set[2][2] = {{128|8, 128|2}, {128|4, 128|1}};
byte _chr_clr[2][2] = {{240|7, 240|13}, {240|11, 240|14}};

