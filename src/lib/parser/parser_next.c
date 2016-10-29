
#include "_parser.h"

int parser_next(parser_t* parser)
{
    int result = PARSER_EOL;
    *parser->pos = parser->chr;
    parser->pos = eat_while_space(parser->pos);
    if (*(parser->tok = parser->pos)) {
        if (isdigit(*parser->pos)) {
            if (parser->pos[0] == '0' && parser->pos[1] == 'X') {
                result = PARSER_HEX;
                parser->pos = eat_while_xdigit(parser->pos += 2);
            } else {
                result = PARSER_DIGIT;
                parser->pos = eat_while_digit(parser->pos);
            }
        } else if (isident(*parser->pos)) {
            result = PARSER_IDENT;
            parser->pos = eat_ident(parser->pos);
        } else if (*parser->pos == '"') {
            result = PARSER_STRING;
            parser->pos = eat_quoted(parser->pos, '"');
        } else if (*parser->pos == '\'') {
            result = PARSER_STRING;
            parser->pos = eat_quoted(parser->pos, '\'');
        } else {
            result = PARSER_OPERATOR;
            parser->pos++;
        }
    }
    parser->chr = *parser->pos;
    *parser->pos = 0;
    return result;
}

