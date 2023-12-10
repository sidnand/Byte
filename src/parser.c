#include "../include/parser.h"

// checks if a string is a float
// @param str: the string to check
// @return: true if the string is a float, false otherwise
bool is_float(char *str) {
    int len = strlen(str);
    int dot_count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            dot_count++;
        }
    }

    return (dot_count == 1);
}

// checks if a string is an integer
// @param str: the string to check
// @return: true if the string is an integer, false otherwise
bool is_int(char *str) {
    int len = strlen(str);
    int start_index = 0;

    if (str[0] == '-' || str[0] == '+') {
        start_index = 1;
    }

    for (int i = start_index; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

enum TOKEN_TYPE get_token_type(char *token) {
    switch (*token) {
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
        case ';':
            return SEMICOLON;
        case ',':
            return COMMA;
        case '.':
            return DOT;
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            return WHITESPACE;
        default:
            if (is_int(token)) {
                return INT;
            } else if (is_float(token)) {
                return FLOAT;
            } else {
                return IDENTIFIER;
            }
    }
}