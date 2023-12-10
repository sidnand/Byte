#include "../include/parser.h"

// checks if a string is a number
// @param str: the string to check
// @return: true if the string is a number, false otherwise
bool is_number(char *str) {
    if (!isdigit(*str)) {
        return false;
    }

    return true;
}

enum TOKEN_TYPE get_token_type(char *token) {
    switch (*token) {
        // operators
        case '+':
            return PLUS;
        case '-':
            return MINUS;
        case '*':
            return MULTIPLY;
        case '/':
            return DIVIDE;
        case '%':
            return MODULO;
        case '^':
            return POWER;

        case '(':
            return LPAREN;
        case ')':
            return RPAREN;

        case '{':
            return LBRACE;
        case '}':
            return RBRACE;

        case '[':
            return LBRACKET;
        case ']':
            return RBRACKET;

        // special characters
        case ';':
            return SEMICOLON;
        case ',':
            return COMMA;
        case '.':
            return DOT;

        // whitespace
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            return WHITESPACE;

        default:
            if (is_number(token)) {
                return INT;
            } else {
                return IDENTIFIER;
            }
    }
}