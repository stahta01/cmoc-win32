
#include "_symbol.h"

symbol_t* symbols_pull(symbols_t* symbols)
{
    return (symbol_t*)slist_pull_head(&symbols->list);
}

