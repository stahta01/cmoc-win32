
#include <basic.h>

bool LINECLIPPER(void)
{
    X = _basic.pclip.x1;
    Y = _basic.pclip.x2;
    if (X1 < X) {
        if (X2 < X) {
            return false;
        }
        Y1 += (Y2-Y1)*(X-X1)/(X2-X1);
        X1 = X;
    } else {
        if (X1 > Y) {
            if (X2 > Y) {
                return false;
            }
            Y1 += (Y2-Y1)*(Y-X1)/(X2-X1);
            X1 = Y;
        }
    }
    if (X2 < X) {
        if (X1 < X) {
            return false;
        }
        Y2 += (Y2-Y1)*(X-X2)/(X2-X1);
        X2 = X;
    } else {
        if (X2 > Y) {
            if (X1 > Y) {
                return false;
            }
            Y2 += (Y2-Y1)*(Y-X2)/(X2-X1);
            X2 = Y;
        }
    }
    X = _basic.pclip.y1;
    Y = _basic.pclip.y2;
    if (Y1 < X) {
        if (Y2 < X) {
            return false;
        }
        X1 += (X2-X1)*(X-Y1)/(Y2-Y1);
        Y1 = X;
    } else {
        if (Y1 > Y) {
            if (Y2 > Y) {
                return false;
            }
            X1 += (X2-X1)*(Y-Y1)/(Y2-Y1);
            Y1 = Y;
        }
    }
    if (Y2 < X) {
        if (Y1 < X) {
            return false;
        }
        X2 += (X2-X1)*(X-Y2)/(Y2-Y1);
        Y2 = X;
    } else {
        if (Y2 > Y) {
            if (Y1 > Y) {
                return false;
            }
            X2 += (X2-X1)*(Y-Y2)/(Y2-Y1);
            Y2 = Y;
        }
    }
    return true;
}


