
#include <basic.h>
#include <fixpt.h>
#include <graph.h>

void MARC(int x, int y, int w, int h, int s, int e, byte c)
{
    w <<= 1;
    h <<= 1;
    _setcolor(c);
    _moveto(x + f2i(fxsin((char)s) * w), y + f2i(fxcos((char)s) * h));
    if (s < e) {
        for (; s < e; s += 8) {
            _lineto(x + f2i(fxsin((char)s) * w), y + f2i(fxcos((char)s) * h));
        }
    } else {
        for (; s > e; s -= 8) {
            _lineto(x + f2i(fxsin((char)s) * w), y + f2i(fxcos((char)s) * h));
        }
    }
    _lineto(x + f2i(fxsin((char)e) * w), y + f2i(fxcos((char)e) * h));
}

