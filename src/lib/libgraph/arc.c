
#include "_graph.h"

void _arc(int x, int y, int w, int h, int s, int e)
{
    _moveto(x + f2i6(sin6((char)s) * w), y + f2i6(cos6((char)s) * h));
    if (s < e) {
        for (; s < e; s += 8) {
            _lineto(x + f2i6(sin6((char)s) * w), y + f2i6(cos6((char)s) * h));
        }
    } else {
        for (; s > e; s -= 8) {
            _lineto(x + f2i6(sin6((char)s) * w), y + f2i6(cos6((char)s) * h));
        }
    }
    _lineto(x + f2i6(sin6((char)e) * w), y + f2i6(cos6((char)e) * h));
}
