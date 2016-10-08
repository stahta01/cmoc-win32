
#include "_graph.h"

int _selectpalette(int css)
{
    int result = _cssval ? 1 : 0;
    system_screen(css ? 1 : 0);
    return result;
}

