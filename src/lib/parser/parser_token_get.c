
#include "_parser.h"

char* parser_token_get(parser_t* parser, char* dst)
{
    size_t len = parser_token_len(parser);
    memcpy(dst, parser->tok, len);
    dst[len] = 0;
    return dst;
}

