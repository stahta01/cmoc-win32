
#include "_basic.h"

#include <stdlib.h>
#include <motorola.h>
#include <math.h>

void MLINE(int x1, int y1, int x2, int y2, byte c)
{
    byte sx, *p;
    word sy;
    int x = x2 - x1, y = y2 - y1;
    if (_abs(x) > 120 || _abs(y) > 120) {
        x = (x1 + x2) >> 1;
        y = (y1 + y2) >> 1;
        MLINE(x1, y1, x, y, c);
        MLINE(x, y, x2, y2, c);
    } else {
        x = _basic.pclip.x1;
        y = _basic.pclip.x2;
        if (x1 < x) {
            if (x2 < x) {
                return;
            }
            y1 += (y2 - y1) * (x - x1) / (x2 - x1);
            x1 = x;
        } else {
            if (x1 > y) {
                if (x2 > y) {
                    return;
                }
                y1 += (y2 - y1) * (y - x1) / (x2 - x1);
                x1 = y;
            }
        }
        if (x2 < x) {
            if (x1 < x) {
                return;
            }
            y2 += (y2 - y1) * (x - x2)/(x2 - x1);
            x2 = x;
        } else {
            if (x2 > y) {
                if (x1 > y) {
                    return;
                }
                y2 += (y2 - y1) * (y - x2) / (x2 - x1);
                x2 = y;
            }
        }
        x = _basic.pclip.y1;
        y = _basic.pclip.y2;
        if (y1 < x) {
            if (y2 < x) {
                return;
            }
            x1 += (x2 - x1) * (x - y1) / (y2 - y1);
            y1 = x;
        } else {
            if (y1 > y) {
                if (y2 > y) {
                    return;
                }
                x1 += (x2 - x1) * (y - y1) / (y2 - y1);
                y1 = y;
            }
        }
        if (y2 < x) {
            if (y1 < x) {
                return;
            }
            x2 += (x2 - x1) * (x - y2) / (y2 - y1);
            y2 = x;
        } else {
            if (y2 > y) {
                if (y1 > y) {
                    return;
                }
                x2 += (x2 - x1) * (y - y2) / (y2 - y1);
                y2 = y;
            }
        }
        if (_pmode < 4)  {
            x1 >>= 1;
            x2 >>= 1;
            if (_pmode < 2) {
                y1 >>= 1;
                y2 >>= 1;
            }
        }

        x2 -= x1;
        y2 -= y1;
        x = _abs(x2);
        y = _abs(y2);
        byte length = (byte)_max(x, y);
        if (length) {
            x1 = _i2f(x1);
            y1 = _i2f(y1);
            x2 = _i2f(x2) / length;
            y2 = _i2f(y2) / length;
            if (_pmode & 1) {
                for (; length--; x1 += x2, y1 += y2) {
                    sx = (byte)((word)x1 >> 8);
                    sy = ((word)y1 >> 8);
                    switch (_horbyt) {
                    case 16:
                        p = (byte*)_beggrp + (sy << 4) + (sx >> 2);
                        break;
                    case 32:
                        p = (byte*)_beggrp + (sy << 5) + (sx >> 2);
                        break;
                    default:
                        p = (byte*)_beggrp + (sy * _horbyt) + (sx >> 2);
                        break;
                    }
                    sx &= 3;
                    *p = *p & _pset2_clr[sx] | _pset2_set[c][sx];
                }
            } else {
                for (; length--; x1 += x2, y1 += y2) {
                    sx = (byte)((word)x1 >> 8);
                    sy = ((word)y1 >> 8);
                    switch (_horbyt) {
                    case 16:
                        if (c) {
                            *((byte*)_beggrp + (sy << 4) + (sx >> 3)) |= _pset1_set[sx & 7];
                        } else {
                            *((byte*)_beggrp + (sy << 4) + (sx >> 3)) &= _pset1_clr[sx & 7];
                        }
                        break;
                    case 32:
                        if (c) {
                            *((byte*)_beggrp + (sy << 5) + (sx >> 3)) |= _pset1_set[sx & 7];
                        } else {
                            *((byte*)_beggrp + (sy << 5) + (sx >> 3)) &= _pset1_clr[sx & 7];
                        }
                        break;
                    default:
                        if (c) {
                            *((byte*)_beggrp + (sy * _horbyt) + (sx >> 3)) |= _pset1_set[sx & 7];
                        } else {
                            *((byte*)_beggrp + (sy * _horbyt) + (sx >> 3)) &= _pset1_clr[sx & 7];
                        }
                        break;
                    }
                }
            }
        }
    }
}
