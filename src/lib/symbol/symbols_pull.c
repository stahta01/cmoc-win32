
#include "_symbol.h"

symbol_t* symbols_pull(symbols_t* symbols)
{
    symbol_t* result = symbols->head;
    if (result) {
        symbols->head = result->next;
        result->next = nullptr;
    }
    return result;
}

