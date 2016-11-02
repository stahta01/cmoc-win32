
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <eat.h>
#include <parser.h>
#include <symbol.h>

char* src = "INT APPLE INT  PEAR APPLE=10";

symbols_t symbols;

int main(void)
{
    char tok[100];
    parser_t parser;

    for (parser_init(&parser, src); parser_next(&parser);) {
        if (parser_token_is(&parser, "INT")) {
            parser_next(&parser);
            puts(parser_token_get(&parser, tok));
            symbols_push(&symbols, symbol_create(tok, 0, 0, 0));
        }
    }

    return 0;
}

