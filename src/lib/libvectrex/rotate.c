
#include <vectrex.h>

// Rotate a list of points. The points array can be in ROM, but the out_points need to be in RAM.
// The list of points is given as follows:
// int8_t points[n] = {
//   y1, x1,
//   y2, x2,
//   ...
//   yn, xn
// };
void vectrex_rotate(int8_t angle, uint8_t nr_points, int8_t* points, int8_t* out_points)
{
    asm {
        PSHS    U,D
        LDA     angle
        LDB     nr_points
        DECB
        LDX     points
        LDU     out_points
        JSR     Rot_VL_ab
        PULS    U,D
    }
}

