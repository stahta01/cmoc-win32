
#include "_parser.h"

size_t parser_token_len(parser_t* parser)
{
    return parser->pos - parser->tok;
}

