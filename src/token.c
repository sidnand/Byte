#include "../include/token.h"

struct TOKEN create_token(const char *value, enum TOKEN_TYPE type) {
    struct TOKEN token;
    token.value = strdup(value);
    token.type = type;
    return token;
}

struct TOKEN *tokenize(char **arr) {
    struct TOKEN *tokens = malloc(MAX_TOKENS);

    return tokens;
}

// create a function that takes a string and returns an array of tokens
// @param content: the content of the file
// @return: an array of tokens
char **split(char *content) {
    char *split_by = " \t\n\r(){}";
    char **tokens = malloc(MAX_TOKENS);

    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(content, split_by);

    int i = 0;
    while (token != NULL) {
        if (i % MAX_TOKENS == 0) {
            tokens = resize_array(tokens, i, i + MAX_TOKENS, sizeof(char *));
        }

        tokens[i++] = token;
        token = strtok(NULL, split_by);
    }

    return tokens;
}