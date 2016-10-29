
#include "_parser.h"

bool parser_token_is(parser_t* parser, char* str)
{
    return strcmp(parser->tok, str) == 0;
}

