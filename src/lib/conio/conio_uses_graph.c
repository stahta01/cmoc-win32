
#include "_conio.h"

void conio_uses_graph(void)
{
    _conio.outchar = _outchar;
    _conio.scrolltextwindow = _scrolltextwindow;
    _conio.clearscreen = _clearscreen;
    _conio.settextposition = _settextposition;
    _conio.settextpositionx = _settextpositionx;
    _conio.settextpositiony = _settextpositiony;
    _conio.getfontinfo = _getfontinfo;
    _conio.movetextposition = _movetextposition;
}

