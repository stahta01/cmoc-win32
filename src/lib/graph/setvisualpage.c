
#include "_graph.h"

int _setvisualpage(int page)
{
    int result = _getvisualpage();
    page = _setactivepage(_graph.visualpage = page);
    system_screen(_cssval ? 1 : 0);
    _setactivepage(page);
    return result;
}

