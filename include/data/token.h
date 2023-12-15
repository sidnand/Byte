#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Enumeration representing token types
enum TOKEN_TYPE {
    // Arithmetic operators
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO, POWER,

    // Data types
    INT, FLOAT,

    // Special characters
    SEMICOLON, LPAREN, RPAREN,

    // User-defined identifiers
    IDENTIFIER,

    // Keywords
    PRINT,

    // MISC
    WHITESPACE,
};

// Structure representing a token
struct TOKEN {
    enum TOKEN_TYPE type;
    char *value;
};

struct TOKEN create_token(const char *value, enum TOKEN_TYPE type);
enum TOKEN_TYPE get_token_type(char *token);
bool is_int(char *str);
bool is_float(char *str);
bool is_period(char str);
bool is_quote(char str);
enum TOKEN_TYPE get_keyword_type(char *str);

#endif