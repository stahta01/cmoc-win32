
#include "_symbol.h"

symbol_t* symbol_create(char* name, int type, int value, void* data)
{
    symbol_t* result = new(symbol_t);
    if (result) {
        symbol_set_name(result, name);
        result->type = type;
        result->value = value;
        result->data = data;
    }
    return result;
}

