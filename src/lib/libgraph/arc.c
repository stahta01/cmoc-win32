
#include "_graph.h"

void _arc(int x, int y, int w, int h, int s, int e)
{
    w <<= 1;
    h <<= 1;
    _moveto(x + f2i(fixsin((char)s) * w), y + f2i(fixcos((char)s) * h));
    if (s < e) {
        for (; s < e; s += 8) {
            _lineto(x + f2i(fixsin((char)s) * w), y + f2i(fixcos((char)s) * h));
        }
    } else {
        for (; s > e; s -= 8) {
            _lineto(x + f2i(fixsin((char)s) * w), y + f2i(fixcos((char)s) * h));
        }
    }
    _lineto(x + f2i(fixsin((char)e) * w), y + f2i(fixcos((char)e) * h));
}
