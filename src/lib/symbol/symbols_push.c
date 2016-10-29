
#include "_symbol.h"

symbol_t* symbols_push(symbols_t* symbols, char* name, int type, int value, void* data)
{
    symbol_t* result = symbol_create(name, type, value, data);
    if (result) {
        result->next = symbols->head;
        symbols->head = result;
    }
    return result;
}

