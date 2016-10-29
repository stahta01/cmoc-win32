
#include "_symbol.h"

void symbol_free(symbol_t* symbol)
{
    free(symbol->name);
    free(symbol);
}

