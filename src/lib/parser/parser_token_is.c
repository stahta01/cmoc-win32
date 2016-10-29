
#include "_parser.h"

bool parser_token_is(parser_t* parser, char* str)
{
    return strmemcmp(str, parser->tok, parser_token_len(parser)) == 0;
}

