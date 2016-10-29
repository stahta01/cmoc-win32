
#include "_symbol.h"

void symbol_set_name(symbol_t* symbol, char* name)
{
    free(symbol->name);
    symbol->name = strdup(name);
}

