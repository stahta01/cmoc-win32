
#include "_parser.h"

void parser_init(parser_t* parser, char* str)
{
    parser->chr = *(parser->tok = parser->pos = str);
}

