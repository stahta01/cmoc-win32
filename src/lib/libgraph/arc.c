
#include "_graph.h"

void _arc(int x, int y, int w, int h, int s, int e)
{
    _moveto(x + f2i6(sin6(s) * w), y + f2i6(cos6(s) * h));
    if (s < e) {
        for (; s < e; s += 8) {
            _lineto(x + f2i6(sin6(s) * w), y + f2i6(cos6(s) * h));
        }
    } else {
        for (; s > e; s -= 8) {
            _lineto(x + f2i6(sin6(s) * w), y + f2i6(cos6(s) * h));
        }
    }
    _lineto(x + f2i6(sin6(e) * w), y + f2i6(cos6(e) * h));
}
