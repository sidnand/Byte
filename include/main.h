#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> // system input/output
#include <stdbool.h> // boolean type
#include <string.h> // string manipulation
#include <libgen.h> // pattern matching
#include <stdlib.h> // memory allocation

// Enumeration representing token types
enum TOKEN_TYPE {
    KEYWORD,     // reserved words with special meaning. e.g., if, else, while, for, true, false
    IDENTIFIER,  // names given to variables, functions, etc.
    OPERATOR,    // symbols that operate on arguments and produce results. e.g., +, -, *, /, %
    SEPARATOR,   // symbols that separate statements. e.g., ;, {, }, (, ), [, ]
    LITERAL,     // a fixed value. e.g., integer, float, string
};

// Structure representing a token
struct TOKEN {
    enum TOKEN_TYPE type;
    char *value;
};

// Structure representing a user file
struct USER_FILE {
    char *path;
    char *name;
    char *ext;
    char *content;
};

// Function prototypes
const char *read_file(char *filepath);
const char *get_extension(const char *filename);
struct USER_FILE get_file(char *filepath);
struct TOKEN create_token(const char *value, enum TOKEN_TYPE type);
// struct TOKEN *tokenize(char *content);

#endif // MAIN_H
