
#include "_symbol.h"

void symbols_push(symbols_t* symbols, symbol_t* symbol)
{
    slist_push_head(&symbols->list, &symbol->node);
}

