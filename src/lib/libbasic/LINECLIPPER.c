
#include <basic.h>

bool LINECLIPPER(void)
{
    zX = _basic.pclip.x1;
    zY = _basic.pclip.x2;
    if (zX1 < zX) {
        if (zX2 < zX) {
            return false;
        }
        zY1 += (zY2 - zY1) * (zX - zX1) / (zX2 - zX1);
        zX1 = zX;
    } else {
        if (zX1 > zY) {
            if (zX2 > zY) {
                return false;
            }
            zY1 += (zY2 - zY1) * (zY - zX1) / (zX2 - zX1);
            zX1 = zY;
        }
    }
    if (zX2 < zX) {
        if (zX1 < zX) {
            return false;
        }
        zY2 += (zY2 - zY1) * (zX - zX2)/(zX2 - zX1);
        zX2 = zX;
    } else {
        if (zX2 > zY) {
            if (zX1 > zY) {
                return false;
            }
            zY2 += (zY2 - zY1) * (zY - zX2) / (zX2 - zX1);
            zX2 = zY;
        }
    }
    zX = _basic.pclip.y1;
    zY = _basic.pclip.y2;
    if (zY1 < zX) {
        if (zY2 < zX) {
            return false;
        }
        zX1 += (zX2 - zX1) * (zX - zY1) / (zY2 - zY1);
        zY1 = zX;
    } else {
        if (zY1 > zY) {
            if (zY2 > zY) {
                return false;
            }
            zX1 += (zX2 - zX1) * (zY - zY1) / (zY2 - zY1);
            zY1 = zY;
        }
    }
    if (zY2 < zX) {
        if (zY1 < zX) {
            return false;
        }
        zX2 += (zX2 - zX1) * (zX - zY2) / (zY2 - zY1);
        zY2 = zX;
    } else {
        if (zY2 > zY) {
            if (zY1 > zY) {
                return false;
            }
            zX2 += (zX2 - zX1) * (zY - zY2) / (zY2 - zY1);
            zY2 = zY;
        }
    }
    return true;
}


