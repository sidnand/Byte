#include "../include/token.h"

#include "./parser.c"

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

// create a function that takes an array of strings and returns an array of tokens
// @param arr: the array of strings
// @return: an array of tokens
struct TOKEN *tokenize(char **arr, int num_elements) {
    struct TOKEN *tokens = malloc((size_t) num_elements * sizeof(struct TOKEN));

    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_elements; i++) {
        char *token = arr[i];

        if (token == NULL) {
            break;
        }

        enum TOKEN_TYPE type;

        if (is_int(token)) {
            type = INT;
        } else if (is_float(token)) {
            type = FLOAT;
        } else {
            type = IDENTIFIER;
        }

        tokens[i] = create_token(&token[0], type);
    }

    return tokens;
}

// create a function that takes a string and returns an array of tokens
// @param content: the content of the file
// @param num_elements: the number of elements in the array
// @return: an array of tokens
char **split(char *content, int *num_elements) {
    char *split_by = " \t\n\r(){}[]";
    char **tokens = malloc((INITIAL_SIZE + 1) * sizeof(char *));  // +1 for null terminator

    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(content, split_by);

    int i = 0;
    while (token != NULL) {
        if (i == max_tokens - 1) {
            max_tokens *= 2; // time complexity: O(n)
            tokens = resize_array(tokens, i, max_tokens, sizeof(char *));
        }

        tokens[i++] = token;
        token = strtok(NULL, split_by);
    }

    *num_elements = i;
    return tokens;
}