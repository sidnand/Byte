#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "../../include/data/token.h"

// create a function that takes a string and returns a token
// @param value: the value of the token
// @param type: the type of the token
// @return: a token
struct TOKEN create_token(const char *value, enum TOKEN_TYPE type) {
    struct TOKEN token;
    token.value = strdup(value);

    token.type = type;

    return token;
}

// get the type of a token
// @param token: the token to check
// @return: the type of the token
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

// checks if a string is a number
// @param str: the string to check
// @return: true if the string is a number, false otherwise
bool is_number(char *str) {
    if (!isdigit(*str)) {
        return false;
    }

    return true;
}