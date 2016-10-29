
#include "_symbol.h"

void symbols_push(symbols_t* symbols, symbol_t* symbol)
{
    symbol->next = symbols->head;
    symbols->head = symbol;
}

