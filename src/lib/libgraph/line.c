
#include "_graph.h"

void _line(int x1, int y1, int x2, int y2)
{
    byte sx, *p;
    word sy;
    int x = x2 - x1, y = y2 - y1;
    if (_abs(x) > 120 || _abs(y) > 120) {
        x = (x1 + x2) >> 1;
        y = (y1 + y2) >> 1;
        _line(x1, y1, x, y);
        _line(x, y, x2, y2);
    } else {
        x = _graph.clipx1;
        y = _graph.clipx2;
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
        x = _graph.clipy1;
        y = _graph.clipy2;
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
            x1 = (x1 << 8);
            y1 = (y1 << 8);
            x2 = (x2 << 8) / length;
            y2 = (y2 << 8) / length;
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
                    *p = *p & _pset2_clr[sx] | _pset2_set[_forcol][sx];
                }
            } else {
                for (; length--; x1 += x2, y1 += y2) {
                    sx = (byte)((word)x1 >> 8);
                    sy = ((word)y1 >> 8);
                    switch (_horbyt) {
                    case 16:
                        if (_forcol) {
                            *((byte*)_beggrp + (sy << 4) + (sx >> 3)) |= _pset1_set[sx & 7];
                        } else {
                            *((byte*)_beggrp + (sy << 4) + (sx >> 3)) &= _pset1_clr[sx & 7];
                        }
                        break;
                    case 32:
                        if (_forcol) {
                            *((byte*)_beggrp + (sy << 5) + (sx >> 3)) |= _pset1_set[sx & 7];
                        } else {
                            *((byte*)_beggrp + (sy << 5) + (sx >> 3)) &= _pset1_clr[sx & 7];
                        }
                        break;
                    default:
                        if (_forcol) {
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

