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
    SEMICOLON, DOT, COMMA, LPAREN, RPAREN, LBRACE, RBRACE, LBRACKET, RBRACKET,

    // User-defined identifiers
    IDENTIFIER,

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
bool is_number(char *str);

#endif